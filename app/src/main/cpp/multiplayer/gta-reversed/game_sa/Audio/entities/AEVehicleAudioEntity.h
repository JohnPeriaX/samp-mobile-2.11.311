//
// Created by Traw-GG on 13.07.2025.
//
#pragma once

#include "AEAudioEntity.h"
#include "gta-reversed/game_sa/cTransmission.h"
#include "AETwinLoopSoundEntity.h"
#include "gta-reversed/game_sa/Audio/AESound.h"
#include "gta-reversed/game_sa/Enums/eRadioID.h"
#include "gta-reversed/game_sa/Enums/eVehicleType.h"

enum tWheelState : int32;

struct CVehicleGTA;

enum eVehicleSoundType : int8 {
    VEHICLE_SOUND_CAR              = 0x0,
    VEHICLE_SOUND_MOTORCYCLE       = 0x1,
    VEHICLE_SOUND_BICYCLE          = 0x2,
    VEHICLE_SOUND_BOAT             = 0x3,
    VEHICLE_SOUND_HELI             = 0x4,
    VEHICLE_SOUND_PLANE            = 0x5,
    VEHICLE_SOUND_NON_VEH          = 0x6, // SEA_PLANE
    VEHICLE_SOUND_USED_BY_NONE_VEH = 0x7,
    VEHICLE_SOUND_TRAIN            = 0x8,
    VEHICLE_SOUND_TRAILER          = 0x9,
    VEHICLE_SOUND_SPECIAL          = 0xA,
};

enum eRadioType : int8 {
    RADIO_CIVILIAN  = 0,
    RADIO_SPECIAL   = 1,
    RADIO_UNKNOWN   = 2,
    RADIO_EMERGENCY = 3,
    RADIO_DISABLED  = -1,
};

struct tEngineDummySlot {
    int16 m_nBankId;
    int16 m_nUsageCount;

    void Reset() {
        m_nBankId     = -1;
        m_nUsageCount = 0;
    }
};
VALIDATE_SIZE(tEngineDummySlot, 0x4);

struct cVehicleParams {
    int32          nSpecificVehicleType{ VEHICLE_TYPE_IGNORE };
    int32          nBaseVehicleType{ VEHICLE_TYPE_IGNORE };
    bool           bDistanceCalculated{ false };
    float          fDistSqr{ 0.0f };
    CVehicleGTA*   Vehicle{ nullptr };
    cTransmission* Transmission{ nullptr };
    uint32         nModelIndexMinusOffset{ 0 };
    float          fSpeed{ 0.0f };
    int16          ThisAccel{ 0 };
    int16          ThisBrake{ 0 };
    float          fAbsSpeed{ 0.0f };
    float          fZOverSpeed{};
    float          fSpeedRatio{ 0.0f };
    float*         pfGasPedalAudioRevs{ nullptr };
    float          fPrevSpeed{ 0.0f };
    uint8          RealGear{ 0 };
    bool           bHandbrakeOn{ false };
    float          fRealRevsRatio{ 0.0f };
    float          fWheelSpin{ 0.0f };
    int16          NumGears{};
    uint8          NumDriveWheelsOnGround{};
    uint8          NumDriveWheelsOnGroundLastFrame{};
    tWheelState*   WheelState{};
};
VALIDATE_SIZE(cVehicleParams, 0x60);

class tVehicleSound {
public:
    uint32    m_nIndex;
    CAESound* m_pSound;

    void Init(auto index) {
        m_nIndex = index;
        m_pSound = nullptr;
    }
};

struct tVehicleAudioSettings {
    eVehicleSoundType m_nVehicleSoundType;
    int16             m_nEngineOnSoundBankId;
    int16             m_nEngineOffSoundBankId;
    int8              m_nBassSetting; // m_nStereo
    float             m_fBassEq; // m_fBassFactor
    float             field_C;
    int8              m_nHornToneSoundInBank; // sfx id
    float             m_fHornHigh;
    char              m_nDoorSound;
    char              m_EngineUpgrade;
    eRadioID          m_nRadioID;
    eRadioType        m_nRadioType;
    int8              m_nVehTypeForAudio;
    float             m_fHornVolumeDelta;

public:
    [[nodiscard]] bool IsHeli()          const { return m_nVehicleSoundType == eVehicleSoundType::VEHICLE_SOUND_HELI; }
    [[nodiscard]] bool IsPlane()         const { return m_nVehicleSoundType == eVehicleSoundType::VEHICLE_SOUND_PLANE; }
    [[nodiscard]] bool IsFlyingVehicle() const { return IsPlane() || IsHeli(); }
    [[nodiscard]] bool IsNonVeh()        const { return m_nVehicleSoundType == eVehicleSoundType::VEHICLE_SOUND_NON_VEH; }
    [[nodiscard]] bool IsCar()           const { return m_nVehicleSoundType == eVehicleSoundType::VEHICLE_SOUND_CAR; }
    [[nodiscard]] bool IsMotorcycle()    const { return m_nVehicleSoundType == eVehicleSoundType::VEHICLE_SOUND_MOTORCYCLE; }
    [[nodiscard]] bool IsBicycle()       const { return m_nVehicleSoundType == eVehicleSoundType::VEHICLE_SOUND_BICYCLE; }
};
VALIDATE_SIZE(tVehicleAudioSettings, 0x24);

class CPed;

class CAEVehicleAudioEntity : public CAEAudioEntity {
public:
    int16                  field_7C;
    tVehicleAudioSettings  m_Settings;
    bool                   m_bEnabled;
    bool                   m_bPlayerDriver;
    bool                   m_bPlayerPassenger;
    bool                   m_bVehicleRadioPaused;
    bool                   m_bSoundsStopped;
    char                   m_nEngineState;
    uint8                  m_nGearRelatedStuff;
    float                  field_AC;
    bool                   m_bInhibitAccForLowSpeed;
    int16                  m_nRainDropCounter;
    int16                  field_B4;
    int32                  field_B8;
    bool                   field_BC; // ProcessPlayerProp
    bool                   m_bDisableHeliEngineSounds;

    bool                   m_bPlayHornTone;
    bool                   m_bSirenOrAlarmPlaying;
    bool                   m_bHornPlaying;
    float                  m_fHornVolume;
    bool                   m_bModelWithSiren;

    uint32                 m_nBoatHitWaveLastPlayedTime;
    uint32                 m_nTimeToInhibitAcc;
    uint32                 m_nTimeToInhibitCrz;
    float                  m_fGeneralVehicleSoundVolume;
    int16                  m_nEngineDecelerateSoundBankId;
    int16                  m_nEngineAccelerateSoundBankId;
    int16                  m_nEngineBankSlotId;
    tVehicleSound          m_aEngineSounds[12];
    int32                  m_nTime144;

    int16                  m_nEngineSoundPlayPos;
    int16                  m_nEngineSoundLastPlayedPos;
    int16                  m_nAcclLoopCounter;
    int16                  field_14E; // CancelVehicleEngineSound
    uint32                 field_150; // CancelVehicleEngineSound
    int16                  field_154; // CancelVehicleEngineSound m_nPrevEngineSoundPlayPos

    int16                  m_nSkidSoundType;
    CAESound*              m_SkidSoundMaybe;

    int16                  m_nRoadNoiseSoundType;
    CAESound*              m_RoadNoiseSound;

    int16                  m_nFlatTyreSoundType;
    CAESound*              m_FlatTyreSound;

    int16                  m_nReverseGearSoundType;
    CAESound*              m_ReverseGearSound;

    int32                  _align_174;
    CAESound*              m_HornTonSound;
    CAESound*              m_SirenSound;
    CAESound*              m_PoliceSirenSound;
    CAETwinLoopSoundEntity m_TwinSkidSound;

    float                  m_fPlaneSoundSpeed;
    float                  m_fPlaneSoundVolume_Probably;

    float                  field_234; // speed ?
    float                  field_238; // volume ?

    float                  field_23C;
    float                  field_240;

    bool                   m_bNitroSoundPresent;
    float                  field_248;

public:
    static void InjectHooks();

    void Initialise(CEntityGTA* entity);
    tVehicleAudioSettings GetVehicleAudioSettings(int16 vehId);

    static constexpr int32 NUM_DUMMY_ENGINE_SLOTS = 10;
    static tEngineDummySlot (&s_DummyEngineSlots)[NUM_DUMMY_ENGINE_SLOTS];

};
VALIDATE_SIZE(CAEVehicleAudioEntity, 0x310);