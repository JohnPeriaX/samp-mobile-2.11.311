//
// Created on 21.05.2024.
//

#pragma once
#include <cstdint>

enum class eGunCommand : int8_t {
    UNKNOWN    = -1,
    NONE       = 0,
    AIM        = 1,
    FIRE       = 2,
    FIREBURST  = 3,
    RELOAD     = 4,
    PISTOLWHIP = 5,

    // These 2 must stay in this order, after all other commands
    END_LEISURE = 6, //! End task when possible
    END_NOW     = 7, //! End task immidiately
};
