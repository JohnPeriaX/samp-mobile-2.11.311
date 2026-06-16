//
// Created by x1y2z on 03.08.2023.
//

#include "VisibilityPlugins.h"
#include "vendor/patch/patch.h"

namespace {
constexpr uintptr_t kMsCameraPosnGot = 0x83C940;
constexpr uintptr_t kMsPedLodDistGot = 0x83C990;
constexpr uintptr_t kMsPedFadeDistGot = 0x83C9A8;
}

void CVisibilityPlugins::Initialise() {
    CHook::CallFunction<void>(g_libGTASA + 0x6032E0);
}

void CVisibilityPlugins::SetRenderWareCamera(RwCamera* camera) {
    CHook::CallFunction<void>(g_libGTASA + 0x605790, camera);
}

RpAtomic* CVisibilityPlugins::RenderPedCB(RpAtomic* atomic) {
    const float distanceSquared = GetDistanceSquaredFromCamera(RpAtomicGetFrame(atomic));
    if (distanceSquared >= ms_pedLodDist)
        return atomic;

    int32 alpha = GetClumpAlpha(RpAtomicGetClump(atomic));
    if (alpha == 255) {
        AtomicDefaultRenderCallBack(atomic);
        return atomic;
    }
    RenderAlphaAtomic(atomic, alpha);
    return atomic;
}

float CVisibilityPlugins::GetDistanceSquaredFromCamera(RwFrame* frame) {
    RwMatrix* transformMatrix = RwFrameGetLTM(frame);
    CVector distance;
    RwV3dSub(&distance, &transformMatrix->pos, ms_pCameraPosn);
    return distance.SquaredMagnitude();
}


int32 CVisibilityPlugins::GetClumpAlpha(RpClump* clump) {
    return CHook::CallFunction<int32>(g_libGTASA + 0x604310, clump);
}

void CVisibilityPlugins::RenderAlphaAtomic(RpAtomic* atomic, int32 alpha) {
    CHook::CallFunction<void>(g_libGTASA + 0x606350, atomic, alpha);
}

void CVisibilityPlugins::InjectHooks() {
    // 2.11 arm64 LST verified:
    // ms_pCameraPosn GOT = g_libGTASA + 0x83C940
    // ms_pedLodDist GOT = g_libGTASA + 0x83C990
    // ms_pedFadeDist GOT = g_libGTASA + 0x83C9A8
    //
    // Mobile's native ped renderer reads these through the GOT. Pointing them
    // at the reversed variables keeps ped LOD/camera distance in sync with the
    // same path used by PC RenderPedCB, instead of leaving remote peds culled
    // while the SA-MP name tag UI still renders.
    CHook::Write(g_libGTASA + kMsPedLodDistGot, &CVisibilityPlugins::ms_pedLodDist);
    CHook::Write(g_libGTASA + kMsPedFadeDistGot, &CVisibilityPlugins::ms_pedFadeDist);
    CHook::Write(g_libGTASA + kMsCameraPosnGot, &CVisibilityPlugins::ms_pCameraPosn);
}

void CVisibilityPlugins::SetupVehicleVariables(RpClump *clump) {
    CHook::CallFunction<void>(g_libGTASA + 0x603B38, clump);
}

void CVisibilityPlugins::RenderReallyDrawLastObjects() {
    CHook::CallFunction<void>(g_libGTASA + 0x606584);
}

// The function name is misleading, it returns the flags
uint16 CVisibilityPlugins::GetAtomicId(RpAtomic* atomic) {
    return CHook::CallFunction<uint16>(g_libGTASA + 0x603AF0, atomic);
}
