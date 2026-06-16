#pragma once
#include "samp/main.h"
#include <string.h>
#include <dlfcn.h>
#include <asm/unistd.h>
#include <unistd.h>
#include <ctype.h>
#include <link.h>
#include <sys/cachectl.h>
#include <sys/mman.h>

#ifdef __aarch64__
#define __64BIT
    #define DETHUMB(_a)
    #define RETHUMB(_a)
    #define THUMBMODE(_a) (false)
    #define cacheflush(c, n, zeroarg) __builtin___clear_cache((char*)(c), (char*)(n))
#else
    #error This lib is supposed to work on ARM only!
#endif

#define GET_LR(dwRetAddr) \
    do { \
        uintptr_t lr = reinterpret_cast<uintptr_t>(__builtin_return_address(0)); \
        dwRetAddr = lr - g_libGTASA; \
    } while (0)


#define SET_TO(__a1, __a2) *(void**)&(__a1) = (void*)(__a2)

#include "shadowhook.h"
#include "asm32.h"
#include "asm64.h"
#include "vendor/patch/Gloss.h"

class CHook {
public:
    static inline void* lib;

public:

    static uintptr_t FindLib(const char* libname)
    {
        void* handle = dlopen(libname, RTLD_LAZY);

        if (handle) {
            void* symbol = dlsym(handle, "JNI_OnLoad");
            if (symbol) {
                Dl_info info;
                if (dladdr(symbol, &info) != 0) {
                    return reinterpret_cast<uintptr_t>(info.dli_fbase);
                }
            }
            dlclose(handle);
        }
        return 0;
    }

    static void InitHookStuff() {
        lib = dlopen("libGame.so", RTLD_LAZY);
    }

    static void UnFuck(uintptr_t ptr, uint64_t len = PAGE_SIZE) {
        if(mprotect((void*)(ptr & 0xFFFFFFFFFFFFF000), len, PROT_READ | PROT_WRITE | PROT_EXEC) == 0)
            return;

        mprotect((void*)(ptr & 0xFFFFFFFFFFFFF000), len, PROT_READ | PROT_WRITE);
    }

    static uintptr_t GetAddrBaseXDL(uintptr_t addr)
    {
#ifdef __XDL
        xdl_info_t info;
        void* cache = NULL;
        if(!xdl_addr((void*)addr, &info, &cache)) return 0;
        xdl_addr_clean(&cache);
        return (uintptr_t)info.dli_saddr;
#endif
        return 0;
    }

    template<typename Addr>
    static void NOP(Addr adr, size_t count)
    {
        // fully check
        auto addr = (uintptr)(adr);
        if(count > 1)
            count /= 2;

        int bytesCount = 4 * count;
        uintptr_t endAddr = addr + bytesCount;
        UnFuck(addr, bytesCount);
        for (uintptr_t p = addr; p != endAddr; p += 4)
        {
            (*(char*)(p + 0)) = 0x1F;
            (*(char*)(p + 1)) = 0x20;
            (*(char*)(p + 2)) = 0x03;
            (*(char*)(p + 3)) = 0xD5;
        }
        cacheflush(addr, endAddr, 0);
    }

    static void RET(const char* sym)
    {
        // fully check
        auto addr = getSym(sym);

        RET(addr);
    }

    static void RET(uintptr addr)
    {
        // fully check
            WriteMemory(addr, (uintptr_t)"\xC0\x03\x5F\xD6", 4);
    }

    template <typename Src>
    static void WriteMemory(uintptr_t dest, Src src, uint64_t size)
    {
        UnFuck(dest, size);
        memcpy((void*)dest, (void*)src, size);

        cacheflush(dest, dest + size, 0);
    }

    static void ReadMemory(uintptr_t addr, void* dest, size_t size)
    {
        UnFuck(addr, size);
        memcpy(dest, (void*)addr, size);
    }

    template <typename Src>
    static void Write(uintptr_t dest, Src src, uint64_t size = 0)
    {   
	    if(size <= 0)
            size = sizeof(Src);
        
        CHook::WriteMemory(dest, &src, size);
    }

    static void Write32(uintptr_t dest, uint32_t v)
    {
        uint32_t vPtr = v;

        CHook::WriteMemory(dest, (uintptr_t)&vPtr, 4);
    }

    static uintptr_t getSym(const char* sym)
    {

        auto res = (uintptr_t)dlsym(lib, sym);
        if(res == 0) {
            FLog("[ERROR]: Failed to search for libraries: %s", sym);
            exit(0);
            return 0;
        }
        return res;
    }

    template<typename T, typename A>
    static void SetVTable(T* obj, A newVTable) {
        *reinterpret_cast<uintptr_t**>(obj) = (uintptr_t*)(newVTable);
    }

    template<typename Ret, typename T, typename... Args>
    static Ret CallVTableFunctionByNum(T* obj, int num, Args... args) {
        auto vtable = *reinterpret_cast<uintptr_t**>(obj);

        auto func = reinterpret_cast<Ret(*)(T*, Args...)>(vtable[num]);

        return func(obj, std::forward<Args>(args)...);
    }

    template <typename Ret, typename... Args>
    static inline Ret CallFunction(uintptr address, Args... args)
    {
        return (( Ret(*)(Args...))(address) )(args...);
    }

    template <typename Ret, typename... Args>
    static Ret CallFunction(const char* sym, Args... args) {
        static std::unordered_map<std::string, uintptr_t> addr_map;

        auto it = addr_map.find(sym);
        uintptr_t addr;

        if (it == addr_map.end()) {
            addr = (uintptr_t)dlsym(lib, sym);
            if (addr == 0) {
                FLog("[ERROR]: Function not found: %s", sym);
                exit(0);
            }
            addr_map[sym] = addr;
        } else {
            addr = it->second;
        }

        return ((Ret(*)(Args...))(addr))(args...);
    }

    template <typename Addr, typename Func, typename Orig>
    static void InstallPLT(Addr addr, Func hook_func, Orig* orig_func)
    {
        UnFuck(addr);

        *orig_func = reinterpret_cast<Orig>(*(uintptr_t*)addr);

        *(uintptr_t*)addr = reinterpret_cast<uintptr_t>(hook_func);
    }

    template <typename Addr, typename Func>
    static void InstallPLT(Addr addr, Func hook_func)
    {
        UnFuck(addr);
        *(uintptr_t*)addr = reinterpret_cast<uintptr_t>(hook_func);
    }

    template <typename Func, typename Orig>
    static void InlineHook(const char* sym, Func func, Orig orig)
    {
        shadowhook_hook_sym_name(
                "libGame.so",
                sym,
                (void *)func,
                (void **)orig);
    }

    template <typename Ptr, typename Func, typename Orig>
    static void InlineHook(Ptr ptr, Func func, Orig orig)
    {
        shadowhook_hook_func_addr(
                (void*)ptr,
                (void *)func,
                (void **)orig);
    }

    template <typename Func>
    static void Redirect(const char* sym, Func func)
    {
        auto addr = getSym(sym);

        Redirect(addr, func);
    }
    template <typename Ptr, typename Func>
    static void Redirect(Ptr ptr, Func func)
    {
        UnFuck(ptr, 16);
        uint64_t hook[2] = {0xD61F022058000051, reinterpret_cast<uintptr_t>(func)};
        WriteMemory(ptr, reinterpret_cast<uintptr_t>(hook), sizeof(hook));
    }
};
