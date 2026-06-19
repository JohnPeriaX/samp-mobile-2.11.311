#pragma once

#include "Bike.h"

enum eBmxNodes {
    BMX_NODE_NONE   = 0,
    BMX_CHASSIS     = 1,
    BMX_FORKS_FRONT = 2,
    BMX_FORKS_REAR  = 3,
    BMX_WHEEL_FRONT = 4,
    BMX_WHEEL_REAR  = 5,
    BMX_HANDLEBARS  = 6,
    BMX_CHAINSET    = 7,
    BMX_PEDAL_R     = 8,
    BMX_PEDAL_L     = 9,

    BMX_NUM_NODES
};

struct CBmx : CBike {
public:
    float m_fControlJump;
    float m_fControlPedaling;
    float m_fSprintLeanAngle;
    float m_fCrankAngle;
    float m_fPedalAngleL;
    float m_fPedalAngleR;
    float m_fMidWheelDistY;
    float m_fMidWheelFracY;
    bool  m_bIsFreewheeling;

    static constexpr auto Type = VEHICLE_TYPE_BMX;

public:
    static void InjectHooks();
};
