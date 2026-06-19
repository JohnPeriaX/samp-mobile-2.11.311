#pragma once

#include <cstdint>

struct tBikeHandlingData {
    int32_t m_nVehicleId;
    float   m_fLeanFwdCOM;
    float   m_fLeanFwdForce;
    float   m_fLeanBakCOM;
    float   m_fLeanBakForce;
    float   m_fMaxLean;
    float   m_fFullAnimLean;
    float   m_fDesLean;
    float   m_fSpeedSteer;
    float   m_fSlipSteer;
    float   m_fNoPlayerCOMz;
    float   m_fWheelieAng;
    float   m_fStoppieAng;
    float   m_fWheelieSteer;
    float   m_fWheelieStabMult;
    float   m_fStoppieStabMult;

    int32_t InitFromData(int32_t id, const char* line);
};

static_assert(sizeof(tBikeHandlingData) == 0x40, "Invalid size tBikeHandlingData");
