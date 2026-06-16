//
// Created by x1y2z on 16.09.2023.
//

#pragma once

#include "gta-reversed/game_sa/Entity/CVehicleGTA.h"

class CAutomobile : public CVehicleGTA {
    uint8_t pad0[0x470];
};

VALIDATE_SIZE(CAutomobile, 0xBC8);
