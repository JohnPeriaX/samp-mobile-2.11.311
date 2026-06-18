//
// Created by x1y2z on 15.11.2023.
//

#include "Renderer.h"
#include "vendor/patch/patch.h"

void CRenderer::InjectHooks() {
    // 2.11 arm64 LST verified:
    // m_loadingPriority GOT     = g_libGTASA + 0x838330
    // ms_fFarClipPlane GOT      = g_libGTASA + 0x838348
    // ms_bRenderOutsideTunnels  = g_libGTASA + 0x838338
    CHook::Write(g_libGTASA + 0x838338, &ms_bRenderOutsideTunnels);
    CHook::Write(g_libGTASA + 0x838330, &m_loadingPriority);
    CHook::Write(g_libGTASA + 0x838348, &ms_fFarClipPlane);

    CHook::Write(g_libGTASA + 0x83A488, &ms_aVisibleEntityPtrs);
    CHook::Write(g_libGTASA + 0x83A438, &ms_nNoOfVisibleEntities);
}
