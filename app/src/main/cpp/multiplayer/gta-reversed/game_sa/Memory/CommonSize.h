#pragma once

#include "HeapFreeBlockDesc.h"
#include "../common.h"

class CommonSize {
public:
    HeapFreeBlockDesc m_ListStart;
    HeapFreeBlockDesc m_ListEnd;

    int32             m_BlockSize;

    int32             m_NumFails;
    int32             m_NumFreeBlocks;

public:
    void Init(int32 blockSize);
    HeapFreeBlockDesc* Malloc();
    void Free(HeapFreeBlockDesc* desc);

    void _DumpInfo();
};

VALIDATE_SIZE(CommonSize, 0x60);
