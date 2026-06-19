//
// Created on 29.05.2024.
//

#pragma once

#include "gta-reversed/game_sa/common.h"
#include "gta-reversed/game_sa/RGBA.h"
#include "gta-reversed/game_sa/RenderWare/RenderWare.h"
#include "gta-reversed/game_sa/Entity/CVehicleGTA.h"

enum class eNeonTypes : uint8 {
    OFF = 0,
    ON_TYPE_STATIC,
    ON_TYPE_RAINDOW,
    ON_TYPE_FLASH,
    ON_TYPE_SHARP,
};

class CVehicleNeon {
public:
    CRGBA       neonColor      {255, 255, 255, 255};
    eNeonTypes  neonType       = eNeonTypes::OFF;
    int         neonState      {};
    uint32      lastNeonTime   {};

public:
    static inline RwTexture* pNeonTex{};

public:
    static void Init();

    void Process();
    void Render(CVehicleGTA* veh) const;

    bool IsSet() const { return neonType != eNeonTypes::OFF; }
};
