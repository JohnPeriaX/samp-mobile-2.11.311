//
// Created on 29.05.2024.
//

#include "gta-reversed/game_sa/Fx/VehicleNeon.h"
#include "gta-reversed/game_sa/Timer.h"
#include "gta-reversed/game_sa/Models/ModelInfo.h"
#include "samp/Utils/CUtil.h"
#include "vendor/patch/patch.h"

namespace {
constexpr uint8 SHADOW_ADDITIVE = 2;
}

/* เพิ่มจาก sasamp-main: CVehicleNeon::Init */
void CVehicleNeon::Init()
{
    if (!pNeonTex)
        pNeonTex = CUtil::LoadTextureFromDB("samp", "neonaper3");
}

/* เพิ่มจาก sasamp-main: CVehicleNeon::Process */
void CVehicleNeon::Process()
{
    if (neonType <= eNeonTypes::ON_TYPE_STATIC)
        return;

    const uint32 dif = CTimer::m_snTimeInMillisecondsNonClipped - lastNeonTime;

    if (neonType == eNeonTypes::ON_TYPE_RAINDOW) {
        neonColor.RainbowCycle(CTimer::m_snTimeInMillisecondsNonClipped);
        return;
    }

    if (neonType == eNeonTypes::ON_TYPE_FLASH) {
        if (dif >= 200) {
            if (neonState == 0) {
                neonColor.a = 0;
                neonState = 1;
            } else if (neonState == 1) {
                neonColor.a = 255;
                neonState = 2;
            } else if (neonState == 2) {
                neonColor.a = 0;
                neonState = 3;
            } else if (neonState == 3) {
                neonColor.a = 255;
                neonState = 4;
            } else if (neonState == 4) {
                neonState = 5;
            } else if (neonState == 5) {
                neonState = 0;
            }
            lastNeonTime = CTimer::m_snTimeInMillisecondsNonClipped;
        }
        return;
    }

    if (neonType == eNeonTypes::ON_TYPE_SHARP) {
        if (dif >= 150) {
            neonColor = CRGBA::RandomColor();
            lastNeonTime = CTimer::m_snTimeInMillisecondsNonClipped;
        }
        return;
    }
}

/* เพิ่มจาก sasamp-main: CVehicleNeon::Render */
void CVehicleNeon::Render(CVehicleGTA* veh) const
{
    if (!veh || !pNeonTex || neonColor.a == 0)
        return;

    const auto* modelInfo = CModelInfo::GetModelInfo(veh->m_nModelIndex);
    if (!modelInfo || !modelInfo->m_pColModel)
        return;

    const CVector pos = modelInfo->m_pColModel->m_boundBox.m_vecMin;
    const CVector center = veh->TransformFromObjectSpace(CVector(0.0f, 0.0f, 0.0f));
    const CVector up = veh->TransformFromObjectSpace(CVector(0.0f, -pos.y - 0.5f, 0.0f)) - center;
    const CVector right = veh->TransformFromObjectSpace(CVector(pos.x + 0.2f, 0.0f, 0.0f)) - center;

    CHook::CallFunction<void>(
        g_libGTASA + 0x5E6FB8,
        SHADOW_ADDITIVE,
        pNeonTex,
        &center,
        up.x * 1.8f,
        up.y * 1.8f,
        right.x * 2.0f,
        right.y * 2.0f,
        static_cast<int16>(-100),
        neonColor.r,
        neonColor.g,
        neonColor.b,
        4.0f,
        false,
        1.0f,
        static_cast<void*>(nullptr),
        true
    );
}
