//
// Created by x1y2z on 27.04.2023.
//
#include "BaseModelInfo.h"
#include "gta-reversed/game_sa/TxdStore.h"
#include "vendor/patch/patch.h"

void CBaseModelInfo::SetTexDictionary(const char* txdName, const char *dbName) {
    m_nTxdIndex = CTxdStore::FindOrAddTxdSlot(txdName, dbName);
}

ModelInfoType CBaseModelInfo::GetModelType() {
    return CHook::CallFunction<ModelInfoType>(*(uintptr_t*)(vtable + 0x28), this);
}

int32 CBaseModelInfo::GetAnimFileIndex() {
    return CHook::CallFunction<int32>(*(uintptr_t*)(vtable + 0x78), this);
}

void CBaseModelInfo::DeleteRwObject() {
    CHook::CallFunction<void>(*(uintptr_t*)(vtable + 0x48), this);
}
