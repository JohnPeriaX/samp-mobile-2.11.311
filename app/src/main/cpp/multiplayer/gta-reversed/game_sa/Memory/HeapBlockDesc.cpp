
#include <cstdio>
#include <cstring>
#include "HeapBlockDesc.h"
#include "HeapFreeBlockDesc.h"

HeapBlockDesc::HeapBlockDesc() {
    m_nSize      = 0;
    m_bInUse     = false;
    m_nMemId     = 0;
    m_pDebugInfo = nullptr;
    m_PrevBlock  = nullptr;
#ifdef MEMORY_MGR_USE_HEAP_FLAGS
    m_Flags.value = 0;
#endif
}

void HeapBlockDesc::InsertHeapBlock(HeapBlockDesc* desc) {
    // missing
}

HeapBlockDesc* HeapBlockDesc::_GetNextLocatedBlock() const {
    return (HeapBlockDesc*)((uint8*)this + sizeof(HeapBlockDesc) + m_nSize);
}

void* HeapBlockDesc::_GetBlockData() const {
    return (uint8*)this + sizeof(HeapBlockDesc);
}

void HeapBlockDesc::_DumpBlockInfo() const {
    auto const* self = reinterpret_cast<HeapFreeBlockDesc const*>(this);

    const char* info = "";
#ifdef MEMORY_MGR_USE_HEAP_FLAGS
    char szInfo[128] = { 0 };
    info = szInfo;

    if (self->m_Flags.AllocatedUsingNew) {
        if (self->m_Flags.IsArray)
            std::snprintf(szInfo, sizeof(szInfo), "%s", "operator new[]");
        else
            std::snprintf(szInfo, sizeof(szInfo), "%s", "operator new  ");
        info = szInfo;
    }

    if (!self->m_Flags.NoDebugHint) {
        if (szInfo[0])
            std::strncat(szInfo, " ", sizeof(szInfo) - std::strlen(szInfo) - 1);

        if (self->m_Flags.StringDebugInfo)
            std::snprintf(szInfo + std::strlen(szInfo), sizeof(szInfo) - std::strlen(szInfo), "[Hint: %s]", self->m_upDebugInfo);
        else
            std::snprintf(szInfo + std::strlen(szInfo), sizeof(szInfo) - std::strlen(szInfo), "[Hint: %p]", self->m_pDebugInfo);

        info = szInfo;
    }
#endif

    const char* type = m_bInUse ? "USED" : "FREE";
#ifdef MEMORY_MGR_USE_HEAP_FLAGS
    if (m_Flags.IsBoundBlock) {
        type = "BOUND";
    } else if (m_nMemId == -1) {
        type = "SYS";
    }
#endif

    char szMem[64] = { 0 };
    for (int32 i = 0; i < 16; ++i) { // todo: magic number (related to m_idStack size?)
        char byteInfo[4]{};
        std::snprintf(byteInfo, sizeof(byteInfo), "%02x", ((uint8*)self->_GetBlockData())[i]);
        std::strncat(szMem, byteInfo, sizeof(szMem) - std::strlen(szMem) - 1);
        if (i + 1 != 16) {
            std::strncat(szMem, " ", sizeof(szMem) - std::strlen(szMem) - 1);
        }
    }

    (void)type;
    (void)info;
    (void)szMem;
}
