#include "samp/main.h"
#include "samp/Multiplayer/Multiplayer.h"
#include "vendor/patch/patch.h"
#include "gta-reversed/game_sa/vehicleColoursTable.h"
#include "samp/Settings/Settings.h"

///skip for now later if above is already converted
extern CSettings* pSettings;

VehicleAudioPropertiesStruct VehicleAudioProperties[20000];
#include "gta-reversed/game_sa/World.h"
#include "samp/Network/Network.h"

extern CGame* pGame;

void ApplyFPSPatch(uint8_t fps)
{
    uint8_t targetFPS = fps;
    if (targetFPS < 30) targetFPS = 30;
    if (targetFPS > 120) targetFPS = 120;

    // asm64.h is included through vendor/patch/patch.h.
    // MOV W8/W9, #targetFPS for 2.11 DoGameState(float) FPS constants.
    const uint32_t movW8Fps = ARMv8::MOVBits::Create(targetFPS, 8, false);
    const uint32_t movW9Fps = ARMv8::MOVBits::Create(targetFPS, 9, false);

    CHook::Write32(g_libGTASA + 0x3683D0, movW8Fps);
    CHook::Write32(g_libGTASA + 0x368644, movW8Fps);
    CHook::Write32(g_libGTASA + 0x3685B8, movW9Fps);
    CHook::Write32(g_libGTASA + 0x368924, movW8Fps);


    FLog("New fps limit = %d", targetFPS);
}


void DisableAutoAim()
{
    CHook::RET("_ZN10CPlayerPed22FindWeaponLockOnTargetEv"); // CPed::FindWeaponLockOnTarget
    CHook::RET("_ZN10CPlayerPed26FindNextWeaponLockOnTargetEP7CEntityb"); // CPed::FindNextWeaponLockOnTarget
    CHook::RET("_ZN4CPed21SetWeaponLockOnTargetEP7CEntity"); // CPed::SetWeaponLockOnTarget
}

// BEGIN GENERATED LEGACY PATCH BACKLOG
// Enabled mapped patches. Disabled block keeps no-map / unsafe old-byte evidence only.

void ApplyMappedLegacyPatches()
{
    FLog("Installing mapped legacy patches..");

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN14MainMenuScreen10OnSettingsEv @ 0x710998 NOP 2
    //CHook::NOP(g_libGTASA + 0x710998, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN10GameScreenC2Ev @ 0x716AD4 NOP 2
    //CHook::NOP(g_libGTASA + 0x716AD4, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN10GameScreenC2Ev @ 0x716B0A NOP 2
    //CHook::NOP(g_libGTASA + 0x716B0A, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN10GameScreenC2Ev @ 0x716C62 NOP 2
    //CHook::NOP(g_libGTASA + 0x716C62, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _Z14Menu_MapRenderv @ 0x71D54C NOP 2
    //CHook::NOP(g_libGTASA + 0x71D54C, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN17CWidgetPlayerInfo4DrawEv @ 0x350722 NOP 2
    //CHook::NOP(g_libGTASA + 0x350722, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN17CWidgetPlayerInfo4DrawEv @ 0x350824 NOP 2
    //CHook::NOP(g_libGTASA + 0x350824, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN17CWidgetPlayerInfo4DrawEv @ 0x350854 NOP 2
    //CHook::NOP(g_libGTASA + 0x350854, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN17CWidgetPlayerInfo4DrawEv @ 0x35087A NOP 2
    //CHook::NOP(g_libGTASA + 0x35087A, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN17CWidgetPlayerInfo4DrawEv @ 0x3508B4 NOP 2
    //CHook::NOP(g_libGTASA + 0x3508B4, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN17CWidgetPlayerInfo4DrawEv @ 0x35091A NOP 2
    //CHook::NOP(g_libGTASA + 0x35091A, 2);

    // _ZN8CCarCtrl18GenerateRandomCarsEv @ 0x3C8A54 RET
    CHook::RET("_ZN8CCarCtrl18GenerateRandomCarsEv");

    // _ZN6CCheat12WeaponCheat4Ev @ 0x3DF40C RET
    CHook::RET("_ZN6CCheat12WeaponCheat4Ev");

    // _ZN6CCheat12WeaponCheat1Ev @ 0x3DECB8 RET
    CHook::RET("_ZN6CCheat12WeaponCheat1Ev");

    // _ZN6CCheat12WeaponCheat2Ev @ 0x3DEF78 RET
    CHook::RET("_ZN6CCheat12WeaponCheat2Ev");

    // _ZN6CCheat16AddToCheatStringEc @ 0x3E12C4 RET
    CHook::RET("_ZN6CCheat16AddToCheatStringEc");

    // _ZN6CCheat8DoCheatsEv @ 0x3E126C RET
    CHook::RET("_ZN6CCheat8DoCheatsEv");

    // _ZN6CCheat16ProcessCheatMenuEv @ 0x3E26B8 RET
    CHook::RET("_ZN6CCheat16ProcessCheatMenuEv");

    // _ZN10CEntryExit19GenerateAmbientPedsERK7CVector @ 0x3EA44C RET
    CHook::RET("_ZN10CEntryExit19GenerateAmbientPedsERK7CVector");

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN10CEntryExit18TransitionFinishedEP4CPed @ 0x3E85C2 NOP 4
    //CHook::NOP(g_libGTASA + 0x3E85C2, 4);

    // _ZN8CGarages14TriggerMessageEPcsts @ 0x3F52F8 RET
    CHook::RET("_ZN8CGarages14TriggerMessageEPcsts");

    // _ZN17CVehicleRecording4LoadEP8RwStreamii @ 0x40A878 RET
    CHook::RET("_ZN17CVehicleRecording4LoadEP8RwStreamii");

    // _ZN11CRoadBlocks18GenerateRoadBlocksEv @ 0x40B6B0 RET
    CHook::RET("_ZN11CRoadBlocks18GenerateRoadBlocksEv");

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN11CTheScripts7ProcessEv @ 0x412380 NOP 2
    //CHook::NOP(g_libGTASA + 0x412380, 2);

    // _ZN14CRunningScript25ProcessCommands1800To1899Ei @ 0x439938 RET
    CHook::RET("_ZN14CRunningScript25ProcessCommands1800To1899Ei");

    // _ZN17CStuntJumpManager6UpdateEv @ 0x450418 RET
    CHook::RET("_ZN17CStuntJumpManager6UpdateEv");

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN28CPedDamageResponseCalculator21ComputeDamageResponseEP4CPedR18CPedDamageResponseb @ 0x4E5AC4 NOP 2
    //CHook::NOP(g_libGTASA + 0x4E5AC4, 2);

    // _ZN26CAEGlobalWeaponAudioEntity21ServiceAmbientGunFireEv @ 0x37E788 RET
    CHook::RET("_ZN26CAEGlobalWeaponAudioEntity21ServiceAmbientGunFireEv");

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN12CAudioEngine7ServiceEv @ 0x3A8DBE NOP 2
    //CHook::NOP(g_libGTASA + 0x3A8DBE, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN12CAudioEngine7ServiceEv @ 0x3A8DD0 NOP 2
    //CHook::NOP(g_libGTASA + 0x3A8DD0, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN12CAudioEngine5ResetEv @ 0x3A92CC NOP 2
    //CHook::NOP(g_libGTASA + 0x3A92CC, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN12CAudioEngine20PreloadCutsceneTrackEsh @ 0x3A99DE NOP 2
    //CHook::NOP(g_libGTASA + 0x3A99DE, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN12CAudioEngine16PreloadBeatTrackEs @ 0x3A9C78 NOP 2
    //CHook::NOP(g_libGTASA + 0x3A9C78, 2);

    // _ZN7CCamera8CamShakeEffff @ 0x46F95C RET
    CHook::RET("_ZN7CCamera8CamShakeEffff");

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN7CCamera10CamControlEv @ 0x46ACE6 WRITE 0
    //CHook::Write(g_libGTASA + 0x46ACE6, 0);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CGame8ShutdownEv @ 0x495962 NOP 2
    //CHook::NOP(g_libGTASA + 0x495962, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CGame8ShutdownEv @ 0x4959A6 NOP 2
    //CHook::NOP(g_libGTASA + 0x4959A6, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CGame8ShutdownEv @ 0x4959B6 NOP 2
    //CHook::NOP(g_libGTASA + 0x4959B6, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CGame7ProcessEv @ 0x4960D0 NOP 2
    //CHook::NOP(g_libGTASA + 0x4960D0, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CGame7ProcessEv @ 0x4960EA NOP 2
    //CHook::NOP(g_libGTASA + 0x4960EA, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CGame7ProcessEv @ 0x496128 NOP 2
    //CHook::NOP(g_libGTASA + 0x496128, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CGame7ProcessEv @ 0x49617A NOP 2
    //CHook::NOP(g_libGTASA + 0x49617A, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CGame7ProcessEv @ 0x49619C NOP 2
    //CHook::NOP(g_libGTASA + 0x49619C, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CGame7ProcessEv @ 0x49630E NOP 2
    //CHook::NOP(g_libGTASA + 0x49630E, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CGame7ProcessEv @ 0x496324 NOP 2
    //CHook::NOP(g_libGTASA + 0x496324, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CGame7ProcessEv @ 0x4963F4 NOP 2
    //CHook::NOP(g_libGTASA + 0x4963F4, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CGame7ProcessEv @ 0x4963FA NOP 2
    //CHook::NOP(g_libGTASA + 0x4963FA, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _Z10DisplayFPSv @ 0x4979B0 NOP 2
    //CHook::NOP(g_libGTASA + 0x4979B0, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _Z11RenderSceneb @ 0x49873C NOP 1
    //CHook::NOP(g_libGTASA + 0x49873C, 1);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _Z11RenderSceneb @ 0x498784 NOP 2
    //CHook::NOP(g_libGTASA + 0x498784, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _Z4IdlePvb @ 0x498FAC NOP 2
    //CHook::NOP(g_libGTASA + 0x498FAC, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _Z4IdlePvb @ 0x498FB0 NOP 2
    //CHook::NOP(g_libGTASA + 0x498FB0, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN9CPhysicalD1Ev @ 0x4A0904 NOP 2
    //CHook::NOP(g_libGTASA + 0x4A0904, 2);

    // _ZN11CPlayerInfo17FindObjectToStealEP4CPed @ 0x4AF574 RET
    CHook::RET("_ZN11CPlayerInfo17FindObjectToStealEP4CPed");

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN11CPlayerInfo10KillPlayerEv @ 0x4B05F2 NOP 2
    //CHook::NOP(g_libGTASA + 0x4B05F2, 2);

    // _ZN6CRopes6UpdateEv @ 0x4B7B80 RET
    CHook::RET("_ZN6CRopes6UpdateEv");

    // _ZN10CPlaceName7ProcessEv @ 0x4C5048 RET
    CHook::RET("_ZN10CPlaceName7ProcessEv");

    // _ZN4CHud24SetHelpMessageStatUpdateEhtff @ 0x510B3C RET
    CHook::RET("_ZN4CHud24SetHelpMessageStatUpdateEhtff");

    // _ZN4CHud15DrawVehicleNameEv @ 0x512200 RET
    CHook::RET("_ZN4CHud15DrawVehicleNameEv");

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN4CHud4DrawEv @ 0x514080 NOP 2
    //CHook::NOP(g_libGTASA + 0x514080, 2);

    // _ZN6CRadar10DrawLegendEiii @ 0x51C348 RET
    CHook::RET("_ZN6CRadar10DrawLegendEiii");

    // _ZN6CRadar19AddBlipToLegendListEhi @ 0x51BFAC RET
    CHook::RET("_ZN6CRadar19AddBlipToLegendListEhi");

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN6CRadar14DrawEntityBlipEihif @ 0x51ADDC NOP 2
    //CHook::NOP(g_libGTASA + 0x51ADDC, 2);

    // _ZN10Interior_c10AddPickupsEv @ 0x52192C RET
    CHook::RET("_ZN10Interior_c10AddPickupsEv");

    // _ZN15InteriorGroup_c9SetupPedsEv @ 0x5267BC RET
    CHook::RET("_ZN15InteriorGroup_c9SetupPedsEv");

    // _ZN15InteriorGroup_c4ExitEv @ 0x525798 RET
    CHook::RET("_ZN15InteriorGroup_c4ExitEv");

    // _ZN15InteriorGroup_c5SetupEv @ 0x527710 RET
    CHook::RET("_ZN15InteriorGroup_c5SetupEv");

    // _ZN11CFileLoader10LoadPickupEPKc @ 0x555024 RET
    CHook::RET("_ZN11CFileLoader10LoadPickupEPKc");

    // _ZN11CFileLoader9LoadSceneEPKc @ 0x551C84 RET
    CHook::RET("_ZN11CFileLoader9LoadSceneEPKc");

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN11CFileLoader9LoadSceneEPKc @ 0x552132 NOP 2
    //CHook::NOP(g_libGTASA + 0x552132, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN10CStreaming5Init2Ev @ 0x5558CA NOP 1
    //CHook::NOP(g_libGTASA + 0x5558CA, 1);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _Z12LightsCreateP7RpWorld @ 0x55BB2E NOP 2
    //CHook::NOP(g_libGTASA + 0x55BB2E, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN10CPlayerPed17ProcessAnimGroupsEv @ 0x5B8222 NOP 5
    //CHook::NOP(g_libGTASA + 0x5B8222, 5);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN10CPlayerPed17ProcessAnimGroupsEv @ 0x5B83F4 NOP 17
    //CHook::NOP(g_libGTASA + 0x5B83F4, 17);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN10CPlayerPed17ClearWeaponTargetEv @ 0x5B7C10 NOP 2
    //CHook::NOP(g_libGTASA + 0x5B7C10, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN10CPlayerPed15SetInitialStateEb @ 0x5B56F8 NOP 2
    //CHook::NOP(g_libGTASA + 0x5B56F8, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN10CPlayerPed14ProcessControlEv @ 0x5B6BF4 NOP 11
    //CHook::NOP(g_libGTASA + 0x5B6BF4, 11);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN10CPlayerPed14ProcessControlEv @ 0x5B6C0C NOP 3
    //CHook::NOP(g_libGTASA + 0x5B6C0C, 3);

    // _ZN11CPopulation6AddPedE8ePedTypejRK7CVectorb @ 0x5C2A8C RET
    CHook::RET("_ZN11CPopulation6AddPedE8ePedTypejRK7CVectorb");

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN11CPopulation11AddPedInCarEP8CVehiclebiibb @ 0x5C41B4 NOP 16
    //CHook::NOP(g_libGTASA + 0x5C41B4, 16);

    // _ZN11CPopulation17AddPedAtAttractorEiP9C2dEffect7CVectorP7CEntityi @ 0x5C4E68 RET
    CHook::RET("_ZN11CPopulation17AddPedAtAttractorEiP9C2dEffect7CVectorP7CEntityi");

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN11CPopulation17AddPedAtAttractorEiP9C2dEffect7CVectorP7CEntityi @ 0x5C4F48 NOP 9
    //CHook::NOP(g_libGTASA + 0x5C4F48, 9);

    // _ZN8C_PcSave8SaveSlotEab @ 0x606BB4 RET
    CHook::RET("_ZN8C_PcSave8SaveSlotEab");

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN26CTaskComplexUseMobilePhone16RemovePhoneModelEP4CPed @ 0x62EE42 WRITE 0xFFFFFFFF
    //CHook::Write(g_libGTASA + 0x62EE42, 0xFFFFFFFF);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN26CTaskComplexUseMobilePhone14ControlSubTaskEP4CPed @ 0x62F3A0 WRITE 0xFFFFFFFF
    //CHook::Write(g_libGTASA + 0x62F3A0, 0xFFFFFFFF);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN20CTaskComplexEnterCar17CreateNextSubTaskEP4CPed @ 0x635A9C NOP 5
    //CHook::NOP(g_libGTASA + 0x635A9C, 5);

    // _ZN11CAutomobile21ProcessFlyingCarStuffEv @ 0x6A5870 RET
    CHook::RET("_ZN11CAutomobile21ProcessFlyingCarStuffEv");

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN11CAutomobile14ProcessControlEv @ 0x6A7812 NOP 2
    //CHook::NOP(g_libGTASA + 0x6A7812, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CBike9ProcessAIERj @ 0x6B99C8 WRITE 0x9B
    //CHook::Write(g_libGTASA + 0x6B99C8, 0x9B);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CBike14ProcessControlEv @ 0x6B6996 NOP 2
    //CHook::NOP(g_libGTASA + 0x6B6996, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CBoat14ProcessControlEv @ 0x6C1822 NOP 2
    //CHook::NOP(g_libGTASA + 0x6C1822, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CBoat14ProcessControlEv @ 0x6C19B8 NOP 4
    //CHook::NOP(g_libGTASA + 0x6C19B8, 4);

    // _ZN17CTheCarGenerators7ProcessEv @ 0x6C4348 RET
    CHook::RET("_ZN17CTheCarGenerators7ProcessEv");

    // _ZN5CHeli11UpdateHelisEv @ 0x6C97F0 RET
    CHook::RET("_ZN5CHeli11UpdateHelisEv");

    // _ZN6CPlane27DoPlaneGenerationAndRemovalEv @ 0x6CFDE0 RET
    CHook::RET("_ZN6CPlane27DoPlaneGenerationAndRemovalEv");

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN6CTrain10InitTrainsEv @ 0x6D3E06 NOP 2
    //CHook::NOP(g_libGTASA + 0x6D3E06, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN6CTrain10InitTrainsEv @ 0x6D3E24 NOP 2
    //CHook::NOP(g_libGTASA + 0x6D3E24, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN6CTrain14ProcessControlEv @ 0x6D424A NOP 2
    //CHook::NOP(g_libGTASA + 0x6D424A, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN8CVehicle9SetDriverEP4CPed @ 0x6DBED0 NOP 2
    //CHook::NOP(g_libGTASA + 0x6DBED0, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN8CVehicle9SetDriverEP4CPed @ 0x6DBEDC WRITE 0
    //CHook::Write(g_libGTASA + 0x6DBEDC, 0);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZNK8CVehicle11CanBeDrivenEv @ 0x6E8568 WRITE 0xFF
    //CHook::Write(g_libGTASA + 0x6E8568, 0xFF);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN8CVehicle15DoHeadLightBeamEiR7CMatrixh @ 0x6E903A NOP 2
    //CHook::NOP(g_libGTASA + 0x6E903A, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN8CVehicle15DoHeadLightBeamEiR7CMatrixh @ 0x6E9040 NOP 4
    //CHook::NOP(g_libGTASA + 0x6E9040, 4);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN8CVehicle15DoHeadLightBeamEiR7CMatrixh @ 0x6E90BC NOP 4
    //CHook::NOP(g_libGTASA + 0x6E90BC, 4);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN8CVehicle15DoHeadLightBeamEiR7CMatrixh @ 0x6E90F4 NOP 4
    //CHook::NOP(g_libGTASA + 0x6E90F4, 4);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN8CVehicle15DoHeadLightBeamEiR7CMatrixh @ 0x6E9100 NOP 2
    //CHook::NOP(g_libGTASA + 0x6E9100, 2);

    // _ZN6CBirds6RenderEv @ 0x5C9E04 RET
    CHook::RET("_ZN6CBirds6RenderEv");

    // _ZN6CGlass6RenderEv @ 0x5D8828 RET
    CHook::RET("_ZN6CGlass6RenderEv");

    // _ZN22CRealTimeShadowManager20ReturnRealTimeShadowEP15CRealTimeShadow @ 0x5E610C RET
    CHook::RET("_ZN22CRealTimeShadowManager20ReturnRealTimeShadowEP15CRealTimeShadow");

    // _ZN22CRealTimeShadowManager6UpdateEv @ 0x5E5D34 RET
    CHook::RET("_ZN22CRealTimeShadowManager6UpdateEv");

    // _ZN8CShadows19RenderStaticShadowsEb @ 0x5E9094 RET
    CHook::RET("_ZN8CShadows19RenderStaticShadowsEb");

    // _ZN8CShadows19RenderStoredShadowsEb @ 0x5E8370 RET
    CHook::RET("_ZN8CShadows19RenderStoredShadowsEb");

    // _ZN8CMirrors16RenderReflBufferEb @ 0x5F3C58 RET
    CHook::RET("_ZN8CMirrors16RenderReflBufferEb");

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN10CExplosion12AddExplosionEP7CEntityS1_14eExplosionType7CVectorjhfh @ 0x6F61EC NOP 2
    //CHook::NOP(g_libGTASA + 0x6F61EC, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN10CExplosion12AddExplosionEP7CEntityS1_14eExplosionType7CVectorjhfh @ 0x6F6B2C NOP 2
    //CHook::NOP(g_libGTASA + 0x6F6B2C, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN14MainMenuScreen11AddAllItemsEv @ 0x70EB0E NOP 1
    //CHook::NOP(g_libGTASA + 0x70EB0E, 1);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN14MainMenuScreen11AddAllItemsEv @ 0x70ED88 NOP 1
    //CHook::NOP(g_libGTASA + 0x70ED88, 1);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN14SettingsScreenC2Ev @ 0x710DD2 NOP 1
    //CHook::NOP(g_libGTASA + 0x710DD2, 1);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN11AudioScreenC2Ev @ 0x716F30 NOP 2
    //CHook::NOP(g_libGTASA + 0x716F30, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN15StartGameScreen14OnNewGameCheckEv @ 0x719024 NOP 2
    //CHook::NOP(g_libGTASA + 0x719024, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN17CWidgetPlayerInfo10DrawWantedEv @ 0x35177A NOP 1
    //CHook::NOP(g_libGTASA + 0x35177A, 1);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN17CWidgetRegionLook15OnReleasedTouchEv @ 0x506570 NOP 2
    //CHook::NOP(g_libGTASA + 0x506570, 2);

    // _ZN10CCollision24CheckCameraCollisionPedsEiiP7CVectorS1_Pf @ 0x3BE800 RET
    CHook::RET("_ZN10CCollision24CheckCameraCollisionPedsEiiP7CVectorS1_Pf");

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN18CAEFireAudioEntity16UpdateParametersEP8CAESounds @ 0x37C94A NOP 7
    //CHook::NOP(g_libGTASA + 0x37C94A, 7);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CGame7ProcessEv @ 0x49635E NOP 2
    //CHook::NOP(g_libGTASA + 0x49635E, 2);

    // _Z10DisplayFPSv @ 0x49789C RET
    CHook::RET("_Z10DisplayFPSv");

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _Z4IdlePvb @ 0x498FEC NOP 2
    //CHook::NOP(g_libGTASA + 0x498FEC, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _Z4IdlePvb @ 0x498FF0 NOP 2
    //CHook::NOP(g_libGTASA + 0x498FF0, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _Z4IdlePvb @ 0x499224 NOP 2
    //CHook::NOP(g_libGTASA + 0x499224, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN9CPhysicalD1Ev @ 0x4A0908 NOP 2
    //CHook::NOP(g_libGTASA + 0x4A0908, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN9CPhysicalD0Ev @ 0x4A095C NOP 2
    //CHook::NOP(g_libGTASA + 0x4A095C, 2);

    // _ZN11CPlayerInfo9AddHealthEi @ 0x4B0AA0 RET
    CHook::RET("_ZN11CPlayerInfo9AddHealthEi");

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN10CTimeCycle19CalcColoursForPointE7CVectorP10CColourSet @ 0x4C3204 WRITE 0x41C80000
    //CHook::Write(g_libGTASA + 0x4C3204, 0x41C80000);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN10CTimeCycle19CalcColoursForPointE7CVectorP10CColourSet @ 0x4C3E70 WRITE 0x40A00000
    //CHook::Write(g_libGTASA + 0x4C3E70, 0x40A00000);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN6CRadar14DrawEntityBlipEihif @ 0x51AEC0 NOP 3
    //CHook::NOP(g_libGTASA + 0x51AEC0, 3);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN6CRadar14DrawEntityBlipEihif @ 0x51AEC2 NOP 2
    //CHook::NOP(g_libGTASA + 0x51AEC2, 2);

    // _ZN10Interior_c4ExitEv @ 0x521BE0 RET
    CHook::RET("_ZN10Interior_c4ExitEv");

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN11CFileLoader9LoadSceneEPKc @ 0x551FDC NOP 2
    //CHook::NOP(g_libGTASA + 0x551FDC, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN10CStreaming5Init2Ev @ 0x555916 WRITE 0x10000000
    //CHook::Write(g_libGTASA + 0x555916, 0x10000000);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN10CStreaming5Init2Ev @ 0x55591C WRITE 0x10000000
    //CHook::Write(g_libGTASA + 0x55591C, 0x10000000);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CGame20InitialiseRenderWareEv @ 0x55B2CA NOP 2
    //CHook::NOP(g_libGTASA + 0x55B2CA, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _Z12LightsCreateP7RpWorld @ 0x55BAF8 NOP 2
    //CHook::NOP(g_libGTASA + 0x55BAF8, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CGame5Init2EPKc @ 0x55F118 NOP 2
    //CHook::NOP(g_libGTASA + 0x55F118, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN10CPlayerPed14ProcessControlEv @ 0x5B6AFE NOP 2
    //CHook::NOP(g_libGTASA + 0x5B6AFE, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN10CPlayerPed17ProcessAnimGroupsEv @ 0x5B829A NOP 2
    //CHook::NOP(g_libGTASA + 0x5B829A, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN11CAutomobile14ProcessControlEv @ 0x6A780A NOP 2
    //CHook::NOP(g_libGTASA + 0x6A780A, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CBike14ProcessControlEv @ 0x6B6986 NOP 2
    //CHook::NOP(g_libGTASA + 0x6B6986, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CBike9ProcessAIERj @ 0x6B9B48 NOP 1
    //CHook::NOP(g_libGTASA + 0x6B9B48, 1);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CBoat14ProcessControlEv @ 0x6C1820 NOP 2
    //CHook::NOP(g_libGTASA + 0x6C1820, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CBoat14ProcessControlEv @ 0x6C1B0C NOP 2
    //CHook::NOP(g_libGTASA + 0x6C1B0C, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN6CTrain14ProcessControlEv @ 0x6D4248 NOP 2
    //CHook::NOP(g_libGTASA + 0x6D4248, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN8CVehicle12RemoveDriverEb @ 0x6DC0AC NOP 2
    //CHook::NOP(g_libGTASA + 0x6DC0AC, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN8CVehicle12RemoveDriverEb @ 0x6DC0EE NOP 2
    //CHook::NOP(g_libGTASA + 0x6DC0EE, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZNK8CVehicle11CanBeDrivenEv @ 0x6E8566 WRITE 0xFF
    //CHook::Write(g_libGTASA + 0x6E8566, 0xFF);

    // _ZN22CRealTimeShadowManager4InitEv @ 0x5E5A90 RET
    CHook::RET("_ZN22CRealTimeShadowManager4InitEv");

    // _ZN22CRealTimeShadowManager4ExitEv @ 0x5E5BF8 RET
    CHook::RET("_ZN22CRealTimeShadowManager4ExitEv");

    // _ZN22CRealTimeShadowManager11CamDistCompEPKvS1_ @ 0x5E5C70 RET
    CHook::RET("_ZN22CRealTimeShadowManager11CamDistCompEPKvS1_");

    // _ZN22CRealTimeShadowManager6ReInitEv @ 0x5E6124 RET
    CHook::RET("_ZN22CRealTimeShadowManager6ReInitEv");

    // _ZN22CRealTimeShadowManager17DoShadowThisFrameEP9CPhysical @ 0x5E6224 RET
    CHook::RET("_ZN22CRealTimeShadowManager17DoShadowThisFrameEP9CPhysical");

    // _ZN22CRealTimeShadowManager17GetRealTimeShadowEP9CPhysical @ 0x5E62F0 RET
    CHook::RET("_ZN22CRealTimeShadowManager17GetRealTimeShadowEP9CPhysical");

    // _ZN8CVehicle18DoDriveByShootingsEv @ 0x701694 RET
    CHook::RET("_ZN8CVehicle18DoDriveByShootingsEv");

    // _ZN6CTrain18CreateMissionTrainE7CVectorbjPPS_S2_iib @ 0x6D66D8 RET
    CHook::RET("_ZN6CTrain18CreateMissionTrainE7CVectorbjPPS_S2_iib");

    // _ZN5CBoat14ProcessControlEv @ 0x6C180C RET
    CHook::RET("_ZN5CBoat14ProcessControlEv");

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _Z21_rwOpenGLRasterCreatePvS_i @ 0x775834 HEX \x22\x00\x80\x52
    //CHook::WriteMemory(g_libGTASA + 0x775834, (uintptr_t)"\x22\x00\x80\x52", 4);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _Z19RpMaterialSetUVAnimP10RpMaterialP15RtAnimAnimationj @ 0x732978 NOP 1
    //CHook::NOP(g_libGTASA + 0x732978, 1);

    // ต้องทำ HEX 2.11 ก่อน - ปิดไว้ เพราะ HEX/size ไม่ใช่ ARM64 instruction ตรง 4 bytes
    // _ZN9RQTexture14ConvertToRaw16EPhS0_jj15RQTextureFormat @ 0x790894 HEX \x03\x20
    //CHook::WriteMemory(g_libGTASA + 0x790894, (uintptr_t)"\x03\x20", 2);

    // ต้องทำ HEX 2.11 ก่อน - ปิดไว้ เพราะ HEX/size ไม่ใช่ ARM64 instruction ตรง 4 bytes
    // _ZN9RQTexture14ConvertToRaw16EPhS0_jj15RQTextureFormat @ 0x79089E HEX \x03\x28
    //CHook::WriteMemory(g_libGTASA + 0x79089E, (uintptr_t)"\x03\x28", 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _Z19OS_PointerGetNumberv @ 0x7D32F0 HEX \x60\x00\x80\x52
    //CHook::WriteMemory(g_libGTASA + 0x7D32F0, (uintptr_t)"\x60\x00\x80\x52", 4);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _Z17OS_PointerGetTypei @ 0x7D32FC HEX \x1F\x0C\x00\x71
    //CHook::WriteMemory(g_libGTASA + 0x7D32FC, (uintptr_t)"\x1F\x0C\x00\x71", 4);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _Z25LIB_PointerGetCoordinatesiPiS_Pf @ 0x7D7C80 HEX \x1F\x0C\x00\x71
    //CHook::WriteMemory(g_libGTASA + 0x7D7C80, (uintptr_t)"\x1F\x0C\x00\x71", 4);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _Z20LIB_PointerGetButtonii @ 0x7D7CFC HEX \x1F\x0D\x00\x71
    //CHook::WriteMemory(g_libGTASA + 0x7D7CFC, (uintptr_t)"\x1F\x0D\x00\x71", 4);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _Z19LIB_PointerGetWheeli @ 0x7D7D4C HEX \x1F\x0C\x00\x71
    //CHook::WriteMemory(g_libGTASA + 0x7D7D4C, (uintptr_t)"\x1F\x0C\x00\x71", 4);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _Z24LIB_PointerDoubleClickedii @ 0x7D7E8C HEX \x1F\x0C\x00\x71
    //CHook::WriteMemory(g_libGTASA + 0x7D7E8C, (uintptr_t)"\x1F\x0C\x00\x71", 4);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _Z14Menu_MapRenderv @ 0x71D548 NOP 1
    //CHook::NOP(g_libGTASA + 0x71D548, 1);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _Z14Menu_MapRenderv @ 0x71DA48 NOP 1
    //CHook::NOP(g_libGTASA + 0x71DA48, 1);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _Z14Menu_MapRenderv @ 0x71DAA0 NOP 2
    //CHook::NOP(g_libGTASA + 0x71DAA0, 2);

    // ซ้ำ 0x71DAA0 - ปิดไว้ เพราะซ้ำกับรายการก่อนหน้า
    // _Z14Menu_MapRenderv @ 0x71DAA0 NOP 1
    //CHook::NOP(g_libGTASA + 0x71DAA0, 1);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _Z14Menu_MapRenderv @ 0x71DAB0 NOP 1
    //CHook::NOP(g_libGTASA + 0x71DAB0, 1);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN10CStreaming29DeleteLeastUsedEntityRwObjectEbj @ 0x3B463E NOP 2
    //CHook::NOP(g_libGTASA + 0x3B463E, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN8CCarCtrl20GenerateOneRandomCarEv @ 0x3C97BA NOP 2
    //CHook::NOP(g_libGTASA + 0x3C97BA, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN11CTheScripts14StartNewScriptEPh @ 0x4121B6 NOP 2
    //CHook::NOP(g_libGTASA + 0x4121B6, 2);

    // ต้องทำ HEX 2.11 ก่อน - ปิดไว้ เพราะ HEX/size ไม่ใช่ ARM64 instruction ตรง 4 bytes
    // _ZN11CTheScripts15StartTestScriptEv @ 0x412B40 HEX \x03
    //CHook::WriteMemory(g_libGTASA + 0x412B40, (uintptr_t)"\x03", 1);

    // ต้องทำ HEX 2.11 ก่อน - ปิดไว้ เพราะ HEX/size ไม่ใช่ ARM64 instruction ตรง 4 bytes
    // _ZN10FxSystem_c6UpdateEP8RwCameraf @ 0x4E1612 HEX \x12\xE0
    //CHook::WriteMemory(g_libGTASA + 0x4E1612, (uintptr_t)"\x12\xE0", 2);

    // ต้องทำ HEX 2.11 ก่อน - ปิดไว้ เพราะ HEX/size ไม่ใช่ ARM64 instruction ตรง 4 bytes
    // _ZN10FxSystem_c6UpdateEP8RwCameraf @ 0x4E163A HEX \x12\xE0
    //CHook::WriteMemory(g_libGTASA + 0x4E163A, (uintptr_t)"\x12\xE0", 2);

    // ซ้ำ 0x4E163A - ปิดไว้ เพราะซ้ำกับรายการก่อนหน้า
    // _ZN10FxSystem_c6UpdateEP8RwCameraf @ 0x4E163A HEX \x48\x46
    //CHook::WriteMemory(g_libGTASA + 0x4E163A, (uintptr_t)"\x48\x46", 2);

    // ต้องทำ HEX 2.11 ก่อน - ปิดไว้ เพราะ HEX/size ไม่ใช่ ARM64 instruction ตรง 4 bytes
    // _ZN10FxSystem_c14GetBoundingBoxEP7FxBox_c @ 0x4E1F40 HEX \x3A\xE0
    //CHook::WriteMemory(g_libGTASA + 0x4E1F40, (uintptr_t)"\x3A\xE0", 2);

    // ต้องทำ HEX 2.11 ก่อน - ปิดไว้ เพราะ HEX/size ไม่ใช่ ARM64 instruction ตรง 4 bytes
    // _ZN10FxSystem_c14GetBoundingBoxEP7FxBox_c @ 0x4E1FB8 HEX \x3A\xE0
    //CHook::WriteMemory(g_libGTASA + 0x4E1FB8, (uintptr_t)"\x3A\xE0", 2);

    // ซ้ำ 0x4E1FB8 - ปิดไว้ เพราะซ้ำกับรายการก่อนหน้า
    // _ZN10FxSystem_c14GetBoundingBoxEP7FxBox_c @ 0x4E1FB8 HEX \x30\x46
    //CHook::WriteMemory(g_libGTASA + 0x4E1FB8, (uintptr_t)"\x30\x46", 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN15CAEAudioChannelD1Ev @ 0x3776BC NOP 1
    //CHook::NOP(g_libGTASA + 0x3776BC, 1);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN15CAEAudioChannel9SetVolumeEf @ 0x377614 NOP 1
    //CHook::NOP(g_libGTASA + 0x377614, 1);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CGame7ProcessEv @ 0x496204 HEX \x1F\x0D\x00\x71
    //CHook::WriteMemory(g_libGTASA + 0x496204, (uintptr_t)"\x1F\x0D\x00\x71", 4);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _Z11RenderSceneb @ 0x498714 NOP 1
    //CHook::NOP(g_libGTASA + 0x498714, 1);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN6CTimer6UpdateEv @ 0x4C4B2C WRITE32 0xD00010AB
    //CHook::Write32(g_libGTASA + 0x4C4B2C, 0xD00010AB);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN6CTimer6UpdateEv @ 0x4C4B38 WRITE32 0xBD41E161
    //CHook::Write32(g_libGTASA + 0x4C4B38, 0xBD41E161);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN6CRadar14DrawEntityBlipEihif @ 0x51AF8C NOP 2
    //CHook::NOP(g_libGTASA + 0x51AF8C, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN10CStreaming5Init2Ev @ 0x555934 NOP 1
    //CHook::NOP(g_libGTASA + 0x555934, 1);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN10CStreaming5Init2Ev @ 0x555938 NOP 1
    //CHook::NOP(g_libGTASA + 0x555938, 1);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN10CStreaming5Init2Ev @ 0x5559F4 NOP 1
    //CHook::NOP(g_libGTASA + 0x5559F4, 1);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZNK20CPedAttractorManager25IsPedRegisteredWithEffectEP4CPedPK9C2dEffectPK7CEntity @ 0x5943DC HEX \x00\x20\x70\x47
    //CHook::WriteMemory(g_libGTASA + 0x5943DC, (uintptr_t)"\x00\x20\x70\x47", 4);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN10CPlayerPed17ClearWeaponTargetEv @ 0x5B7C24 NOP 1
    //CHook::NOP(g_libGTASA + 0x5B7C24, 1);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN11CAutomobile14ProcessControlEv @ 0x6A782C NOP 2
    //CHook::NOP(g_libGTASA + 0x6A782C, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CBike14ProcessControlEv @ 0x6B69A8 NOP 1
    //CHook::NOP(g_libGTASA + 0x6B69A8, 1);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN5CBoat14ProcessControlEv @ 0x6C1830 NOP 2
    //CHook::NOP(g_libGTASA + 0x6C1830, 2);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN8CVehicle12RemoveDriverEb @ 0x6DC0DC NOP 1
    //CHook::NOP(g_libGTASA + 0x6DC0DC, 1);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN8CVehicle12RemoveDriverEb @ 0x6DC128 NOP 1
    //CHook::NOP(g_libGTASA + 0x6DC128, 1);

    // ต้องทำ HEX 2.11 ก่อน - ปิดไว้ เพราะ HEX/size ไม่ใช่ ARM64 instruction ตรง 4 bytes
    // _ZN11CWaterLevel27CalculateWavesForCoordinateEiiffPfS0_S0_P7CVector @ 0x6F182C HEX \x01
    //CHook::WriteMemory(g_libGTASA + 0x6F182C, (uintptr_t)"\x01", 1);

    // _ZN10CPlayerPed22FindWeaponLockOnTargetEv @ 0x5B93C8 RET
    CHook::RET("_ZN10CPlayerPed22FindWeaponLockOnTargetEv");

    // _ZN10CPlayerPed26FindNextWeaponLockOnTargetEP7CEntityb @ 0x5BA5A0 RET
    CHook::RET("_ZN10CPlayerPed26FindNextWeaponLockOnTargetEP7CEntityb");

    // _ZN4CPed21SetWeaponLockOnTargetEP7CEntity @ 0x591AE8 RET
    CHook::RET("_ZN4CPed21SetWeaponLockOnTargetEP7CEntity");

    // _ZN6CTrain10InitTrainsEv @ 0x6D3D24 RET
    CHook::RET("_ZN6CTrain10InitTrainsEv");

    // _ZN8CClothes4InitEv @ 0x53ED50 RET
    CHook::RET("_ZN8CClothes4InitEv");

    // _ZN8CClothes13RebuildPlayerEP10CPlayerPedb @ 0x53E728 RET
    CHook::RET("_ZN8CClothes13RebuildPlayerEP10CPlayerPedb");

    // _ZNK35CPedGroupDefaultTaskAllocatorRandom20AllocateDefaultTasksEP9CPedGroupP4CPed @ 0x59F7E4 RET
    CHook::RET("_ZNK35CPedGroupDefaultTaskAllocatorRandom20AllocateDefaultTasksEP9CPedGroupP4CPed");

    // _ZN6CGlass4InitEv @ 0x5D8464 RET
    CHook::RET("_ZN6CGlass4InitEv");

    // _ZN8CGarages17Init_AfterRestartEv @ 0x3F2160 RET
    CHook::RET("_ZN8CGarages17Init_AfterRestartEv");

    // _ZN6CGangs10InitialiseEv @ 0x586B8C RET
    CHook::RET("_ZN6CGangs10InitialiseEv");

    // _ZN5CHeli9InitHelisEv @ 0x6C97AC RET
    CHook::RET("_ZN5CHeli9InitHelisEv");

    // _ZN17CEntryExitManager22PostEntryExitsCreationEv @ 0x3E9B34 RET
    CHook::RET("_ZN17CEntryExitManager22PostEntryExitsCreationEv");

    // _ZN17CVehicleModelInfo17SetCarCustomPlateEv @ 0x534078 RET
    CHook::RET("_ZN17CVehicleModelInfo17SetCarCustomPlateEv");

    // _Z16SaveGameForPause10eSaveTypesPc @ 0x368C74 RET
    CHook::RET("_Z16SaveGameForPause10eSaveTypesPc");

    // _ZN12CAudioEngine16StartLoadingTuneEv @ 0x3A9F20 RET
    CHook::RET("_ZN12CAudioEngine16StartLoadingTuneEv");

    // _ZN18CMotionBlurStreaks6UpdateEv @ 0x5EEAA4 RET
    CHook::RET("_ZN18CMotionBlurStreaks6UpdateEv");

    // _ZN7CCamera16RenderMotionBlurEv @ 0x47540C RET
    CHook::RET("_ZN7CCamera16RenderMotionBlurEv");

    // _ZN30CWidgetRegionSteeringSelection4DrawEv @ 0x34C19C RET
    CHook::RET("_ZN30CWidgetRegionSteeringSelection4DrawEv");

    // _ZN23CTaskSimplePlayerOnFoot18PlayIdleAnimationsEP10CPlayerPed @ 0x68AA0C RET
    CHook::RET("_ZN23CTaskSimplePlayerOnFoot18PlayIdleAnimationsEP10CPlayerPed");

    // _ZN13CCarEnterExit17SetPedInCarDirectEP4CPedP8CVehicleib @ 0x650350 RET
    CHook::RET("_ZN13CCarEnterExit17SetPedInCarDirectEP4CPedP8CVehicleib");

    // _ZN11CAutomobile35CustomCarPlate_BeforeRenderingStartEP17CVehicleModelInfo @ 0x6AFEE0 RET
    CHook::RET("_ZN11CAutomobile35CustomCarPlate_BeforeRenderingStartEP17CVehicleModelInfo");

    // _ZN11CAutomobile33CustomCarPlate_AfterRenderingStopEP17CVehicleModelInfo @ 0x6AFF10 RET
    CHook::RET("_ZN11CAutomobile33CustomCarPlate_AfterRenderingStopEP17CVehicleModelInfo");

    // _ZN7CEntity23PreRenderForGlassWindowEv @ 0x48D1F8 RET
    CHook::RET("_ZN7CEntity23PreRenderForGlassWindowEv");

    // _ZN4CHud23DrawBustedWastedMessageEv @ 0x513270 RET
    CHook::RET("_ZN4CHud23DrawBustedWastedMessageEv");

    // _ZN6CCheat13ProcessCheatsEv @ 0x3E27A8 RET
    CHook::RET("_ZN6CCheat13ProcessCheatsEv");

    // _ZN6CCheat12WeaponCheat3Ev @ 0x3DF1FC RET
    CHook::RET("_ZN6CCheat12WeaponCheat3Ev");

    // _ZN8CCarCtrl31GenerateOneEmergencyServicesCarEj7CVector @ 0x3DDAC0 RET
    CHook::RET("_ZN8CCarCtrl31GenerateOneEmergencyServicesCarEj7CVector");

    // _ZN7CDarkel26RegisterCarBlownUpByPlayerEP8CVehiclei @ 0x3E73F8 RET
    CHook::RET("_ZN7CDarkel26RegisterCarBlownUpByPlayerEP8CVehiclei");

    // _ZN7CDarkel25ResetModelsKilledByPlayerEi @ 0x3E79D8 RET
    CHook::RET("_ZN7CDarkel25ResetModelsKilledByPlayerEi");

    // _ZN7CDarkel25QueryModelsKilledByPlayerEii @ 0x3E7A00 RET
    CHook::RET("_ZN7CDarkel25QueryModelsKilledByPlayerEii");

    // _ZN7CDarkel27FindTotalPedsKilledByPlayerEi @ 0x3E7A14 RET
    CHook::RET("_ZN7CDarkel27FindTotalPedsKilledByPlayerEi");

    // _ZN7CDarkel20RegisterKillByPlayerEPK4CPed11eWeaponTypebi @ 0x3E6F04 RET
    CHook::RET("_ZN7CDarkel20RegisterKillByPlayerEPK4CPed11eWeaponTypebi");

    // _ZN10CPlayerPed14AnnoyPlayerPedEb @ 0x5BC7C0 RET
    CHook::RET("_ZN10CPlayerPed14AnnoyPlayerPedEb");

    // _ZN11CPopulation15AddToPopulationEffff @ 0x5BFEB8 RET
    CHook::RET("_ZN11CPopulation15AddToPopulationEffff");

    // _ZN23CAEPedSpeechAudioEntity11AddSayEventEisjfhhh @ 0x38179C RET
    CHook::RET("_ZN23CAEPedSpeechAudioEntity11AddSayEventEisjfhhh");

    // _ZN4CPed31RemoveWeaponWhenEnteringVehicleEi @ 0x58DF88 RET
    CHook::RET("_ZN4CPed31RemoveWeaponWhenEnteringVehicleEi");

    // _ZN20CAERadioTrackManager7ServiceEi @ 0x387014 RET
    CHook::RET("_ZN20CAERadioTrackManager7ServiceEi");

    // _ZN14CLoadingScreen15DisplayPCScreenEv @ 0x514AA8 RET
    CHook::RET("_ZN14CLoadingScreen15DisplayPCScreenEv");

    // _ZN10CSkidmarks6UpdateEv @ 0x5EC704 RET
    CHook::RET("_ZN10CSkidmarks6UpdateEv");

    // _ZN10CSkidmarks6RenderEv @ 0x5EC7BC RET
    CHook::RET("_ZN10CSkidmarks6RenderEv");

    // _ZN14SurfaceInfos_c16CreatesWheelDustEj @ 0x4C2008 RET
    CHook::RET("_ZN14SurfaceInfos_c16CreatesWheelDustEj");

    // _ZN14SurfaceInfos_c17CreatesWheelSprayEj @ 0x4C2030 RET
    CHook::RET("_ZN14SurfaceInfos_c17CreatesWheelSprayEj");

    // _ZN4Fx_c12AddWheelDustEP8CVehicle7CVectorhf @ 0x4D74FC RET
    CHook::RET("_ZN4Fx_c12AddWheelDustEP8CVehicle7CVectorhf");

    // _ZN4Fx_c13AddWheelSprayEP8CVehicle7CVectorhhf @ 0x4D65B4 RET
    CHook::RET("_ZN4Fx_c13AddWheelSprayEP8CVehicle7CVectorhhf");

    // _ZN10CGameLogic43SetPlayerWantedLevelForForbiddenTerritoriesEb @ 0x3EC960 RET
    CHook::RET("_ZN10CGameLogic43SetPlayerWantedLevelForForbiddenTerritoriesEb");

    // _ZN7CWanted14ReportCrimeNowE10eCrimeTypeRK7CVectorb @ 0x4C610C RET
    CHook::RET("_ZN7CWanted14ReportCrimeNowE10eCrimeTypeRK7CVectorb");

    // _ZN8CMirrors16BeforeMainRenderEv @ 0x5F3858 RET
    CHook::RET("_ZN8CMirrors16BeforeMainRenderEv");

    // _ZN10CPedGroups7ProcessEv @ 0x5A6438 RET
    CHook::RET("_ZN10CPedGroups7ProcessEv");

    // _ZN21CPedGroupIntelligence7ProcessEv @ 0x5A19F0 RET
    CHook::RET("_ZN21CPedGroupIntelligence7ProcessEv");

    // _ZN19CPedGroupMembership9SetLeaderEP4CPed @ 0x59E238 RET
    CHook::RET("_ZN19CPedGroupMembership9SetLeaderEP4CPed");

    // _ZN21CPedGroupIntelligence5FlushEv @ 0x59FD58 RET
    CHook::RET("_ZN21CPedGroupIntelligence5FlushEv");

    // RenderQueue 2.11 @ 0x78C5F0 = STR XZR, ไม่ใช่ old MOV buffer size
    // _ZN11RenderQueueC1Ev old +0x34 maps to 0x78C5F0 แต่ semantic ไม่ตรง
    // _ZN11RenderQueueC1Ev 2.11 buffer size อยู่ที่ 0x78C608
    // _ZN11RenderQueueC1Ev @ 0x78C5F0 HEX \x15\x80\xA0\x52
    //CHook::WriteMemory(g_libGTASA + 0x78C5F0, (uintptr_t)"\x15\x80\xA0\x52", 4);

    // ซ้ำ 0x78C5F0 - ปิดไว้ เพราะซ้ำกับรายการก่อนหน้า
    // _ZN11RenderQueueC1Ev @ 0x78C5F0 HEX \xF5\x03\x08\x32
    //CHook::WriteMemory(g_libGTASA + 0x78C5F0, (uintptr_t)"\xF5\x03\x08\x32", 4);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN6CRadar14DrawEntityBlipEihif @ 0x51AA50 HEX \x22\x00\x00\x14
    //CHook::WriteMemory(g_libGTASA + 0x51AA50, (uintptr_t)"\x22\x00\x00\x14", 4);

    // ต้องทำค่า/count/HEX จาก 2.11 จริงก่อน - ปิดไว้ ไม่ใช้ค่าจาก 1.08/2.0/2.10
    // _ZN6CRadar14DrawEntityBlipEihif @ 0x51AAD8 HEX \x22\x00\x00\x14
    //CHook::WriteMemory(g_libGTASA + 0x51AAD8, (uintptr_t)"\x22\x00\x00\x14", 4);

    // ซ้ำ 0x51AAD8 - ปิดไว้ เพราะซ้ำกับรายการก่อนหน้า
    // _ZN6CRadar14DrawEntityBlipEihif @ 0x51AAD8 HEX \xE1\x03\x16\x2A
    //CHook::WriteMemory(g_libGTASA + 0x51AAD8, (uintptr_t)"\xE1\x03\x16\x2A", 4);

}
void ApplyMappedLegacyPatchBacklog_1_08_Disabled()
{
#if 0
    // 1.08 only: no 2.11 map or unsafe old-version bytes
    // 1.08 0x1200 0x1200 HEX \xb3\xf5\x90\x5f // no 2.11 map
    // 1.08 0x1200 0x1200 HEX \xb3\xf5\x90\x5f // no 2.11 map
    // 1.08 0x1400 0x1400 HEX \x4f\xf4\xa0\x52 // no 2.11 map
    // 1.08 _Z21_rwOpenGLRasterCreatePvS_i 0x1859FC HEX \x01\x22 // ARM32/Thumb bytes
    // 1.08 _Z21_rwOpenGLRasterCreatePvS_i 0x1859FC HEX \x01\x22 // ARM32/Thumb bytes
    // 1.08 _Z21_rwOpenGLRasterCreatePvS_i 0x1859FC HEX \x01\x22 // ARM32/Thumb bytes
    // 1.08 _ZN11RenderQueueC1Ev 0x1A7ECE HEX \x4F\xF0\x01\x00\x00\x46 // ARM32/Thumb bytes
    // 1.08 _ZN11RenderQueueC1Ev 0x1A7EF2 HEX \x4F\xF4\x00\x10\x4F\xF4\x80\x00 // ARM32/Thumb bytes
    // 1.08 _ZN11RenderQueueC1Ev 0x1A7F32 HEX \x4F\xF4\x00\x10\x4F\xF4\x80\x00 // ARM32/Thumb bytes
    // 1.08 _ZN22TextureDatabaseRuntime15LoadFullTextureEj 0x1BDD4A HEX \x10\x46\xA2\xF1\x04\x0B // ARM32/Thumb bytes
    // 1.08 _Z18RpClumpStreamWriteP7RpClumpP8RwStream 0x1E16DC // ARM32/Thumb bytes
    // 1.08 _Z18RpClumpStreamWriteP7RpClumpP8RwStream 0x1E16DC // unsupported
    // 1.08 _Z18RpClumpStreamWriteP7RpClumpP8RwStream 0x1E1738 // ARM32/Thumb bytes
    // 1.08 _Z18RpClumpStreamWriteP7RpClumpP8RwStream 0x1E1738 // unsupported
    // 1.08 _Z19OS_PointerGetNumberv 0x238232 HEX \x03\x20 // ARM32/Thumb bytes
    // 1.08 _ZN10MobileMenu6UpdateEv 0x25C522 HEX \x02\x2C // ARM32/Thumb bytes
    // 1.08 _ZN13DisplayScreenC1Ev 0x2661DA // no 2.11 map
    // 1.08 _ZN13CWidgetButton6UpdateEv 0x274AB4 HEX \x00\x46 // no 2.11 map
    // 1.08 _ZN17CWidgetPlayerInfo14RenderArmorBarEif 0x27D884 // unsupported
    // 1.08 _ZN17CWidgetPlayerInfo14RenderArmorBarEif 0x27D884 // no value
    // 1.08 _ZN17CWidgetPlayerInfo14RenderArmorBarEif 0x27D884 // ARM32/Thumb bytes
    // 1.08 _ZN17CWidgetPlayerInfo14RenderArmorBarEif 0x27D884 // unsupported
    // 1.08 _ZN17CWidgetPlayerInfo14RenderArmorBarEif 0x27D884 // no value
    // 1.08 _ZN17CWidgetPlayerInfo10DrawWantedEv 0x27D8D0 HEX \x4F\xF0\x00\x08 // ARM32/Thumb bytes
    // 1.08 _ZN17CWidgetPlayerInfo10DrawWantedEv 0x27D8D0 HEX \x4F\xF0\x00\x08 // ARM32/Thumb bytes
    // 1.08 _ZN17CWidgetPlayerInfo10DrawWantedEv 0x27D8D0 HEX \x4F\xF0\x00\x08 // ARM32/Thumb bytes
    // 1.08 _ZN30CWidgetRegionSteeringSelection4DrawEv 0x284BB8 HEX \xF7\x46 // no 2.11 map
    // 1.08 _ZN30CWidgetRegionSteeringSelection4DrawEv 0x284BB8 // no 2.11 map
    // 1.08 _ZN30CWidgetRegionSteeringSelection4DrawEv 0x284BB8 // no 2.11 map
    // 1.08 _ZN10CStreaming19RemoveLoadedVehicleEv 0x293218 HEX \x01\x20\x70\x47 // ARM32/Thumb bytes
    // 1.08 _ZN10CCollision4InitEv 0x29554A HEX \x4f\xf4\x61\x60 // ARM32/Thumb bytes
    // 1.08 _ZN10CCollision4InitEv 0x295556 HEX \x4f\xf4\x5b\x62 // ARM32/Thumb bytes
    // 1.08 _ZN8CCarCtrl31GenerateOneEmergencyServicesCarEj7CVector 0x2B055C HEX \xF7\x46 // no 2.11 map
    // 1.08 _ZN8CCarCtrl31GenerateOneEmergencyServicesCarEj7CVector 0x2B055C // no 2.11 map
    // 1.08 _ZN8CCarCtrl18GenerateRandomCarsEv 0x2B5C24 // ARM32/Thumb bytes
    // 1.08 _ZN6CCheat12WeaponCheat4Ev 0x2BA68C HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN6CCheat12WeaponCheat1Ev 0x2BA710 HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN6CCheat12WeaponCheat2Ev 0x2BA92C HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN6CCheat12WeaponCheat3Ev 0x2BAB20 HEX \xF7\x46 // no 2.11 map
    // 1.08 _ZN6CCheat12WeaponCheat3Ev 0x2BAB20 // no 2.11 map
    // 1.08 _ZN6CCheat16AddToCheatStringEc 0x2BC08C HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN6CCheat8DoCheatsEv 0x2BC24C HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN6CCheat16ProcessCheatMenuEv 0x2BCD0C HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN6CCheat13ProcessCheatsEv 0x2BCDB4 HEX \xF7\x46 // no 2.11 map
    // 1.08 _ZN6CCheat13ProcessCheatsEv 0x2BCDB4 // no 2.11 map
    // 1.08 _ZN10CEntryExit19GenerateAmbientPedsERK7CVector 0x2C1CB0 HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN10CEntryExit19GenerateAmbientPedsERK7CVector 0x2C1CB0 // ARM32/Thumb bytes
    // 1.08 _ZN10CEntryExit18TransitionFinishedEP4CPed 0x2C2C22 // unsupported
    // 1.08 _ZN10CEntryExit18TransitionFinishedEP4CPed 0x2C2C22 // ARM32/Thumb bytes
    // 1.08 _ZN10CGameLogic17IsCoopGameGoingOnEv 0x2C3868 HEX \x00\x20\x70\x47 // ARM32/Thumb bytes
    // 1.08 _ZN10CGameLogic36RestorePlayerStuffDuringResurrectionEP10CPlayerPed7CVectorf 0x2C3EA2 // no 2.11 map
    // 1.08 _ZN10CGameLogic43SetPlayerWantedLevelForForbiddenTerritoriesEb 0x2C4694 // no 2.11 map
    // 1.08 _ZN7CPickup29IsPickUpCloseEnoughForObjectsEv 0x2D6CC8 // unsupported
    // 1.08 _ZN7CPickup29IsPickUpCloseEnoughForObjectsEv 0x2D6CC8 // no value
    // 1.08 _ZN17CVehicleRecording4LoadEP8RwStreamii 0x2DC8E0 HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN17CVehicleRecording4LoadEP8RwStreamii 0x2DC8E0 // ARM32/Thumb bytes
    // 1.08 _ZN11CRoadBlocks18GenerateRoadBlocksEv 0x2DE734 HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN14CRunningScript25ProcessCommands1800To1899Ei 0x2E82CC HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN14CRunningScript23ProcessCommands300To399Ei 0x2F7B68 // no 2.11 map
    // 1.08 _ZN14CRunningScript23ProcessCommands300To399Ei 0x2F7B68 // no 2.11 map
    // 1.08 _ZN14CRunningScript23ProcessCommands300To399Ei 0x2F7B68 // no 2.11 map
    // 1.08 _ZN14CRunningScript23ProcessCommands300To399Ei 0x2F7B68 // no 2.11 map
    // 1.08 _ZN14CRunningScript23ProcessCommands300To399Ei 0x2F7B6B // no 2.11 map
    // 1.08 _ZN14CRunningScript23ProcessCommands300To399Ei 0x2F81BC HEX \x95\xF8\x81\x48 // no 2.11 map
    // 1.08 _ZN14CRunningScript23ProcessCommands800To899Ei 0x2FEE76 // no 2.11 map
    // 1.08 0x3 0x3 HEX \x4f\xf4\xd6\x40\xc0\xf2\x03\x00 // no 2.11 map
    // 1.08 0x30 0x30 HEX \x4C\xF6\xD0\x70\xC0\xF2\x17\x00 // no 2.11 map
    // 1.08 _ZN10FxSystem_c11AddParticleEP5RwV3dS1_fP11FxPrtMult_cfffh 0x320F2C // no 2.11 map
    // 1.08 _ZN13CEventHandler31ComputeVehicleCollisionResponseEP6CEventP5CTaskS3_ 0x32C488 // no 2.11 map
    // 1.08 _ZN13CEventHandler37ComputePlayerCollisionWithPedResponseEP6CEventP5CTaskS3_ 0x32DF94 // no 2.11 map
    // 1.08 _ZN13CEventHandler37ComputePlayerCollisionWithPedResponseEP6CEventP5CTaskS3_ 0x32E05E // no 2.11 map
    // 1.08 _ZN13CEventHandler37ComputePlayerCollisionWithPedResponseEP6CEventP5CTaskS3_ 0x32E160 // no 2.11 map
    // 1.08 _ZN13CEventHandler37ComputePlayerCollisionWithPedResponseEP6CEventP5CTaskS3_ 0x32E1F2 // no 2.11 map
    // 1.08 _ZN13CEventHandler37ComputePlayerCollisionWithPedResponseEP6CEventP5CTaskS3_ 0x32E292 // no 2.11 map
    // 1.08 _ZN13CEventHandler40ComputeVehiclePotentialCollisionResponseEP6CEventP5CTaskS3_ 0x32EFD0 // no 2.11 map
    // 1.08 _ZN13CEventHandler24ComputeEventResponseTaskEP6CEventP5CTask 0x3342CA // no 2.11 map
    // 1.08 _ZN14CBaseModelInfoC2Ev 0x33559C // no value
    // 1.08 _ZN14CBaseModelInfoC2Ev 0x33559C // ARM32/Thumb bytes
    // 1.08 _ZN10CModelInfo12GetModelInfoEPKcPi 0x336110 // ARM32/Thumb bytes
    // 1.08 _ZN10CModelInfo15AddVehicleModelEi 0x336618 HEX \x4F\xF4\x6A\x71 // ARM32/Thumb bytes
    // 1.08 _ZN10CModelInfo15AddVehicleModelEi 0x33661C HEX \x1A\x4B // ARM32/Thumb bytes
    // 1.08 _ZN26CAEGlobalWeaponAudioEntity21ServiceAmbientGunFireEv 0x3474E0 HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN26CAEGlobalWeaponAudioEntity21ServiceAmbientGunFireEv 0x3474E0 // ARM32/Thumb bytes
    // 1.08 0x3500 0x3500 HEX \x4f\xf4\x54\x50\xc0\xf2\x0c\x00 // no 2.11 map
    // 1.08 _ZN20CAERadioTrackManager10StartRadioEaafh 0x351700 HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN7CCamera10CamControlEv 0x385D6A // no value
    // 1.08 _ZN7CCamera10CamControlEv 0x385D6A // unsupported
    // 1.08 _ZN7CEntity23PreRenderForGlassWindowEv 0x392A98 HEX \xF7\x46 // no 2.11 map
    // 1.08 _ZN7CEntity23PreRenderForGlassWindowEv 0x392A98 // no 2.11 map
    // 1.08 _ZN5CGame22InitialiseOnceBeforeRWEv 0x3981EC HEX \x06\x20 // ARM32/Thumb bytes
    // 1.08 _ZN5CGame22InitialiseOnceBeforeRWEv 0x3981EC HEX \x06\x20 // ARM32/Thumb bytes
    // 1.08 _ZN5CGame22InitialiseOnceBeforeRWEv 0x3981EC HEX \x06\x20 // ARM32/Thumb bytes
    // 1.08 _ZN5CGame7ProcessEv 0x398A34 // unsupported
    // 1.08 _ZN5CGame7ProcessEv 0x398A34 // ARM32/Thumb bytes
    // 1.08 _ZN5CGame7ProcessEv 0x398A3A // unsupported
    // 1.08 _ZN5CGame7ProcessEv 0x398A3A // ARM32/Thumb bytes
    // 1.08 _Z4IdlePvb 0x39B2C4 // unsupported
    // 1.08 _Z4IdlePvb 0x39B2C4 // ARM32/Thumb bytes
    // 1.08 _ZN10CPlaceable15InitMatrixArrayEv 0x3ABB0A HEX \x4F\xF4\x7A\x61 // ARM32/Thumb bytes
    // 1.08 _ZN11CPlayerInfo17FindObjectToStealEP4CPed 0x3AC114 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF1B0 HEX \x48\xf2\xa0\x66 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF1BC HEX \x4f\xf4\x54\x50\xc0\xf2\x0c\x00 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF1CA HEX \x48\xf2\xa0\x60\xc0\xf2\x01\x00 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF1D6 HEX \x48\xf2\xa0\x62 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF21C HEX \x4f\xf4\xee\x40\xc0\xf2\x01\x00 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF21C HEX \x4F\xF4\x00\x30 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF22A HEX \x41\xf6\x40\x70 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF232 HEX \x41\xf6\x40\x72 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF27A HEX \x4f\xf4\xc8\x30 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF27A HEX \x4f\xf4\x20\x40 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF284 HEX \x4f\xf4\xa0\x50 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF284 HEX \x4f\xf4\x00\x60 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF28C HEX \x4f\xf4\xa0\x52 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF28C HEX \x4f\xf4\x00\x62 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF2BA HEX \xb3\xf5\xa0\x5f // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF2BA HEX \xb3\xf5\x00\x6f // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF2D0 HEX \x45\xF6\xC8\x60\xC0\xF2\x06\x00 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF2DE HEX \xD2\x20 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF2E4 HEX \xD2\x22 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF310 HEX \xD2\x2B // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF378 HEX \x4F\xF4\x90\x40\xC0\xF2\x19\x00 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF386 HEX \x47\xF2\x91\x30 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF38E HEX \x47\xF2\x91\x32 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF3D6 HEX \x4f\xf4\x7e\x40\xc0\xf2\x12\x00 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF3E4 HEX \x4f\xf4\x3b\x60 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF3EC HEX \x4f\xf4\x3b\x62 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF41A HEX \xb3\xf5\x3b\x6f // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF430 HEX \x4f\xf4\xd6\x40\xc0\xf2\x03\x00 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF43E HEX \x40\xf6\xa0\x70 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF446 HEX \x40\xf6\xa0\x72 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF48E HEX \x4C\xF6\xD0\x70\xC0\xF2\x17\x00 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF49C HEX \x47\xF6\xFF\x60 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF4A4 HEX \x47\xF6\xFF\x62 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF4EA HEX \x4F\xF4\x40\x30 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF4F4 HEX \x4F\xF4\xC0\x60 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF4FC HEX \x4F\xF4\xC0\x62 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF52A HEX \xB3\xF5\xC0\x6F // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF7E6 HEX \x42\xF2\xB0\x00\xC0\xF2\x02\x00\x00\x46 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF7F6 HEX \xD2\x20 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF7FC HEX \xD2\x22 // ARM32/Thumb bytes
    // 1.08 _ZN6CPools10InitialiseEv 0x3AF824 HEX \xD2\x2B // ARM32/Thumb bytes
    // 1.08 _ZN6CRopes6UpdateEv 0x3B67F8 HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN6CStats23GetFatAndMuscleModifierE17eStatModAbilities 0x3BAC68 // no 2.11 map
    // 1.08 _ZN6CStats23GetFatAndMuscleModifierE17eStatModAbilities 0x3BAC68 // no 2.11 map
    // 1.08 _ZN6CStats23GetFatAndMuscleModifierE17eStatModAbilities 0x3BAC68 // no 2.11 map
    // 1.08 _ZN6CStats23GetFatAndMuscleModifierE17eStatModAbilities 0x3BAC68 // no 2.11 map
    // 1.08 _ZN6CStats23GetFatAndMuscleModifierE17eStatModAbilities 0x3BAC68 // no 2.11 map
    // 1.08 _ZN10CPlaceName7ProcessEv 0x3BF8B4 HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN6CWorld7ProcessEv 0x3C5B58 HEX \x02\x21 // ARM32/Thumb bytes
    // 1.08 _ZN6CWorld7ProcessEv 0x3C5B58 HEX \x02\x21 // ARM32/Thumb bytes
    // 1.08 _ZN4CHud24SetHelpMessageStatUpdateEhtff 0x3D42A8 HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN4CHud24SetHelpMessageStatUpdateEhtff 0x3D42A8 // ARM32/Thumb bytes
    // 1.08 _ZN4CHud15DrawVehicleNameEv 0x3D541C HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN4CHud15DrawVehicleNameEv 0x3D541C // ARM32/Thumb bytes
    // 1.08 _ZN4CHud23DrawBustedWastedMessageEv 0x3D62FC HEX \xF7\x46 // no 2.11 map
    // 1.08 _ZN4CHud23DrawBustedWastedMessageEv 0x3D62FC // no 2.11 map
    // 1.08 _ZN4CHud23DrawBustedWastedMessageEv 0x3D62FC // no 2.11 map
    // 1.08 _ZN6CRadar10DrawLegendEiii 0x3DA500 HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN6CRadar19AddBlipToLegendListEhi 0x3DBB30 HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN6CRadar13DrawCoordBlipEihif 0x3DCA90 // no 2.11 map
    // 1.08 _ZN6CRadar13DrawCoordBlipEihif 0x3DCA90 // no 2.11 map
    // 1.08 _ZN6CRadar13DrawCoordBlipEihif 0x3DCA90 // no 2.11 map
    // 1.08 _ZN6CRadar14DrawEntityBlipEihif 0x3DD4A4 // unsupported
    // 1.08 _ZN6CRadar14DrawEntityBlipEihif 0x3DD4A4 // ARM32/Thumb bytes
    // 1.08 _ZN6CRadar13DrawRadarMaskEv 0x3DED84 // no 2.11 map
    // 1.08 _ZN10Interior_c10AddPickupsEv 0x3E17F0 HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN10Interior_c10AddPickupsEv 0x3E17F0 // ARM32/Thumb bytes
    // 1.08 _ZN10Interior_c4InitEP5RwV3d 0x3E1A2C HEX \x67\xE0 // no 2.11 map
    // 1.08 _ZN10Interior_c4InitEP5RwV3d 0x3E1AF0 // no 2.11 map
    // 1.08 _ZN15InteriorGroup_c9SetupPedsEv 0x3E3F38 HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN15InteriorGroup_c4ExitEv 0x3E42E0 HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN15InteriorGroup_c4ExitEv 0x3E42E0 // ARM32/Thumb bytes
    // 1.08 _ZN15InteriorGroup_c5SetupEv 0x3E4490 HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN11CFileLoader10LoadPickupEPKc 0x401BAC // ARM32/Thumb bytes
    // 1.08 _ZN11CFileLoader10LoadPickupEPKc 0x401BAC HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN17CVehicleModelInfo15SetupCommonDataEv 0x405338 HEX \x4F\xF6\xC0\x50 // ARM32/Thumb bytes
    // 1.08 _ZN17CVehicleModelInfo15SetupCommonDataEv 0x405338 HEX \x4F\xF6\xC0\x50 // ARM32/Thumb bytes
    // 1.08 _ZN17CVehicleModelInfo15SetupCommonDataEv 0x405338 HEX \x4F\xF6\xC0\x50 // ARM32/Thumb bytes
    // 1.08 _ZN17CVehicleModelInfo15SetupCommonDataEv 0x405342 HEX \x50\x20 // ARM32/Thumb bytes
    // 1.08 _ZN17CVehicleModelInfo15SetupCommonDataEv 0x405342 HEX \x50\x20 // ARM32/Thumb bytes
    // 1.08 _ZN17CVehicleModelInfo15SetupCommonDataEv 0x405342 HEX \x50\x20 // ARM32/Thumb bytes
    // 1.08 _ZN17CVehicleModelInfo15SetupCommonDataEv 0x405348 HEX \x50\x22 // ARM32/Thumb bytes
    // 1.08 _ZN17CVehicleModelInfo15SetupCommonDataEv 0x405348 HEX \x50\x22 // ARM32/Thumb bytes
    // 1.08 _ZN17CVehicleModelInfo15SetupCommonDataEv 0x405348 HEX \x50\x22 // ARM32/Thumb bytes
    // 1.08 _ZN17CVehicleModelInfo15SetupCommonDataEv 0x405374 HEX \x50\x2B // ARM32/Thumb bytes
    // 1.08 _ZN17CVehicleModelInfo15SetupCommonDataEv 0x405374 HEX \x50\x2B // ARM32/Thumb bytes
    // 1.08 _ZN17CVehicleModelInfo15SetupCommonDataEv 0x405374 HEX \x50\x2B // ARM32/Thumb bytes
    // 1.08 _ZN4CPed31RemoveWeaponWhenEnteringVehicleEi 0x434D94 // no 2.11 map
    // 1.08 _ZN4CPed31RemoveWeaponWhenEnteringVehicleEi 0x434D94 // no 2.11 map
    // 1.08 _ZN4CPed31RemoveWeaponWhenEnteringVehicleEi 0x434D94 // no 2.11 map
    // 1.08 _ZN4CPed21SetWeaponLockOnTargetEP7CEntity 0x438DB4 HEX \x00\x20\xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN4CPed3SayEtjfhhh 0x43E288 // no 2.11 map
    // 1.08 0x43F30 0x43F30 HEX \x45\xF6\xC8\x60\xC0\xF2\x06\x00 // no 2.11 map
    // 1.08 _ZN10CPlayerPed17ProcessAnimGroupsEv 0x454950 // unsupported
    // 1.08 _ZN10CPlayerPed17ProcessAnimGroupsEv 0x454950 // ARM32/Thumb bytes
    // 1.08 _ZN10CPlayerPed22FindWeaponLockOnTargetEv 0x4568B0 HEX \x00\x20\xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN10CPlayerPed15SetInitialStateEb 0x458D68 HEX \x00\x46\x00\x46 // ARM32/Thumb bytes
    // 1.08 _ZN10CPlayerPed26FindNextWeaponLockOnTargetEP7CEntityb 0x4590E4 HEX \x00\x20\xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN11CPopulation6AddPedE8ePedTypejRK7CVectorb 0x45F1A4 // ARM32/Thumb bytes
    // 1.08 _ZN11CPopulation15AddToPopulationEffff 0x45FC20 HEX \x4F\xF0\x00\x00\xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN8C_PcSave8SaveSlotEab 0x463870 HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _Z12RsInitializev 0x463FE8 // ARM32/Thumb bytes
    // 1.08 _Z12RsInitializev 0x463FE8 HEX \x5A // ARM32/Thumb bytes
    // 1.08 _Z12RsInitializev 0x463FE8 HEX \x5A // ARM32/Thumb bytes
    // 1.08 _ZN26CTaskComplexUseMobilePhone16RemovePhoneModelEP4CPed 0x47DA2E // unsupported
    // 1.08 _ZN26CTaskComplexUseMobilePhone14ControlSubTaskEP4CPed 0x47DBC8 // unsupported
    // 1.08 _ZN33CTaskComplexEnterCarAsDriverTimedC1EP8CVehiclei 0x483126 // no 2.11 map
    // 1.08 _ZN13CCarEnterExit17SetPedInCarDirectEP4CPedP8CVehicleib 0x494FE4 HEX \xF7\x46 // no 2.11 map
    // 1.08 _ZN13CCarEnterExit17SetPedInCarDirectEP4CPedP8CVehicleib 0x494FE4 // no 2.11 map
    // 1.08 _ZN13CCarEnterExit17SetPedInCarDirectEP4CPedP8CVehicleib 0x494FE4 // no 2.11 map
    // 1.08 _ZN23CTaskSimplePlayerOnFoot18PlayIdleAnimationsEP10CPlayerPed 0x4BDB18 HEX \x70\x47 // no 2.11 map
    // 1.08 _ZN23CTaskSimplePlayerOnFoot18PlayIdleAnimationsEP10CPlayerPed 0x4BDB18 // no 2.11 map
    // 1.08 _ZN23CTaskSimplePlayerOnFoot18PlayIdleAnimationsEP10CPlayerPed 0x4BDB18 // no 2.11 map
    // 1.08 _ZN11CAutomobile35CustomCarPlate_BeforeRenderingStartEP17CVehicleModelInfo 0x4DD00C // no 2.11 map
    // 1.08 _ZN11CAutomobile33CustomCarPlate_AfterRenderingStopEP17CVehicleModelInfo 0x4DD038 // no 2.11 map
    // 1.08 _ZN11CAutomobile14ProcessControlEv 0x4E31A6 // unsupported
    // 1.08 _ZN11CAutomobile14ProcessControlEv 0x4E31A6 // ARM32/Thumb bytes
    // 1.08 _ZN5CBike9ProcessAIERj 0x4EE200 // unsupported
    // 1.08 _ZN5CBike9ProcessAIERj 0x4EE200 // ARM32/Thumb bytes
    // 1.08 _ZN5CBike9ProcessAIERj 0x4EE200 // unsupported
    // 1.08 _ZN5CBike9ProcessAIERj 0x4EE200 // no value
    // 1.08 _ZN5CBike14ProcessControlEv 0x4EE7D2 // unsupported
    // 1.08 _ZN5CBike14ProcessControlEv 0x4EE7D2 // ARM32/Thumb bytes
    // 1.08 _ZN5CBoat14ProcessControlEv 0x4F741E // unsupported
    // 1.08 _ZN5CBoat14ProcessControlEv 0x4F741E // ARM32/Thumb bytes
    // 1.08 _ZN17CTheCarGenerators7ProcessEv 0x4F90AC HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN17CTheCarGenerators7ProcessEv 0x4F90AC // ARM32/Thumb bytes
    // 1.08 _ZN5CHeli11UpdateHelisEv 0x4FDC78 HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 0x50 0x50 HEX \x50\x22 // no 2.11 map
    // 1.08 0x50 0x50 HEX \x50\x2B // no 2.11 map
    // 1.08 0x50 0x50 HEX \x50\x2B // no 2.11 map
    // 1.08 _ZN6CPlane27DoPlaneGenerationAndRemovalEv 0x504DB8 HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN6CPlane27DoPlaneGenerationAndRemovalEv 0x504DB8 // ARM32/Thumb bytes
    // 1.08 _ZN6CTrain14ProcessControlEv 0x50AB4A // unsupported
    // 1.08 _ZN6CTrain14ProcessControlEv 0x50AB4A // ARM32/Thumb bytes
    // 1.08 _ZN8CVehicle9SetDriverEP4CPed 0x50FEFE HEX \x1B\x00 // ARM32/Thumb bytes
    // 1.08 _ZN8CVehicle9SetDriverEP4CPed 0x50FF70 // unsupported
    // 1.08 _ZNK8CVehicle11CanBeDrivenEv 0x5186E4 // unsupported
    // 1.08 _ZN6CBirds6RenderEv 0x5286EC HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN8CCoronas17RenderReflectionsEv 0x52DD38 HEX \x00\x20\x70\x47 // ARM32/Thumb bytes
    // 1.08 _ZN6CGlass6RenderEv 0x5366D0 HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN12CPostEffects7SpeedFXEf 0x53EC78 HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN22CRealTimeShadowManager6UpdateEv 0x541AC4 // ARM32/Thumb bytes
    // 1.08 _ZN22CRealTimeShadowManager6UpdateEv 0x541AC4 HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN8CMirrors16RenderReflBufferEb 0x54DCF4 HEX \xF7\x46 // ARM32/Thumb bytes
    // 1.08 _ZN9CTxdStore10InitialiseEv 0x55BA9A HEX \x4f\xf4\xb8\x50\xc0\xf2\x11\x00 // ARM32/Thumb bytes
    // 1.08 _ZN9CTxdStore10InitialiseEv 0x55BA9A HEX \x4F\xF4\xB8\x50\xC0\xF2\x11\x00 // ARM32/Thumb bytes
    // 1.08 _ZN9CTxdStore10InitialiseEv 0x55BA9A HEX \x4F\xF4\xB8\x50\xC0\xF2\x11\x00 // ARM32/Thumb bytes
    // 1.08 _ZN9CTxdStore10InitialiseEv 0x55BA9E HEX \xC0\xF2\x11\x00 // ARM32/Thumb bytes
    // 1.08 _ZN9CTxdStore10InitialiseEv 0x55BA9E HEX \xC0\xF2\x11\x00 // ARM32/Thumb bytes
    // 1.08 _ZN9CTxdStore10InitialiseEv 0x55BA9E HEX \xC0\xF2\x11\x00 // ARM32/Thumb bytes
    // 1.08 _ZN9CTxdStore10InitialiseEv 0x55BAA8 HEX \x44\xf6\x20\x60 // ARM32/Thumb bytes
    // 1.08 _ZN9CTxdStore10InitialiseEv 0x55BAA8 HEX \x44\xF6\x20\x60 // ARM32/Thumb bytes
    // 1.08 _ZN9CTxdStore10InitialiseEv 0x55BAA8 HEX \x44\xF6\x20\x60 // ARM32/Thumb bytes
    // 1.08 _ZN9CTxdStore10InitialiseEv 0x55BAB0 HEX \x44\xf6\x20\x62 // ARM32/Thumb bytes
    // 1.08 _ZN9CTxdStore10InitialiseEv 0x55BAB0 HEX \x44\xF6\x20\x62 // ARM32/Thumb bytes
    // 1.08 _ZN9CTxdStore10InitialiseEv 0x55BAB0 HEX \x44\xF6\x20\x62 // ARM32/Thumb bytes
    // 1.08 _ZN11CBulletInfo6UpdateEv 0x55E450 // unsupported
    // 1.08 _ZN11CBulletInfo6UpdateEv 0x55E450 // no value
    // 1.08 _ZN11CBulletInfo6UpdateEv 0x55E454 // unsupported
    // 1.08 _ZN11CBulletInfo6UpdateEv 0x55E454 // no value
    // 1.08 _ZN8CRestart26ExtraHospitalRestartRadiusE_ptr 0x5CEA8C // unsupported
    // 1.08 _ZN8CRestart26ExtraHospitalRestartRadiusE_ptr 0x5CEA8C // no value
    // 1.08 _ZN17CVehicleModelInfo21ms_vehicleColourTableE_ptr 0x5CF418 // unsupported
    // 1.08 _ZN17CVehicleModelInfo21ms_vehicleColourTableE_ptr 0x5CF418 // no value
    // 1.08 _ZN11CPopulation11ms_nNumGangE_ptr 0x5CF914 // unsupported
    // 1.08 _ZN11CPopulation11ms_nNumGangE_ptr 0x5CF914 // no value
    // 1.08 _ZTV23CTaskSimpleRunTimedAnim_ptr 0x5D1020 // no 2.11 map
    // 1.08 _ZN10CTimeCycle12m_nSkyTopRedE_ptr 0x5D1E8C // unsupported
    // 1.08 _ZN10CTimeCycle12m_nSkyTopRedE_ptr 0x5D1E8C // no value
    // 1.08 _ZN10CTimeCycle12m_nSkyTopRedE_ptr 0x5D1E8C // ARM32/Thumb bytes
    // 1.08 _ZN10CStreaming18ms_memoryAvailableE 0x5DE734 // unsupported
    // 1.08 0x600 0x600 HEX \x4F\xF4\xC0\x62 // no 2.11 map
    // 1.08 0x608558 0x608558 // no 2.11 map
    // 1.08 _ZN8CTrailer25m_fTrailerSuspensionForceE 0x60FDE4 // no value
    // 1.08 _ZN8CTrailer25m_fTrailerSuspensionForceE 0x60FDE5 // no value
    // 1.08 0x65EC8 0x65EC8 HEX \x45\xF6\xC8\x60\xC0\xF2\x06\x00 // no 2.11 map
    // 1.08 0x6B00 0x6B00 HEX \x4f\xf4\xd6\x40\xc0\xf2\x03\x00 // no 2.11 map
    // 1.08 0x7391 0x7391 HEX \x47\xF2\x91\x30 // no 2.11 map
    // 1.08 0x76F20 0x76F20 HEX \x4C\xF6\xD0\x70\xC0\xF2\x17\x00 // no 2.11 map
    // 1.08 0x7C4 0x7C4 HEX \x45\xF6\xC8\x60\xC0\xF2\x06\x00 // no 2.11 map
    // 1.08 0x80 0x80 HEX \x4F\xF4\x40\x30 // no 2.11 map
    // 1.08 0x800 0x800 HEX \xb3\xf5\x00\x6f // no 2.11 map
    // 1.08 0x800 0x800 HEX \xb3\xf5\x00\x6f // no 2.11 map
    // 1.08 0xBB0 0xBB0 HEX \x4f\xf4\x3b\x62 // no 2.11 map
    // 1.08 0xC 0xC HEX \x4f\xf4\x54\x50\xc0\xf2\x0c\x00 // no 2.11 map
    // 1.08 0xD2 0xD2 HEX \xD2\x22 // no 2.11 map
    // 1.08 0xFA00 0xFA00 HEX \x4F\xF4\x40\x30 // no 2.11 map
    // 1.08 _ZN6CWorld7PlayersE_ptr 0x5D021C // unsupported
    // 1.08 _ZN6CWorld7PlayersE_ptr 0x5D021C // no value
    // 1.08 _ZN6CWorld7PlayersE_ptr 0x5D021C // ARM32/Thumb bytes
    // 1.08 _ZN6CWorld7PlayersE_ptr 0x5D021C // unsupported
    // 1.08 _ZN6CWorld7PlayersE_ptr 0x5D021C // no value
    // 1.08 0x60EAE8 0x60EAE8 // no 2.11 map
    // 1.08 0x10000000 0x10000000 // no 2.11 map
    // 1.08 0x11 0x11 HEX \x4f\xf4\xb8\x50\xc0\xf2\x11\x00 // no 2.11 map
    // 1.08 0x14 0x14 HEX \x4f\xf4\xc8\x30 // no 2.11 map
    // 1.08 0x14 0x14 HEX \x4f\xf4\x20\x40 // no 2.11 map
    // 1.08 0x16B20 0x16B20 HEX \x42\xF2\xB0\x00\xC0\xF2\x02\x00\x00\x46 // no 2.11 map
    // 1.08 0x1700 0x1700 HEX \x4f\xf4\xb8\x50\xc0\xf2\x11\x00 // no 2.11 map
    // 1.08 0x179B40 0x179B40 // no 2.11 map
    // 1.08 0x17CFD0 0x17CFD0 HEX \x4C\xF6\xD0\x70\xC0\xF2\x17\x00 // no 2.11 map
    // 1.08 0x19 0x19 HEX \x4F\xF4\x90\x40\xC0\xF2\x19\x00 // no 2.11 map
    // 1.08 0x19000 0x19000 HEX \x4f\xf4\xc8\x30 // no 2.11 map
    // 1.08 0x1E080C 0x1E080C // no 2.11 map
    // 1.08 0x1E080C 0x1E080C // no 2.11 map
    // 1.08 0x20000 0x20000 HEX \x4F\xF4\x00\x30 // no 2.11 map
    // 1.08 0x20000 0x20000 HEX \x4F\xF4\x00\x30 // no 2.11 map
    // 1.08 0x20C670 0x20C670 // no 2.11 map
    // 1.08 0x220B0 0x220B0 HEX \x42\xF2\xB0\x00\xC0\xF2\x02\x00\x00\x46 // no 2.11 map
    // 1.08 0x298 0x298 HEX \x42\xF2\xB0\x00\xC0\xF2\x02\x00\x00\x46 // no 2.11 map
    // 1.08 _ZN4CHud14SetHelpMessageEPKcPtbbbj 0x3D4244 HEX \xF7\x46 // no 2.11 map
    // 1.08 _ZN4CHud14SetHelpMessageEPKcPtbbbj 0x3D4244 // no 2.11 map
    // 1.08 _ZN4CHud14SetHelpMessageEPKcPtbbbj 0x3D4244 // no 2.11 map
    // 1.08 _ZN10CPlayerPedC1Eib 0x458ED1 HEX \xE0 // no 2.11 map
    // 1.08 _ZN10CPlayerPedC1Eib 0x458ED1 HEX \xE0 // no 2.11 map
    // 1.08 _ZN10CPlayerPedC1Eib 0x458ED1 HEX \xE0 // no 2.11 map
    // 1.08 0x4800 0x4800 HEX \x4F\xF4\x90\x40\xC0\xF2\x19\x00 // no 2.11 map
    // 1.08 _ZN21CTaskSimpleHoldEntityC2EP7CEntityPK7CVectorhh11AnimationId12AssocGroupIdb 0x4C8816 // no 2.11 map
    // 1.08 _ZN21CTaskSimpleHoldEntityC2EP7CEntityPK7CVectorhh11AnimationId12AssocGroupIdb 0x4C881E // no 2.11 map
    // 1.08 0x4E20 0x4E20 HEX \x44\xf6\x20\x60 // no 2.11 map
    // 1.08 _ZN8CShadows17StoreStaticShadowEjhP9RwTextureP7CVectorffffshhhfffbf 0x545C04 // no 2.11 map
    // 1.08 0x562D52 0x562D52 // no 2.11 map
    // 1.08 0x562D5C 0x562D5C // no 2.11 map
    // 1.08 _Z11DoGameStatev 0x56C126 // no 2.11 map
    // 1.08 _Z11DoGameStatev 0x56C126 HEX \x5A // no 2.11 map
    // 1.08 _Z11DoGameStatev 0x56C126 HEX \x5A // no 2.11 map
    // 1.08 _Z11DoGameStatev 0x56C150 // no 2.11 map
    // 1.08 _Z11DoGameStatev 0x56C1A2 // no 2.11 map
    // 1.08 _Z11DoGameStatev 0x56C1A2 // no 2.11 map
    // 1.08 _Z11DoGameStatev 0x56C1F6 // no 2.11 map
    // 1.08 _Z11DoGameStatev 0x56C1F6 HEX \x5A // no 2.11 map
    // 1.08 _Z11DoGameStatev 0x56C1F6 HEX \x5A // no 2.11 map
    // 1.08 0x570B00 0x570B00 // no 2.11 map
    // 1.08 0x570B40 0x570B40 // no 2.11 map
    // 1.08 0x570B58 0x570B58 // no 2.11 map
    // 1.08 0x570BC8 0x570BC8 // no 2.11 map
    // 1.08 0x570C74 0x570C74 // no 2.11 map
    // 1.08 0x573640 0x573640 // no 2.11 map
    // 1.08 0x573668 0x573668 // no 2.11 map
    // 1.08 0x57367C 0x57367C // no 2.11 map
    // 1.08 0x573690 0x573690 // no 2.11 map
    // 1.08 0x5736C8 0x5736C8 // no 2.11 map
    // 1.08 0x5736D8 0x5736D8 // no 2.11 map
    // 1.08 0x5736E8 0x5736E8 // no 2.11 map
    // 1.08 0x5900 0x5900 HEX \x4f\xf4\x7e\x40\xc0\xf2\x12\x00 // no 2.11 map
    // 1.08 0x5C6C68 0x5C6C68 // no 2.11 map
    // 1.08 0x6 0x6 HEX \x4f\xf4\x7e\x40\xc0\xf2\x12\x00 // no 2.11 map
    // 1.08 0x63D4F0 0x63D4F0 // no 2.11 map
    // 1.08 0x63D4F0 0x63D4F0 // no 2.11 map
    // 1.08 0x63D4F0 0x63D4F0 // no 2.11 map
    // 1.08 0x7019CD 0x7019CD // no 2.11 map
    // 1.08 0x7700 0x7700 HEX \x4f\xf4\xee\x40\xc0\xf2\x01\x00 // no 2.11 map
    // 1.08 0x7EFF 0x7EFF HEX \x47\xF6\xFF\x60 // no 2.11 map
    // 1.08 0x86A0 0x86A0 HEX \x48\xf2\xa0\x62 // no 2.11 map
    // 1.08 0x8E87E4 0x8E87E4 // no 2.11 map
    // 1.08 0x8E87E4 0x8E87E4 // no 2.11 map
    // 1.08 0x8EA7A8 0x8EA7A8 // no 2.11 map
    // 1.08 0x8EA7A8 0x8EA7A8 // no 2.11 map
    // 1.08 0x8EA7B0 0x8EA7B0 // no 2.11 map
    // 1.08 0x8ED875 0x8ED875 // no 2.11 map
    // 1.08 0x95B074 0x95B074 // no 2.11 map
    // 1.08 0x95B074 0x95B074 HEX \x5A // no 2.11 map
    // 1.08 0x95B074 0x95B074 HEX \x5A // no 2.11 map
    // 1.08 0x9B 0x9B // no 2.11 map
    // 1.08 0x9B 0x9B // no 2.11 map
    // 1.08 0xA000 0xA000 HEX \x4f\xf4\x20\x40 // no 2.11 map
    // 1.08 0xA000 0xA000 HEX \x4f\xf4\x20\x40 // no 2.11 map
    // 1.08 0xBE 0xBE // no 2.11 map
    // 1.08 0xBE 0xBE // no 2.11 map
    // 1.08 0xC 0xC // no 2.11 map
    // 1.08 0xFA0 0xFA0 HEX \x40\xf6\xa0\x70 // no 2.11 map
    // 1.08 0xFDC0 0xFDC0 HEX \x4F\xF6\xC0\x50 // no 2.11 map
    // 1.08 0xFDC0 0xFDC0 HEX \x4F\xF6\xC0\x50 // no 2.11 map
    // 1.08 0xFDC0 0xFDC0 HEX \x4F\xF6\xC0\x50 // no 2.11 map
    // 1.08 0xFF 0xFF // no 2.11 map
    // 1.08 0xFFFFFFFF 0xFFFFFFFF // no 2.11 map
#endif
}

void ApplyMappedLegacyPatchBacklog_2_0_Disabled()
{
#if 0
    // 2.0 only: no 2.11 map or unsafe old-version bytes
    // 2.0 _Z21_rwOpenGLRasterCreatePvS_i 0x1AE95E HEX \x01\x22 // ARM32/Thumb bytes
    // 2.0 _ZN11RenderQueueC1Ev 0x1D1764 HEX \x4F\xF4\x80\x00 // ARM32/Thumb bytes
    // 2.0 _ZN11RenderQueueC1Ev 0x1D176E HEX \x4F\xF4\x80\x06 // ARM32/Thumb bytes
    // 2.0 _ZN30CWidgetRegionSteeringSelection4DrawEv 0x2C3F40 // no 2.11 map
    // 2.0 _ZN10CCollision28CheckCameraCollisionVehiclesEiiP7CColBoxP10CColSphereS3_S3_P7CVector 0x2DF1E0 // no 2.11 map
    // 2.0 _ZN8CCarCtrl31GenerateOneEmergencyServicesCarEj7CVector 0x2FB258 // no 2.11 map
    // 2.0 _ZN6CCheat21ToggleShowTapToTargetEv 0x2FD4FC // unsupported
    // 2.0 _ZN6CCheat21ToggleShowTapToTargetEv 0x2FD4FC // ARM32/Thumb bytes
    // 2.0 _ZN10CGameLogic36RestorePlayerStuffDuringResurrectionEP10CPlayerPed7CVectorf 0x307AC0 // no 2.11 map
    // 2.0 _ZN10CGameLogic43SetPlayerWantedLevelForForbiddenTerritoriesEb 0x308FEC // no 2.11 map
    // 2.0 _ZN11CTheScripts30AddToListOfConnectedLodObjectsEP7CObjectS1_ 0x33559C // no 2.11 map
    // 2.0 _ZN14CRunningScript23ProcessCommands300To399Ei 0x341F34 HEX \x00\xF0\x21\xBE // no 2.11 map
    // 2.0 _ZN10FxSystem_c11AddParticleEP5RwV3dS1_fP11FxPrtMult_cfffh 0x36E324 // no 2.11 map
    // 2.0 _ZN14CBaseModelInfoC2Ev 0x384F88 // no value
    // 2.0 _ZN10CTimeCycle19CalcColoursForPointE7CVectorP10CColourSet 0x41F300 // unsupported
    // 2.0 _ZN10CTimeCycle19CalcColoursForPointE7CVectorP10CColourSet 0x41FF6C // unsupported
    // 2.0 _ZN4CHud9DrawRadarEv 0x437ED4 // no value
    // 2.0 _ZN4CHud9DrawRadarEv 0x437ED6 // no value
    // 2.0 _ZN4CHud9DrawRadarEv 0x437EE2 // no value
    // 2.0 _ZN4CHud9DrawRadarEv 0x437F1E // no value
    // 2.0 _ZN4CHud9DrawRadarEv 0x437F20 // no value
    // 2.0 _ZN4CHud9DrawRadarEv 0x437F24 // no value
    // 2.0 _ZN4CHud9DrawRadarEv 0x437F4E // no value
    // 2.0 _ZN4CHud9DrawRadarEv 0x437F50 // no value
    // 2.0 _ZN4CHud9DrawRadarEv 0x437F54 // no value
    // 2.0 _ZN4CHud9DrawRadarEv 0x437F7A // no value
    // 2.0 _ZN4CHud9DrawRadarEv 0x437F7C // no value
    // 2.0 _ZN4CHud9DrawRadarEv 0x437F7E // no value
    // 2.0 _ZN6CRadar13DrawCoordBlipEihif 0x43FB0E HEX \x12\xE0 // no 2.11 map
    // 2.0 _ZN6CRadar13DrawCoordBlipEihif 0x43FB36 HEX \x48\x46 // no 2.11 map
    // 2.0 _ZN6CRadar13DrawCoordBlipEihif 0x43FE08 // no 2.11 map
    // 2.0 _ZN6CRadar13DrawCoordBlipEihif 0x43FE0A // no 2.11 map
    // 2.0 _ZN6CRadar14DrawEntityBlipEihif 0x440470 HEX \x3A\xE0 // ARM32/Thumb bytes
    // 2.0 _ZN6CRadar14DrawEntityBlipEihif 0x4404E8 HEX \x3A\xE0 // ARM32/Thumb bytes
    // 2.0 _ZN6CRadar13Draw3dMarkersEv 0x4420D0 HEX \x2C\xE0 // no 2.11 map
    // 2.0 _ZN6CRadar13Draw3dMarkersEv 0x44212C HEX \x2C\xE0 // no 2.11 map
    // 2.0 _ZN17CVehicleModelInfo15SetupCommonDataEv 0x468B7E HEX \x4F\xF4\x00\x30 // ARM32/Thumb bytes
    // 2.0 _ZN17CVehicleModelInfo15SetupCommonDataEv 0x468B88 HEX \xF7\x20 // ARM32/Thumb bytes
    // 2.0 _ZN17CVehicleModelInfo15SetupCommonDataEv 0x468B8A HEX \xF7\x25 // ARM32/Thumb bytes
    // 2.0 _ZN17CVehicleModelInfo15SetupCommonDataEv 0x468BCC HEX \xF7\x28 // ARM32/Thumb bytes
    // 2.0 _ZN10CStreaming5Init2Ev 0x46BE0A // unsupported
    // 2.0 _ZN10CStreaming5Init2Ev 0x46BE10 // unsupported
    // 2.0 _ZN4CPed31RemoveWeaponWhenEnteringVehicleEi 0x4A5328 // no 2.11 map
    // 2.0 _ZN4CPed21SetWeaponLockOnTargetEP7CEntity 0x4A82D4 HEX \xF7\x46 // ARM32/Thumb bytes
    // 2.0 _ZN8C_PcSave8SaveSlotEab 0x4D3D7C HEX \xF7\x46 // ARM32/Thumb bytes
    // 2.0 _ZN13CCarEnterExit17SetPedInCarDirectEP4CPedP8CVehicleib 0x50AA58 // no 2.11 map
    // 2.0 _ZN18CTaskSimpleJetPack13ProcessThrustEP4CPed 0x5319D0 // no 2.11 map
    // 2.0 _ZN18CTaskSimpleJetPack13ProcessThrustEP4CPed 0x5319D0 // no 2.11 map
    // 2.0 _ZN23CTaskSimplePlayerOnFoot19ProcessPlayerWeaponEP10CPlayerPed 0x537F34 HEX \x02\x23 // no 2.11 map
    // 2.0 _ZN23CTaskSimplePlayerOnFoot18PlayIdleAnimationsEP10CPlayerPed 0x538C8C // no 2.11 map
    // 2.0 _ZN8CVehicle9SetDriverEP4CPed 0x5846D2 HEX \x00\x00 // ARM32/Thumb bytes
    // 2.0 _ZNK8CVehicle11CanBeDrivenEv 0x58FEBA // unsupported
    // 2.0 _ZN7CSprite43RenderBufferedOneXLUSprite_Rotate_DimensionEfffffhhhsffh 0x5C6C68 // no 2.11 map
    // 2.0 _ZN10CCullZones22AddTunnelAttributeZoneERK7CVectorfffffft 0x5D021C // unsupported
    // 2.0 _ZN10CCullZones22AddTunnelAttributeZoneERK7CVectorfffffft 0x5D021C // no value
    // 2.0 _ZN17CVehicleModelInfo21ms_vehicleColourTableE_ptr 0x677654 // unsupported
    // 2.0 _ZN17CVehicleModelInfo21ms_vehicleColourTableE_ptr 0x677654 // no value
    // 2.0 _ZN9CPopCycle11m_fPercCopsE_ptr 0x679118 // unsupported
    // 2.0 _ZN9CPopCycle11m_fPercCopsE_ptr 0x679118 // no value
    // 2.0 _ZN10CModelInfo16ms_modelInfoPtrsE_ptr 0x6796D4 // ARM32/Thumb bytes
    // 2.0 _ZN6CWorld7PlayersE_ptr 0x6783C8 // unsupported
    // 2.0 _ZN6CWorld7PlayersE_ptr 0x6783C8 // no value
    // 2.0 0x6B012C 0x6B012C // no 2.11 map
    // 2.0 0x10000000 0x10000000 // no 2.11 map
    // 2.0 0x19B688 0x19B688 // no 2.11 map
    // 2.0 0x19E2CC 0x19E2CC // no 2.11 map
    // 2.0 0x1C8064 0x1C8064 HEX \x01 // no 2.11 map
    // 2.0 0x1C8082 0x1C8082 HEX \x01 // no 2.11 map
    // 2.0 0x40A00000 0x40A00000 // no 2.11 map
    // 2.0 0x41C80000 0x41C80000 // no 2.11 map
    // 2.0 _ZN4CHud14SetHelpMessageEPKcPtbbbj 0x436F5C // no 2.11 map
    // 2.0 _ZN10CPlayerPedC1Eib 0x4C3673 HEX \xB3 // no 2.11 map
    // 2.0 _ZN22CRealTimeShadowManagerC2Ev 0x5B81E4 // no 2.11 map
    // 2.0 _ZN22CRealTimeShadowManagerD1Ev 0x5B8206 // no 2.11 map
    // 2.0 _Z11DoGameStatev 0x5E4916 // no 2.11 map
    // 2.0 _Z11DoGameStatev 0x5E4978 HEX \x64 // no 2.11 map
    // 2.0 _Z11DoGameStatev 0x5E4978 // no 2.11 map
    // 2.0 _Z11DoGameStatev 0x5E4978 // no 2.11 map
    // 2.0 _Z11DoGameStatev 0x5E4990 HEX \x64 // no 2.11 map
    // 2.0 _Z11DoGameStatev 0x5E4990 // no 2.11 map
    // 2.0 _Z11DoGameStatev 0x5E4990 // no 2.11 map
    // 2.0 0x5EB9D9 0x5EB9D9 HEX \x31\x2E\x30\x30 // no 2.11 map
    // 2.0 0x60EAE8 0x60EAE8 // no 2.11 map
    // 2.0 0x613E0A 0x613E0A // no 2.11 map
    // 2.0 0x613E0A 0x613E0A // no 2.11 map
    // 2.0 0x667454 0x667454 // no 2.11 map
    // 2.0 _ZN14SurfaceInfos_c12CantSprintOnEj_ptr 0x66FD60 // no 2.11 map
    // 2.0 0x6BCBF8 0x6BCBF8 // no 2.11 map
    // 2.0 0x6BD1E4 0x6BD1E4 HEX \x01 // no 2.11 map
    // 2.0 0x8EA7A8 0x8EA7A8 // no 2.11 map
    // 2.0 0x8EA7B0 0x8EA7B0 // no 2.11 map
    // 2.0 0x98D252 0x98D252 // no 2.11 map
    // 2.0 0x98D2B8 0x98D2B8 // no 2.11 map
    // 2.0 0x98F1AD 0x98F1AD // no 2.11 map
    // 2.0 0x9F0B16 0x9F0B16 // no 2.11 map
    // 2.0 0x9F0B16 0x9F0B16 // no 2.11 map
    // 2.0 0x9FC908 0x9FC908 // no 2.11 map
    // 2.0 0x9FC908 0x9FC908 // no 2.11 map
    // 2.0 0xF7 0xF7 HEX \xF7\x20 // no 2.11 map
    // 2.0 0xFF 0xFF // no 2.11 map
#endif
}

void ApplyMappedLegacyPatchBacklog_2_10_Disabled()
{
#if 0
    // 2.10 only: no 2.11 map or unsafe old-version bytes
    // 2.10 _Z16RwFrameTranslateP7RwFramePK5RwV3d15RwOpCombineType 0x2700AC HEX \x03\x28 // no 2.11 map
    // 2.10 _Z12RwFrameScaleP7RwFramePK5RwV3d15RwOpCombineType 0x2700F2 HEX \x03\x2A // no 2.11 map
    // 2.10 _Z12RwFrameScaleP7RwFramePK5RwV3d15RwOpCombineType 0x270118 HEX \x03\x28 // no 2.11 map
    // 2.10 _Z12RwFrameScaleP7RwFramePK5RwV3d15RwOpCombineType 0x270164 HEX \x03\x28 // no 2.11 map
    // 2.10 0x2AB4A6 0x2AB4A6 // no 2.11 map
    // 2.10 _ZN30CWidgetRegionSteeringSelectionD0Ev 0x385E38 // no 2.11 map
    // 2.10 _ZN14CRunningScript23ProcessCommands100To199Ei 0x3F61B6 // no 2.11 map
    // 2.10 _ZN14CRunningScript23ProcessCommands100To199Ei 0x3F62D8 // no 2.11 map
    // 2.10 _ZN14CRunningScript25ProcessCommands1400To1499Ei 0x420E40 // no value
    // 2.10 _ZN22CEventEditableResponse23ComputeResponseTaskTypeEP9CPedGroup 0x442120 HEX \x2C\xE0 // no 2.11 map
    // 2.10 _ZN22CEventEditableResponse23ComputeResponseTaskTypeEP9CPedGroup 0x44217C HEX \x2C\xE0 // no 2.11 map
    // 2.10 _ZN13CEventHandler21ComputeDamageResponseEP6CEventP5CTaskS3_S3_ 0x454A88 // no 2.11 map
    // 2.10 _ZN24CControllerConfigManager30InitDefaultControlConfigJoyPadEj 0x4C36E2 HEX \xE0 // no 2.11 map
    // 2.10 _ZN24CControllerConfigManager31InitDefaultControlConfigurationEv 0x4C5902 // no 2.11 map
    // 2.10 _ZN6CRadar13DrawCoordBlipEihif 0x52522C (x64-from-ternary) // no 2.11 map
    // 2.10 _ZN6CRadar13Draw3dMarkersEv 0x52737C HEX \x1E\x00\x00\x14 // no 2.11 map
    // 2.10 _ZN32CTaskComplexMedicTreatInjuredPed10CreateTaskEv 0x584850 // no 2.11 map
    // 2.10 _ZN32CTaskComplexMedicTreatInjuredPed10CreateTaskEv 0x584884 // no 2.11 map
    // 2.10 _ZN22CTaskComplexSeekEntityI33CEntitySeekPosCalculatorVehicleIdE14ControlSubTaskEP4CPed 0x591272 HEX \x02 // no 2.11 map
    // 2.10 _ZN22CTaskComplexSeekEntityI33CEntitySeekPosCalculatorVehicleIdE14ControlSubTaskEP4CPed 0x59128E HEX \x02 // no 2.11 map
    // 2.10 _ZN32CTaskComplexKillPedOnFootStealth14ControlSubTaskEP4CPed 0x5E492E // no 2.11 map
    // 2.10 _ZN32CTaskComplexKillPedOnFootStealth14ControlSubTaskEP4CPed 0x5E49C8 // no 2.11 map
    // 2.10 _ZN32CTaskComplexKillPedOnFootStealth14ControlSubTaskEP4CPed 0x5E49E0 // no 2.11 map
    // 2.10 _ZN32CTaskComplexKillPedOnFootStealth14ControlSubTaskEP4CPed 0x5E49E6 // no 2.11 map
    // 2.10 _ZN6CWorld13PlayerInFocusE_ptr 0x8516D8 (x64-from-ternary) HEX \x00\x21 // no 2.11 map
    // 2.10 _ZN10CTimeCycle12m_nSkyTopRedE_ptr 0x851D38 (x64-from-ternary) // no value
    // 2.10 _ZN6CWorld28FindPlayerSlotWithPedPointerEPv _ZN6CWorld28FindPlayerSlotWithPe // needs replacement
    // 2.10 0x2AB5C6 0x2AB5C6 HEX \x00\x21 // no 2.11 map
    // 2.10 _ZN6CRadar13DrawCoordBlipEihif 0x524E88 HEX \xCC\xFF\xFF\x17 // no 2.11 map
    // 2.10 _ZN6CRadar13DrawCoordBlipEihif 0x524F58 HEX \xCC\xFF\xFF\x17 // no 2.11 map
    // 2.10 _ZN6CRadar13Draw3dMarkersEv 0x5273F4 HEX \x1E\x00\x00\x14 // no 2.11 map
    // 2.10 _ZN6CWorld7PlayersE_ptr 0x84E7A8 (x64-from-ternary) HEX \xE1\x03\x16\x2A // no value
    // 2.10 0x88CB08 (x64-from-ternary) 0x88CB08 (x64-from-ternary) HEX \x03\x28 // no 2.11 map
    // 2.10 _ZN4CHud14SetHelpMessageEPKcPtbbbj _ZN4CHud14SetHelpMessageEPKcPtbb // no 2.11 map
    // 2.10 0x1AE8DE 0x1AE8DE HEX \x01\x22 // no 2.11 map
    // 2.10 0x1D16E4 0x1D16E4 HEX \x4F\xF0\x80\x70 // no 2.11 map
    // 2.10 0x1D16EA 0x1D16EA HEX \x4F\xF4\x00\x10\x4F\xF4\x80\x06 // no 2.11 map
    // 2.10 0x1D16EE 0x1D16EE HEX \x4F\xF0\x80\x76 // no 2.11 map
    // 2.10 0x1D193A 0x1D193A HEX \x4F\xF4\x00\x16 // no 2.11 map
    // 2.10 _ZL10UVAnimReadP8RwStreamiPvii 0x25EDC8 // no 2.11 map
    // 2.10 _ZL10UVAnimReadP8RwStreamiPvii 0x25EE0C // no 2.11 map
    // 2.10 _ZN14CRunningScript25ProcessCommands2600To2699Ei 0x40BF26 // no 2.11 map
    // 2.10 _ZN10CPlayerPedC1Eib 0x5C0BC4 HEX \x34\x00\x80\x52 // no 2.11 map
    // 2.10 _Z11DoGameStatev 0x70A38C // no 2.11 map
    // 2.10 _Z11DoGameStatev 0x70A398 // no 2.11 map
    // 2.10 _Z11DoGameStatev 0x70A43C // no 2.11 map
    // 2.10 _Z11DoGameStatev 0x70A458 // no 2.11 map
    // 2.10 _Z11DoGameStatev 0x70A474 // no 2.11 map
    // 2.10 0x7371E0 (x64-from-ternary) 0x7371E0 (x64-from-ternary) // no 2.11 map
    // 2.10 0x73740C (x64-from-ternary) 0x73740C (x64-from-ternary) // no 2.11 map
    // 2.10 0x89AA88 0x89AA88 // no 2.11 map
    // 2.10 0x8B5028 (x64-from-ternary) 0x8B5028 (x64-from-ternary) // no 2.11 map
    // 2.10 0xBD41E161 0xBD41E161 // no 2.11 map
    // 2.10 0xC1BF92 (x64-from-ternary) 0xC1BF92 (x64-from-ternary) HEX \x34\x00\x80\x52 // no 2.11 map
    // 2.10 0xC1BFF8 (x64-from-ternary) 0xC1BFF8 (x64-from-ternary) // no 2.11 map
    // 2.10 0xC9B320 (x64-from-ternary) 0xC9B320 (x64-from-ternary) HEX \x03\x28 // no 2.11 map
    // 2.10 0xD00010AB 0xD00010AB // no 2.11 map
#endif
}
// END GENERATED LEGACY PATCH BACKLOG

void ApplySAMPPatchesInGame()
{
    FLog("Installing patches (ingame)..");

    /* Разблокировка карты */
    // CTheZones::ZonesVisited[100]
    memset((void*)(g_libGTASA + 0xA59D7A), 1, 100);
    // CTheZones::ZonesRevealed
    *(uint32_t*)(g_libGTASA + 0xA59DE0) = 100;

    // CPlayerPed::CPlayerPed task fix
    CHook::WriteMemory(g_libGTASA + 0x5B5510, (uintptr_t)"\x34\x00\x80\x52", 4);

    // radar draw blips
    CHook::NOP(g_libGTASA + 0x51A314, 2);
    CHook::NOP(g_libGTASA + 0x51B11C, 2);

    CHook::RET("_ZN4CPed31RemoveWeaponWhenEnteringVehicleEi"); // CPed::RemoveWeaponWhenEnteringVehicle

//	CHook::WriteMemory(g_libGTASA + 0x00341F84, (uintptr_t)"\x00\xF0\x21\xBE", 4);

    // no vehicle audio processing
    CHook::NOP(g_libGTASA + 0x6A7834, 1); // CAutomobile
    CHook::NOP(g_libGTASA + 0x6B69B8, 1); // CBike
    CHook::NOP(g_libGTASA + 0x6C183C, 1); // CBoat
    CHook::NOP(g_libGTASA + 0x6D4270, 1); // CTrain

    // Disable in-game radio
    CHook::RET("_ZN20CAERadioTrackManager7ServiceEi");

    // Pause/menu map text/icon patches from older versions were not applied here.
    // They require exact 2.11 instruction-pattern verification before enabling.
}

int32_t CWorld__FindPlayerSlotWithPedPointer(CPedGTA* pPlayersPed)
{
    // Оптимизация - быстрый поиск
    static CPedGTA* lastPed = nullptr;
    static int32_t lastIndex = -1;

    if(lastPed == pPlayersPed && lastIndex != -1)
        return lastIndex;

    for(int i = 0; i < MAX_PLAYERS; ++i)
    {
        if(CWorld::Players[i].m_pPed == pPlayersPed)
        {
            lastPed = pPlayersPed;
            lastIndex = i;
            return i;
        }
    }

    lastPed = nullptr;
    lastIndex = -1;
    return -1;
}
CPlayerInfoGta * GetPlayerInfoForThisPlayerPed(CPedGTA *thiz)
{
    CPlayerInfoGta *v1; // x8
    v1 = CWorld::Players;

    return v1;

}
void ApplyPatches_level0()
{
    FLog("ApplyPatches_level0");

    CHook::Write(g_libGTASA + 0x837358, &CWorld::Players);       // 2.11 GOT: CWorld::Players
    CHook::Write(g_libGTASA + 0x837378, &CWorld::PlayerInFocus); // 2.11 GOT: CWorld::PlayerInFocus
    CHook::Redirect("_ZN6CWorld28FindPlayerSlotWithPedPointerEPv", &CWorld__FindPlayerSlotWithPedPointer);
    CHook::Redirect("_ZN10CPlayerPed29GetPlayerInfoForThisPlayerPedEv", &GetPlayerInfoForThisPlayerPed);


    CHook::WriteMemory(g_libGTASA + 0x77584C, (uintptr_t)"\x22\x00\x80\x52", 4);


/* 32-bit-only patch removed for 64-bit build. */

    DisableAutoAim();

    //CHook::RET("_ZN6CTrain10InitTrainsEv"); // CTrain::InitTrains

    //CHook::RET("_ZN8CClothes4InitEv"); // CClothes::Init()/
    //CHook::RET("_ZN8CClothes13RebuildPlayerEP10CPlayerPedb"); // CClothes::RebuildPlayer/

    CHook::RET("_ZNK35CPedGroupDefaultTaskAllocatorRandom20AllocateDefaultTasksEP9CPedGroupP4CPed"); // AllocateDefaultTasks
    CHook::RET("_ZN6CGlass4InitEv"); // CGlass::Init
    CHook::RET("_ZN8CGarages17Init_AfterRestartEv"); // CGarages::Init_AfterRestart
    CHook::RET("_ZN6CGangs10InitialiseEv"); // CGangs::Initialise
    CHook::RET("_ZN5CHeli9InitHelisEv"); // CHeli::InitHelis(void)
    CHook::RET("_ZN11CFileLoader10LoadPickupEPKc"); // CFileLoader::LoadPickup
    CHook::RET("_ZN14CLoadingScreen15DisplayPCScreenEv"); // Loading screen

    // entryexit
    //CHook::RET("_ZN17CEntryExitManager4InitEv");
    //CHook::RET("_ZN17CEntryExitManager22PostEntryExitsCreationEv");

    CHook::RET("_ZN10CSkidmarks6UpdateEv"); // CSkidmarks::Update
    CHook::RET("_ZN10CSkidmarks6RenderEv"); // CSkidmarks::Render

    //CHook::RET("_ZN14SurfaceInfos_c17CreatesWheelGrassEj"); // SurfaceInfos_c::CreatesWheelGrass
    //CHook::RET("_ZN14SurfaceInfos_c18CreatesWheelGravelEj"); // SurfaceInfos_c::CreatesWheelGravel
    //CHook::RET("_ZN14SurfaceInfos_c15CreatesWheelMudEj"); // SurfaceInfos_c::CreatesWheelMud
    //CHook::RET("_ZN14SurfaceInfos_c16CreatesWheelDustEj"); // SurfaceInfos_c::CreatesWheelDust
    //CHook::RET("_ZN14SurfaceInfos_c16CreatesWheelSandEj"); // SurfaceInfos_c::CreatesWheelSand
    //CHook::RET("_ZN14SurfaceInfos_c17CreatesWheelSprayEj"); // SurfaceInfos_c::CreatesWheelSpray

    //CHook::RET("_ZN4Fx_c13AddWheelGrassEP8CVehicle7CVectorhf"); // Fx_c::AddWheelGrass
    //CHook::RET("_ZN4Fx_c14AddWheelGravelEP8CVehicle7CVectorhf"); // Fx_c::AddWheelGravel
    //CHook::RET("_ZN4Fx_c11AddWheelMudEP8CVehicle7CVectorhf"); // Fx_c::AddWheelMud
    //CHook::RET("_ZN4Fx_c12AddWheelDustEP8CVehicle7CVectorhf"); // Fx_c::AddWheelDust
    //CHook::RET("_ZN4Fx_c12AddWheelSandEP8CVehicle7CVectorhf"); // Fx_c::AddWheelSand
    //CHook::RET("_ZN4Fx_c13AddWheelSprayEP8CVehicle7CVectorhhf"); // Fx_c::AddWheelSpray

    CHook::RET("_ZN11CPlayerInfo14LoadPlayerSkinEv");
    CHook::RET("_ZN11CPopulation10InitialiseEv");

    // fix skin vertices a lot, and it caused caching in RenderQueue.
    //missing renderqueu have been reworked
    //CHook::WriteMemory(g_libGTASA + 0x266FC8, (uintptr_t)"\x15\x80\xA0\x52", 4);
}

void ApplyGlobalPatches()
{
    FLog("Installing patches..");

    CHook::NOP(g_libGTASA + 0x716AD0, 1);

    // vehicle reflection wrong color
    CHook::NOP(g_libGTASA + 0x5F3B14, 1);

    CHook::RET("_ZN17CVehicleModelInfo17SetCarCustomPlateEv"); // default plate

    CHook::RET("_Z16SaveGameForPause10eSaveTypesPc"); // не сохранять при сворачивании. черный экран

    // черные значки
   // CHook::WriteMemory(g_libGTASA + 0x51C8B0, (uintptr_t)"\x1E\x00\x00\x14", 4); // B 0x5273F4
  //  CHook::WriteMemory(g_libGTASA + 0x51C974, (uintptr_t)"\xE1\x03\x14\x2A", 4); // mov w1, w20

    //missing n 2.11.311
    // CRadar::DrawEntityBlip (translate color)
    //CHook::WriteMemory(g_libGTASA + 0x5258D8, (uintptr_t)"\x22\x00\x00\x14", 4); // B 0x525960
    //CHook::WriteMemory(g_libGTASA + 0x525960, (uintptr_t)"\xE1\x03\x16\x2A", 4); // mov w1, W22

    // CRadar::DrawCoordBlip (translate color)
   // CHook::WriteMemory(g_libGTASA + 0x524F58, (uintptr_t)"\xCC\xFF\xFF\x17", 4); // B 0x524E88
    //CHook::WriteMemory(g_libGTASA + 0x524E88, (uintptr_t)"\xE1\x03\x16\x2A", 4); // mov w1, W22
    ////CHook::WriteMemory(g_libGTASA + 0x002AB5C6, (uintptr_t)"\x00\x21", 2);

    // crash legend
    CHook::NOP(g_libGTASA + 0x71DB60, 1);

    // Disable cutscene processing
    CHook::NOP(g_libGTASA + 0x4960E4, 2); // NOP calling CCutsceneMgr::Update from CGame::Process

    //ApplyShadowPatch();
    // why to set task if i create my task hmmm
    //ARMHook::writeMemory(g_libGTASA + 0x40AC28, (uintptr_t)"\x8F\xF5\x3A\xEF", 4); // CTaskComplexEnterCarAsDriver
    //ARMHook::makeNOP(g_libGTASA + 0x40AC30, 2); // NOP calling CTaskComplexEnterCarAsDriver::CTaskComplexEnterCarAsDriver from CPlayerInfo::Process
    CHook::NOP(g_libGTASA + 0x4AE114, 2); // CTaskManager::SetTask in CPLayerInfo::Process

    //CDebugInfo::ApplyDebugPatches();

    CHook::RET("_ZN12CAudioEngine16StartLoadingTuneEv"); // звук загрузочного экрана

    // DefaultPCSaveFileName
    char* DefaultPCSaveFileName = (char*)(g_libGTASA + 0x8839B0);
    memcpy(DefaultPCSaveFileName, "GTASAMP", 8);


    CHook::NOP(g_libGTASA + 0x498718, 1);  // CCoronas::RenderSunReflection crash
    CHook::NOP(g_libGTASA + 0x6DC14C, 1);  // не давать ган при выходе из тачки   ( клюшка, дробовик and etc )
    CHook::NOP(g_libGTASA + 0x6DC100, 1);  // не давать ган при выходе из тачки  ( клюшка, дробовик and etc )


    CHook::RET("_ZN17CVehicleRecording4LoadEP8RwStreamii"); // CVehicleRecording::Load

    CHook::RET("_ZN18CMotionBlurStreaks6UpdateEv");
    CHook::RET("_ZN7CCamera16RenderMotionBlurEv");

    CHook::RET("_ZN11CPlayerInfo17FindObjectToStealEP4CPed"); // Crash
    CHook::RET("_ZN26CAEGlobalWeaponAudioEntity21ServiceAmbientGunFireEv");	// CAEGlobalWeaponAudioEntity::ServiceAmbientGunFire
    CHook::RET("_ZN30CWidgetRegionSteeringSelection4DrawEv"); // CWidgetRegionSteeringSelection::Draw
    CHook::RET("_ZN23CTaskSimplePlayerOnFoot18PlayIdleAnimationsEP10CPlayerPed");	// CTaskSimplePlayerOnFoot::PlayIdleAnimations
    CHook::RET("_ZN13CCarEnterExit17SetPedInCarDirectEP4CPedP8CVehicleib");	// CCarEnterExit::SetPedInCarDirect
    CHook::RET("_ZN6CRadar10DrawLegendEiii"); // CRadar::DrawLgegend
    CHook::RET("_ZN6CRadar19AddBlipToLegendListEhi"); // CRadar::AddBlipToLegendList

    CHook::RET("_ZN11CAutomobile35CustomCarPlate_BeforeRenderingStartEP17CVehicleModelInfo"); // CAutomobile::CustomCarPlate_BeforeRenderingStart
    CHook::RET("_ZN11CAutomobile33CustomCarPlate_AfterRenderingStopEP17CVehicleModelInfo"); // CAutomobile::CustomCarPlate_AfterRenderingStop
    CHook::RET("_ZN7CCamera8CamShakeEffff"); // CCamera::CamShake
    CHook::RET("_ZN7CEntity23PreRenderForGlassWindowEv"); // CEntity::PreRenderForGlassWindow
    CHook::RET("_ZN8CMirrors16RenderReflBufferEb"); // CMirrors::RenderReflBuffer
    CHook::RET("_ZN4CHud23DrawBustedWastedMessageEv"); // CHud::DrawBustedWastedMessage // ПОТРАЧЕНО
    CHook::RET(g_libGTASA+0x510A94); // CHud::SetHelpMessage
    CHook::RET("_ZN4CHud24SetHelpMessageStatUpdateEhtff"); // CHud::SetHelpMessageStatUpdate
    CHook::RET("_ZN6CCheat16ProcessCheatMenuEv"); // CCheat::ProcessCheatMenu
    CHook::RET("_ZN6CCheat13ProcessCheatsEv"); // CCheat::ProcessCheats
    CHook::RET("_ZN6CCheat16AddToCheatStringEc"); // CCheat::AddToCheatString
    CHook::RET("_ZN6CCheat12WeaponCheat1Ev"); // CCheat::WeaponCheat1
    CHook::RET("_ZN6CCheat12WeaponCheat2Ev"); // CCheat::WeaponCheat2
    CHook::RET("_ZN6CCheat12WeaponCheat3Ev"); // CCheat::WeaponCheat3
    CHook::RET("_ZN6CCheat12WeaponCheat4Ev"); // CCheat::WeaponCheat4
    CHook::RET("_ZN8CGarages14TriggerMessageEPcsts"); // CGarages::TriggerMessage
    // ApplyMappedLegacyPatches();

    CHook::RET("_ZN11CPopulation6AddPedE8ePedTypejRK7CVectorb"); // CPopulation::AddPed
    CHook::RET("_ZN6CPlane27DoPlaneGenerationAndRemovalEv"); // CPlane::DoPlaneGenerationAndRemoval

    CHook::RET("_ZN10CEntryExit19GenerateAmbientPedsERK7CVector"); // CEntryExit::GenerateAmbientPeds
    CHook::RET("_ZN8CCarCtrl31GenerateOneEmergencyServicesCarEj7CVector"); // CCarCtrl::GenerateOneEmergencyServicesCar
    CHook::RET("_ZN11CPopulation17AddPedAtAttractorEiP9C2dEffect7CVectorP7CEntityi"); // CPopulation::AddPedAtAttractor crash. wtf stuff?

    CHook::RET("_ZN7CDarkel26RegisterCarBlownUpByPlayerEP8CVehiclei"); // CDarkel__RegisterCarBlownUpByPlayer_hook
    CHook::RET("_ZN7CDarkel25ResetModelsKilledByPlayerEi"); // CDarkel__ResetModelsKilledByPlayer_hook
    CHook::RET("_ZN7CDarkel25QueryModelsKilledByPlayerEii"); // CDarkel__QueryModelsKilledByPlayer_hook
    CHook::RET("_ZN7CDarkel27FindTotalPedsKilledByPlayerEi"); // CDarkel__FindTotalPedsKilledByPlayer_hook
    CHook::RET("_ZN7CDarkel20RegisterKillByPlayerEPK4CPed11eWeaponTypebi"); // CDarkel__RegisterKillByPlayer_hook

    CHook::NOP(g_libGTASA + 0x555A08, 1);	// CStreaming::ms_memoryAvailable = (int)v24


     CHook::NOP(g_libGTASA + 0x5B7C20, 1);  // CCamera::ClearPlayerWeaponMode from CPlayerPed::ClearWeaponTarget
    CHook::WriteMemory(g_libGTASA + 0x496200, "\x1F\x0D\x00\x71", 4); // RE3: Fix R* optimization that prevents peds to spawn

/*
 * //uncomplete
 * main address in 2.11 arm64 of openglaallinoneatomic is 0x7857F4
    // openglSkinAllInOneAtomicInstanceCB
    CHook::Write32(g_libGTASA + 0x785A28, ARMv8::MOVBits::Create(1, 27, false));
    CHook::NOP(g_libGTASA + 0x25C28C, 1);
    CHook::Write32(g_libGTASA + 0x25C290, ARMv8::MOVBits::Create(1, 27, false));

 */
    CHook::RET("_ZN10CPlayerPed14AnnoyPlayerPedEb"); // CPedSamp::AnnoyPlayerPed
    CHook::RET("_ZN11CPopulation15AddToPopulationEffff");    // CPopulation::AddToPopulation

    CHook::RET("_ZN23CAEPedSpeechAudioEntity11AddSayEventEisjfhhh"); // CPed::Say

    CHook::RET("_ZN10CPedGroups7ProcessEv"); // CPedGroups::Process
    CHook::RET("_ZN21CPedGroupIntelligence7ProcessEv"); // CPedGroupIntelligence::Process
    CHook::RET("_ZN19CPedGroupMembership9SetLeaderEP4CPed"); // CPedGroupMembership::SetLeader
    CHook::RET("_ZN21CPedGroupIntelligence5FlushEv"); // CPedGroupIntelligence::Flush

    CHook::RET("_ZN22CRealTimeShadowManager4InitEv"); // CRealTimeShadowManager::Init
    CHook::RET("_ZN22CRealTimeShadowManager6UpdateEv"); // CRealTimeShadowManager::Update

    CHook::RET("_ZN22CRealTimeShadowManager20ReturnRealTimeShadowEP15CRealTimeShadow"); // CRealTimeShadowManager::ReturnRealTimeShadow from ~CPhysical
    CHook::RET("_ZN8CShadows19RenderStaticShadowsEb"); // CShadows::RenderStaticShadows

    CHook::RET("_ZN8CMirrors16BeforeMainRenderEv"); // CMirrors::BeforeMainRender(void)
    CHook::RET("_ZN8CMirrors17RenderReflectionsEv"); // CMirrors::RenderReflections(void)

    CHook::RET("_ZN8CCarCtrl18GenerateRandomCarsEv"); // CCarCtrl::GenerateRandomCars(void)

    CHook::RET("_ZN10CGameLogic43SetPlayerWantedLevelForForbiddenTerritoriesEb"); // CGameLogic::SetPlayerWantedLevelForForbiddenTerritories

    CHook::RET("_ZN7CWanted14ReportCrimeNowE10eCrimeTypeRK7CVectorb"); // CWanted::ReportCrimeNow

    CHook::RET("_ZN8CCarCtrl18GenerateRandomCarsEv");
}
