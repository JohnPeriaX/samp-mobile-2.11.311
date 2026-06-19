//
// Created by traw-GG on 14.07.2025.
//

#include "gta-reversed/game_sa/Mobile/MobileSettings/MobileSettings.h"
#include "vendor/patch/patch.h"

void CMobileSettings::InjectHooks() {
    /* เพิ่มจาก sasamp-main: CMobileSettings::InjectHooks */
    CHook::Write(g_libGTASA + 0x8373D0, &ms_MobileSettings);
}
