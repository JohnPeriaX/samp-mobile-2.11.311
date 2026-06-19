//
// Created by x1y2z on 07.03.2023.
//

#include "ModelInfo.h"
#include "vendor/patch/patch.h"
#include "vendor/log/log.h"

CVehicleModelInfo* CModelInfo::AddVehicleModel(int index)
{
    auto& pInfo = CModelInfo::ms_vehicleModelInfoStore.AddItem();

    ((void(*)(CVehicleModelInfo*))(g_libGTASA + 0x533338))(&pInfo); // CBaseModelInfo::CBaseModelInfo();

    pInfo.vtable = g_libGTASA + 0x822910;

    ((void(*)(CVehicleModelInfo*))(*(uintptr_t*)(pInfo.vtable +  0x1C*2)))(&pInfo);

    CModelInfo::SetModelInfo(index, &pInfo);
    return &pInfo;
}

CPedModelInfo* CModelInfo::AddPedModel(int index)
{

    auto& pInfo = CModelInfo::ms_pedModelInfoStore.AddItem();

    ((void(*)(CPedModelInfo*))(g_libGTASA +  0x5304DC))(&pInfo); // CBaseModelInfo::CBaseModelInfo();

    pInfo.vtable = g_libGTASA + 0x822858;

    ((void(*)(CPedModelInfo*))(*(uintptr_t*)(pInfo.vtable + 0x1C*2)))(&pInfo);

    CModelInfo::SetModelInfo(index, &pInfo);
    return &pInfo;
}

CDamageAtomicModelInfo* CModelInfo::AddDamageAtomicModel(int32 index)
{
    return CHook::CallFunction<CDamageAtomicModelInfo*>(g_libGTASA + 0x531B4C, index);
}

CAtomicModelInfo* CModelInfo::AddAtomicModel(int index)
{
    auto& pInfo = ms_atomicModelInfoStore.AddItem();

    ((void(*)(CAtomicModelInfo*))(g_libGTASA + 0x5304DC))(&pInfo);

    pInfo.vtable = g_libGTASA + 0x822390;

    ((void(*)(CAtomicModelInfo*))(*(uintptr_t*)(pInfo.vtable + 0x1C*2)))(&pInfo);

    CModelInfo::SetModelInfo(index, &pInfo);
    return &pInfo;
}

/* เพิ่มจาก sasamp-main: CModelInfo::AddClumpModel */
CClumpModelInfo* CModelInfo::AddClumpModel(int32 index)
{
    auto& pInfo = ms_clumpModelInfoStore.AddItem();

    ((void(*)(CClumpModelInfo*))(g_libGTASA + 0x5304DC))(&pInfo);

    pInfo.vtable = g_libGTASA + 0x822590;

    ((void(*)(CClumpModelInfo*))(*(uintptr_t*)(pInfo.vtable + 0x1C*2)))(&pInfo);

    CModelInfo::SetModelInfo(index, &pInfo);
    return &pInfo;
}

/* เพิ่มจาก sasamp-main: CModelInfo::AddWeaponModel */
CWeaponModelInfo* CModelInfo::AddWeaponModel(int32 index)
{
    auto& pInfo = ms_weaponModelInfoStore.AddItem();

    ((void(*)(CWeaponModelInfo*))(g_libGTASA + 0x5304DC))(&pInfo);

    pInfo.vtable = g_libGTASA + 0x8229C8;

    ((void(*)(CWeaponModelInfo*))(*(uintptr_t*)(pInfo.vtable + 0x1C*2)))(&pInfo);

    CModelInfo::SetModelInfo(index, &pInfo);
    return &pInfo;
}

/* เพิ่มจาก sasamp-main: CModelInfo name lookup helpers */
CBaseModelInfo* CModelInfo::GetModelInfo(const char* name, int32* index)
{
    const auto key = CKeyGen::GetUppercaseKey(name);
    auto curIndex = ms_lastPositionSearched;

    while (curIndex < NUM_MODEL_INFOS) {
        auto mi = GetModelInfo(curIndex);
        if (mi && mi->m_nKey == key) {
            ms_lastPositionSearched = curIndex;
            if (index)
                *index = curIndex;
            return mi;
        }

        ++curIndex;
    }

    curIndex = ms_lastPositionSearched;
    if (curIndex < 0)
        return nullptr;

    while (curIndex >= 0) {
        auto mi = GetModelInfo(curIndex);
        if (mi && mi->m_nKey == key) {
            ms_lastPositionSearched = curIndex;
            if (index)
                *index = curIndex;
            return mi;
        }

        --curIndex;
    }

    return nullptr;
}

CBaseModelInfo* CModelInfo::GetModelInfo(const char* name, int32 minIndex, int32 maxIndex)
{
    const auto key = CKeyGen::GetUppercaseKey(name);
    if (minIndex > maxIndex)
        return nullptr;

    for (auto i = minIndex; i <= maxIndex; ++i) {
        auto mi = GetModelInfo(i);
        if (mi && mi->m_nKey == key)
            return mi;
    }

    return nullptr;
}

int32 CModelInfo::GetModelInfoIndex(const char* name)
{
    const auto key = CKeyGen::GetUppercaseKey(name);
    auto curIndex = ms_lastPositionSearched;

    while (curIndex < NUM_MODEL_INFOS) {
        auto mi = GetModelInfo(curIndex);
        if (mi && mi->m_nKey == key) {
            ms_lastPositionSearched = curIndex;
            return curIndex;
        }

        ++curIndex;
    }

    curIndex = ms_lastPositionSearched;
    if (curIndex < 0)
        return 0;

    while (curIndex >= 0) {
        auto mi = GetModelInfo(curIndex);
        if (mi && mi->m_nKey == key) {
            ms_lastPositionSearched = curIndex;
            return curIndex;
        }

        --curIndex;
    }

    return 0;
}

void CModelInfo::Initialise() {
    memset(ms_modelInfoPtrs, 0, sizeof(ms_modelInfoPtrs));
    ms_lastPositionSearched = 0;

}

void CModelInfo::injectHooks()
{
    CHook::Write(g_libGTASA +  0xA76CF0, &CModelInfo::ms_atomicModelInfoStore);
    CHook::Write(g_libGTASA +  0xBCD208, &CModelInfo::ms_pedModelInfoStore);
    CHook::Write(g_libGTASA +  0xB74840, &CModelInfo::ms_vehicleModelInfoStore);
    CHook::Write(g_libGTASA + 0x8373A8, &CModelInfo::ms_modelInfoPtrs);
    /* เพิ่มจาก sasamp-main: ms_lastPositionSearched */
    CHook::Write(g_libGTASA + 0x837A68, &CModelInfo::ms_lastPositionSearched);

    CHook::Redirect("_ZN10CModelInfo11AddPedModelEi", &CModelInfo::AddPedModel);
    CHook::Redirect("_ZN10CModelInfo15AddVehicleModelEi", &CModelInfo::AddVehicleModel);
    CHook::Redirect("_ZN10CModelInfo14AddAtomicModelEi", &CModelInfo::AddAtomicModel);
    /* เพิ่มจาก sasamp-main: AddClumpModel/AddWeaponModel */
    CHook::Redirect("_ZN10CModelInfo13AddClumpModelEi", &CModelInfo::AddClumpModel);
    CHook::Redirect("_ZN10CModelInfo14AddWeaponModelEi", &CModelInfo::AddWeaponModel);
}
