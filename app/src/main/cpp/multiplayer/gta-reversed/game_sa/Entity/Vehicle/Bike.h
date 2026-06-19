//
// Created by traw-GG on 16.09.2024.
//

#pragma once

#include "gta-reversed/game_sa/Entity/CVehicleGTA.h"
#include "gta-reversed/game_sa/Enums/eSkidmarkType.h"
#include "gta-reversed/game_sa/tBikeHandlingData.h"

enum eBikeNodes {
    BIKE_NODE_NONE   = 0,
    BIKE_CHASSIS     = 1,
    BIKE_FORKS_FRONT = 2,
    BIKE_FORKS_REAR  = 3,
    BIKE_WHEEL_FRONT = 4,
    BIKE_WHEEL_REAR  = 5,
    BIKE_MUDGUARD    = 6,
    BIKE_HANDLEBARS  = 7,
    BIKE_MISC_A      = 8,
    BIKE_MISC_B      = 9,

    BIKE_NUM_NODES
};

enum tWheelState : int32;

struct CBike : CVehicleGTA {
    static constexpr auto NUM_SUSP_LINES = 4;
public:
    RwFrame* m_aBikeNodes[BIKE_NUM_NODES];
    bool     m_bLeanMatrixCalculated;
    CMatrix  m_mLeanMatrix;
    union {
        struct {
            uint8 bShouldNotChangeColour : 1;
            uint8 bPanelsAreThougher : 1;
            uint8 bWaterTight : 1;
            uint8 bGettingPickedUp : 1;
            uint8 bOnSideStand : 1;
            uint8 bPlayerBoost : 1;
            uint8 bEngineOnFire : 1;
            uint8 bWheelieForCamera : 1;
        } bikeFlags;
        uint8 nBikeFlags;
    };
    CVector m_vecAveGroundNormal;
    CVector m_vecGroundRight;
    CVector m_vecOldSpeedForPlayback;
    tBikeHandlingData* m_BikeHandling;
    CRideAnimData m_RideAnimData;
    uint8 m_nWheelStatus[2];
    CColPoint m_aWheelColPoints[NUM_SUSP_LINES];
    float m_aWheelRatios[NUM_SUSP_LINES];
    float m_aRatioHistory[NUM_SUSP_LINES];
    float m_aWheelCounts[NUM_SUSP_LINES];
    float m_fBrakeCount;
    eSkidmarkType m_aWheelSkidmarkType[2];
    bool m_bWheelBloody[2];
    bool m_bMoreSkidMarks[2];
    float m_aWheelPitchAngles[2];
    float m_aWheelAngularVelocity[2];
    float m_aWheelSuspensionHeights[2];
    float m_aWheelOrigHeights[2];
    float m_fSuspensionLength[NUM_SUSP_LINES];
    float m_fLineLength[NUM_SUSP_LINES];
    float m_fHeightAboveRoad;
    float m_fExtraTractionMult;
    float m_fSwingArmLength;
    float m_fForkYOffset;
    float m_fForkZOffset;
    float m_fSteerAngleTan;
    uint16 m_nBrakesOn;
    float m_fTyreTemp;
    float m_fBrakingSlide;
    uint8 m_nFixLeftHand;
    uint8 m_nFixRightHand;
    uint8 m_nTestPedCollision;
    float m_fPrevSpeed;
    float m_BlowUpTimer;
    CPhysical* m_aGroundPhysicalPtrs[4];
    CVector m_aGroundOffsets[4];
    CEntityGTA* m_Damager;
    uint8 m_nNoOfContactWheels;
    uint8 m_nDriveWheelsOnGround;
    uint8 m_nDriveWheelsOnGroundLastFrame;
    float m_fGasPedalAudioRevs;
    tWheelState m_aWheelState[2];

    static constexpr auto Type = VEHICLE_TYPE_BIKE;

public:
    static void InjectHooks();

    CRideAnimData* GetRideAnimData() { return &m_RideAnimData; }
};
VALIDATE_SIZE(CBike, 0xA18);
