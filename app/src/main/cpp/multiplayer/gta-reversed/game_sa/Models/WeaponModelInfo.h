//
// Created on 12.07.2025.
//
#pragma once

#include "ClumpModelInfo.h"
#include "gta-reversed/game_sa/Enums/eWeaponType.h"

struct CWeaponModelInfo : public CClumpModelInfo {
public:
    eWeaponType m_weaponInfo;

public:
    /* เพิ่มจาก sasamp-main: CWeaponModelInfo::GetModelType */
    ModelInfoType GetModelType();
};

VALIDATE_SIZE(CWeaponModelInfo, 0x58);
