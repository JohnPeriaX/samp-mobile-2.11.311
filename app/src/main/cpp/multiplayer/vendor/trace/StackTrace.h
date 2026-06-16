//
// Created by x1y2z on 20.03.2023.
//

#ifndef LIVERUSSIA_CSTACKTRACE_H
#define LIVERUSSIA_CSTACKTRACE_H

#include <stdio.h>
#include <dlfcn.h>
#include <dlfcn.h>
#include <unwind.h>
#include "samp/main.h"

#define PRINT_CRASH_STATES(context) \
    FLog("1: libGTASA.so + 0x%llx", context->uc_mcontext.pc - g_libGTASA); \
    FLog("2: libGTASA.so + 0x%llx", context->uc_mcontext.regs[30] - g_libGTASA); \
    FLog("1: libsamp.so + 0x%llx", context->uc_mcontext.pc - g_libSAMP); \
    FLog("2: libsamp.so + 0x%llx", context->uc_mcontext.regs[30] - g_libSAMP);

void FLog(const char* fmt, ...);
extern int g_iLastRenderedObject;
class CStackTrace
{
public:
    static void printBacktrace()
    {
        FLog("Last rendered object: %d", g_iLastRenderedObject);
        FLog("------------ START BACKTRACE ------------");
        FLog(" ");
        PrintStackTrace();
    }

private:
    static _Unwind_Reason_Code TraceFunction(_Unwind_Context* context, void* arg) {
        uintptr_t pc = _Unwind_GetIP(context);

        Dl_info info;
        if (dladdr(reinterpret_cast<void*>(pc), &info) && info.dli_sname != nullptr) {
            FLog("[adr: %p samp: %p gta: %p] %s\n",
                     reinterpret_cast<void*>(pc),
                     reinterpret_cast<void*>(pc - g_libSAMP),
                     reinterpret_cast<void*>(pc - g_libGTASA),
                     info.dli_sname);
        } else {
            FLog("[adr: %p samp: %p gta: %p] name not found\n",
                     reinterpret_cast<void*>(pc),
                     reinterpret_cast<void*>(pc - g_libSAMP),
                     reinterpret_cast<void*>(pc - g_libGTASA));
        }

        return _URC_NO_REASON;
    }

    static void PrintStackTrace() {
        _Unwind_Backtrace(TraceFunction, nullptr);
    }

};

#endif //LIVERUSSIA_CSTACKTRACE_H
