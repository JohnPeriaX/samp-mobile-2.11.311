//
// Created by Traw-GG on 13.07.2025.
//
#include "AEVehicleAudioEntity.h"
#include "AEAudioEntity.h"
#include "gta-reversed/game_sa/Core/KeyGen.h"
#include "gta-reversed/game_sa/Entity/CVehicleGTA.h"
#include "gta-reversed/game_sa/Models/ModelInfo.h"
#include "samp/main.h"
#include "vendor/patch/patch.h"

#include <cstdio>
#include <cstring>
#include <iterator>

namespace {
    tVehicleAudioSettings gAudioVehicleProperties[20000]{};

    int32 GetModelInfoIndexByName(const char* name) {
        const auto key = CKeyGen::GetUppercaseKey(name);
        for (int32 i = 0; i < CModelInfo::NUM_MODEL_INFOS; ++i) {
            const auto* info = CModelInfo::GetModelInfo(i);
            if (info && info->m_nKey == key) {
                return i;
            }
        }
        return -1;
    }

    bool VehicleUsesSiren(const CVehicleGTA* vehicle) {
        switch (vehicle->m_nModelIndex) {
            case MODEL_FIRETRUK:
            case MODEL_AMBULAN:
            case MODEL_MRWHOOP:
            case MODEL_ENFORCER:
            case MODEL_COPCARLA:
            case MODEL_COPCARSF:
            case MODEL_COPCARVG:
            case MODEL_COPCARRU:
            case MODEL_FBIRANCH:
            case MODEL_FBITRUCK:
            case MODEL_POLMAV:
            case MODEL_SWATVAN:
                return true;
            case MODEL_RHINO:
                return false;
            default:
                return vehicle->m_nVehicleFlags.bSirenOrAlarm != 0;
        }
    }
}

void readVehiclesAudioSettings()
{
    char vehicleModel[50];

    FILE* pFile;

    char line[300];

    memset(gAudioVehicleProperties, 0x00, sizeof(gAudioVehicleProperties));

    tVehicleAudioSettings CurrentVehicleAudioProperties{};

    memset(&CurrentVehicleAudioProperties, 0x0, sizeof(tVehicleAudioSettings));

    char buffer[0xFF];
    sprintf(buffer, "%sAudioConfig/AudioConfig.cfg", g_pszStorage);
    pFile = fopen(buffer, "r");
    if (!pFile)
    {
        FLog("Cannot read AudioConfig.cfg");
        return;
    }

    // File exists
    while (fgets(line, sizeof(line), pFile))
    {
        if (strncmp(line, ";the end", 8) == 0)
            break;

        if (line[0] == ';')
            continue;

        int vehicleSoundType = 0;
        int engineOn = 0;
        int engineOff = 0;
        int bassSetting = 0;
        int hornTone = 0;
        int doorSound = 0;
        int engineUpgrade = 0;
        int radioId = 0;
        int radioType = 0;
        int vehTypeForAudio = 0;

        if (sscanf(line, "%49s %d %d %d %d %f %f %d %f %d %d %d %d %d %f",
                   vehicleModel,
                   &vehicleSoundType,
                   &engineOn,
                   &engineOff,
                   &bassSetting,
                   &CurrentVehicleAudioProperties.m_fBassEq,
                   &CurrentVehicleAudioProperties.field_C,
                   &hornTone,
                   &CurrentVehicleAudioProperties.m_fHornHigh,
                   &doorSound,
                   &engineUpgrade,
                   &radioId,
                   &radioType,
                   &vehTypeForAudio,
                   &CurrentVehicleAudioProperties.m_fHornVolumeDelta) != 15) {
            continue;
        }

        CurrentVehicleAudioProperties.m_nVehicleSoundType = static_cast<eVehicleSoundType>(vehicleSoundType);
        CurrentVehicleAudioProperties.m_nEngineOnSoundBankId = static_cast<int16>(engineOn);
        CurrentVehicleAudioProperties.m_nEngineOffSoundBankId = static_cast<int16>(engineOff);
        CurrentVehicleAudioProperties.m_nBassSetting = static_cast<int8>(bassSetting);
        CurrentVehicleAudioProperties.m_nHornToneSoundInBank = static_cast<int8>(hornTone);
        CurrentVehicleAudioProperties.m_nDoorSound = static_cast<char>(doorSound);
        CurrentVehicleAudioProperties.m_EngineUpgrade = static_cast<char>(engineUpgrade);
        CurrentVehicleAudioProperties.m_nRadioID = static_cast<eRadioID>(radioId);
        CurrentVehicleAudioProperties.m_nRadioType = static_cast<eRadioType>(radioType);
        CurrentVehicleAudioProperties.m_nVehTypeForAudio = static_cast<int8>(vehTypeForAudio);

        const int32 result = GetModelInfoIndexByName(vehicleModel);
        if (result >= 400 && result - 400 < static_cast<int32>(std::size(gAudioVehicleProperties))) {
            memcpy(&gAudioVehicleProperties[result - 400], &CurrentVehicleAudioProperties, sizeof(tVehicleAudioSettings));
        }
    }

    fclose(pFile);
}

tVehicleAudioSettings CAEVehicleAudioEntity::GetVehicleAudioSettings(int16 vehId) {
    const int32 index = vehId - 400;
    if (index < 0 || index >= static_cast<int32>(std::size(gAudioVehicleProperties))) {
        return {};
    }
    return gAudioVehicleProperties[index];
}

void CAEVehicleAudioEntity::Initialise(CEntityGTA* entity) {
    assert(entity && entity->IsVehicle());

    m_nTime144 = 0;
    m_pEntity = entity;
    m_bPlayerDriver = false;
    m_bPlayerPassenger = false;
    m_bVehicleRadioPaused = false;
    m_bSoundsStopped = false;
    m_nEngineState = 0;
    m_nGearRelatedStuff = 0;
    field_AC = 0;
    m_nEngineBankSlotId = -1;
    m_nRainDropCounter = 0;
    field_7C = 0;
    field_B4 = 0;
    field_B8 = 0;
    field_BC = false;
    m_nBoatHitWaveLastPlayedTime = 0;
    m_nTimeToInhibitAcc = 0;
    m_nTimeToInhibitCrz = 0;
    m_bNitroSoundPresent = false;
    m_bDisableHeliEngineSounds = false;
    m_nEngineSoundPlayPos = -1;
    m_nEngineSoundLastPlayedPos = -1;
    field_154 = 0;
    field_14E = 0;
    m_nAcclLoopCounter = 0;

    for (auto i = 0; auto& sound : m_aEngineSounds) {
        sound.Init(i++);
    }

    m_fHornVolume = -100.0f;
    m_fPlaneSoundVolume_Probably = -100.0f;
    m_nSkidSoundType = -1;
    m_nRoadNoiseSoundType = -1;
    m_nFlatTyreSoundType = -1;
    m_nReverseGearSoundType = -1;
    field_234 = -1.0f;
    m_fPlaneSoundSpeed = -1.0f;
    field_248 = -1.0f;

    m_SkidSoundMaybe   = nullptr;
    m_RoadNoiseSound   = nullptr;
    m_FlatTyreSound    = nullptr;
    m_ReverseGearSound = nullptr;
    m_HornTonSound     = nullptr;
    m_SirenSound       = nullptr;
    m_PoliceSirenSound = nullptr;

    field_238 = 0.0f;
    field_23C = 1.0f;
    field_240 = 0.0f;

    m_Settings = GetVehicleAudioSettings(entity->m_nModelIndex);
    m_bModelWithSiren = VehicleUsesSiren(reinterpret_cast<CVehicleGTA*>(entity));
    if (m_Settings.m_nRadioType == eRadioType::RADIO_UNKNOWN) {
        m_Settings.m_nRadioID = eRadioID::RADIO_OFF;
    }

    m_fGeneralVehicleSoundVolume = GetDefaultVolume(AE_GENERAL_VEHICLE_SOUND);

    switch (entity->m_nModelIndex) {
        case MODEL_PIZZABOY:
        case MODEL_CADDY:
        case MODEL_FAGGIO:
        case MODEL_BAGGAGE:
        case MODEL_FORKLIFT:
        case MODEL_VORTEX:
        case MODEL_KART:
        case MODEL_MOWER:
        case MODEL_SWEEPER:
        case MODEL_TUG:
            m_bInhibitAccForLowSpeed = true;
            break;
        default:
            m_bInhibitAccForLowSpeed = false;
            break;
    }

    switch (m_Settings.m_nVehicleSoundType) {
        case VEHICLE_SOUND_CAR:
            m_fGeneralVehicleSoundVolume -= 1.5F;
            m_nEngineAccelerateSoundBankId = m_Settings.m_nEngineOnSoundBankId;
            m_nEngineDecelerateSoundBankId = m_Settings.m_nEngineOffSoundBankId;
            if (m_bEnabled)
                return;

            if (m_Settings.m_nEngineOffSoundBankId != -1 && m_Settings.m_nEngineOffSoundBankId != 129) {
                m_nEngineBankSlotId = CHook::CallFunction<int16>("_ZN21CAEVehicleAudioEntity15RequestBankSlotEs", m_Settings.m_nEngineOffSoundBankId);
            }

            m_bEnabled = true;
            return;

        case VEHICLE_SOUND_MOTORCYCLE:
        case VEHICLE_SOUND_BICYCLE:
            m_nEngineAccelerateSoundBankId = m_Settings.m_nEngineOnSoundBankId;

            if (m_Settings.IsMotorcycle())
                m_fGeneralVehicleSoundVolume = m_fGeneralVehicleSoundVolume - 1.5F;

            if (m_bEnabled)
                return;

            m_nEngineDecelerateSoundBankId = m_Settings.m_nEngineOffSoundBankId;
            if (m_nEngineDecelerateSoundBankId != -1)
                m_nEngineBankSlotId = CHook::CallFunction<int16>("_ZN21CAEVehicleAudioEntity15RequestBankSlotEs", m_Settings.m_nEngineOffSoundBankId);

            m_bEnabled = true;
            return;

        case VEHICLE_SOUND_BOAT:
        case VEHICLE_SOUND_TRAIN:
            m_nEngineAccelerateSoundBankId = m_Settings.m_nEngineOnSoundBankId;
            m_nEngineDecelerateSoundBankId = m_Settings.m_nEngineOffSoundBankId;
            if (m_bEnabled)
                return;

            if (m_Settings.m_nEngineOffSoundBankId != -1 && m_Settings.m_nEngineOffSoundBankId != 129)
                m_nEngineBankSlotId = CHook::CallFunction<int16>("_ZN21CAEVehicleAudioEntity15RequestBankSlotEs", m_Settings.m_nEngineOffSoundBankId);

            m_bEnabled = true;
            return;

        case VEHICLE_SOUND_HELI:
        case VEHICLE_SOUND_NON_VEH:
            m_nEngineDecelerateSoundBankId = m_Settings.m_nEngineOffSoundBankId;
            m_nEngineAccelerateSoundBankId = m_Settings.m_nEngineOnSoundBankId;

            m_bEnabled = true;
            return;

        case VEHICLE_SOUND_PLANE:
            m_nEngineDecelerateSoundBankId = m_Settings.m_nEngineOffSoundBankId;
            m_nEngineAccelerateSoundBankId = m_Settings.m_nEngineOnSoundBankId;
            if (m_bEnabled)
                return;

            if (m_Settings.m_nEngineOffSoundBankId != -1)
                m_nEngineBankSlotId = CHook::CallFunction<int16>("_ZN21CAEVehicleAudioEntity15RequestBankSlotEs", m_Settings.m_nEngineOffSoundBankId);

            m_bEnabled = true;
            return;

        case VEHICLE_SOUND_TRAILER:
            m_nEngineAccelerateSoundBankId = m_Settings.m_nEngineOnSoundBankId;
            m_fGeneralVehicleSoundVolume = m_fGeneralVehicleSoundVolume - 1.5F;
            if (m_bEnabled)
                return;

            m_nEngineDecelerateSoundBankId = m_Settings.m_nEngineOffSoundBankId;
            if (m_nEngineDecelerateSoundBankId != -1)
                m_nEngineBankSlotId = CHook::CallFunction<int16>("_ZN21CAEVehicleAudioEntity15RequestBankSlotEs", m_Settings.m_nEngineOffSoundBankId);

            m_bEnabled = true;
            return;

        default:
            return;
    }
}

void CAEVehicleAudioEntity_Initialise_hooked(CAEVehicleAudioEntity* thiz, CVehicleGTA* pVehicle) {
    thiz->Initialise(pVehicle);
}

void CAEVehicleAudioEntity::InjectHooks() {
    /*
    รอ MAP 2.11: CAEVehicleAudioEntity::Initialise PLT
    2.11 candidate: g_libGTASA + 0x83EE28
    */
}