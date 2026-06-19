//
// Created on 25.04.2024.
//

#pragma once

#include "gta-reversed/game_sa/common.h"
#include "gta-reversed/game_sa/RenderWare/RenderWare.h"

class CCarFXRenderer {
public:
    static void InjectHooks();

    static bool RegisterPlugins();

    static bool Initialise();
    static void InitialiseDirtTexture();
    static void Shutdown();
    static void PreRenderUpdate();

    static bool IsCCPCPipelineAttached(RpAtomic* atomic);

    static void CustomCarPipeAtomicSetup(RpAtomic* atomic);
    static void CustomCarPipeClumpSetup(RpClump* clump);

    static RpMaterial* MaterialRemapDirtCB(RpMaterial*, void*);
    static RpAtomic* AtomicRemapDirtCB(RpAtomic*, void*);
    static RpAtomic* SetCustomFXAtomicRenderPipelinesVMICB(RpAtomic* atomic, void* data);

    static float GetFxEnvMapLightMult();
    static void SetFxEnvMapLightMult(float multiplier);
};
