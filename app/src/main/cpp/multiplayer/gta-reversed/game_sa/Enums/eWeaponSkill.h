#pragma once
#include "gta-reversed/game_sa/common.h"
enum class eWeaponSkill : uint8 {
    POOR,
    STD,  // standard
    PRO,
    COP
};

/* เพิ่มจาก sasamp-main: NUM_WEAPON_SKILLS */
constexpr auto NUM_WEAPON_SKILLS = 4;
