//
// Created by x1y2z on 16.09.2023.
//

#pragma once

#include "Automobile.h"

class CHeli : public CAutomobile {
    uint8_t pad0[0x98];
};

VALIDATE_SIZE(CHeli, 0xC60);