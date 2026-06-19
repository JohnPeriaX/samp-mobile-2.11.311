//
// Created by x1y2z on 07.03.2023.
//

#pragma once

#include "PedModelInfo.h"
#include "AtomicModelInfo.h"
#include "VehicleModelInfo.h"
#include "WeaponModelInfo.h"
#include "gta-reversed/game_sa/Core/Store.h"
#include "gta-reversed/game_sa/constants.h"


class CModelInfo {
public:
    static constexpr int32 NUM_MODEL_INFOS = TOTAL_DFF_MODEL_IDS;
    static inline CBaseModelInfo* ms_modelInfoPtrs[NUM_MODEL_INFOS];
    static inline int32 ms_lastPositionSearched;

    static void injectHooks();

    static constexpr int32_t NUM_PED_MODEL_INFOS = 315;
    static inline CStore<CPedModelInfo, NUM_PED_MODEL_INFOS> ms_pedModelInfoStore;

    static inline CStore<CAtomicModelInfo, 20000> ms_atomicModelInfoStore;

    static constexpr int32 NUM_VEHICLE_MODEL_INFOS = 270;
    static inline CStore<CVehicleModelInfo, NUM_VEHICLE_MODEL_INFOS> ms_vehicleModelInfoStore;

    static constexpr int32 NUM_CLUMP_MODEL_INFOS = 92;
    static inline CStore<CClumpModelInfo, NUM_CLUMP_MODEL_INFOS> ms_clumpModelInfoStore;

    static constexpr int32 NUM_WEAPON_MODEL_INFOS = 51;
    static inline CStore<CWeaponModelInfo, NUM_WEAPON_MODEL_INFOS> ms_weaponModelInfoStore;

    static CPedModelInfo *AddPedModel(int index);

    static CAtomicModelInfo *AddAtomicModel(int index);
    static CDamageAtomicModelInfo* AddDamageAtomicModel(int32 index);
    static CVehicleModelInfo *AddVehicleModel(int index);
    static CClumpModelInfo* AddClumpModel(int32 index);
    static CWeaponModelInfo* AddWeaponModel(int32 index);

    static CBaseModelInfo* GetModelInfo(const char* name, int32 minIndex, int32 maxIndex);
    static CBaseModelInfo* GetModelInfo(const char* name, int32* index = nullptr);
    static int32 GetModelInfoIndex(const char* name);

    static CBaseModelInfo* GetModelInfo(int index) { return ms_modelInfoPtrs[index]; }
    static auto GetPedModelInfo(int32_t index) { return GetModelInfo(index)->AsPedModelInfoPtr(); }
    static auto GetVehicleModelInfo(int32_t index) { return GetModelInfo(index)->AsVehicleModelInfoPtr(); }
    static void SetModelInfo(int index, CBaseModelInfo* pInfo) { ms_modelInfoPtrs[index] = pInfo; }

    static void Initialise();
};

