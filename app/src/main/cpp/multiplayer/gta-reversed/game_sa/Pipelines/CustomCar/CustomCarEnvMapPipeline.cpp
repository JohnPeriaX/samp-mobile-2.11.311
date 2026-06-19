//
// Created by x1y2z on 27.04.2024.
//

#include "CustomCarEnvMapPipeline.h"
#include "vendor/patch/patch.h"
#include "gta-reversed/game_sa/RenderWare/pipe/p2core.h"
#include "gta-reversed/game_sa/RenderWare/pipe/p2define.h"
#include "gta-reversed/game_sa/RenderWare/opengl/openglpipepriv.h"

// Android - CreateCustomOpenGLObjPipe
RxPipeline* CCustomCarEnvMapPipeline::CreateCustomObjPipe() {
    return CHook::CallFunction<RxPipeline*>("_ZN24CCustomCarEnvMapPipeline25CreateCustomOpenGLObjPipeEv");
//    auto pipeline = RxPipelineCreate();
//    if (!pipeline)
//        return nullptr;
//
//    auto lock = RxPipelineLock(pipeline);
//    if (lock) {
//        auto nodeDefinition = RxNodeDefinitionGetOpenGLAtomicAllInOne();
//        auto lockedPipe = RxLockedPipeAddFragment(lock, 0, nodeDefinition);
//        if (RxLockedPipeUnlock(lockedPipe)) {
//            auto node = RxPipelineFindNodeByName(pipeline, nodeDefinition->name, nullptr, nullptr);
//            RxOpenGLAllInOneSetInstanceCallBack(node, CCustomCarEnvMapPipeline::CustomPipeInstanceCB);
//           // RxD3D9AllInOneSetReinstanceCallBack(node, CustomPipeInstanceCB);
//            RxOpenGLAllInOneSetRenderCallBack(node, (RxOpenGLAllInOneRenderCallBack)CCustomCarEnvMapPipeline::CustomPipeRenderCB);
//            pipeline->pluginId = CUSTOM_CAR_ENV_MAP_PIPELINE_PLUGIN_ID;
//            pipeline->pluginData = CUSTOM_CAR_ENV_MAP_PIPELINE_PLUGIN_ID;
//            return pipeline;
//        }
//    }
//    _rxPipelineDestroy(pipeline);
//    return nullptr;
}


bool CCustomCarEnvMapPipeline::CreatePipe() {
    ObjPipeline = CreateCustomObjPipe();
    if (!ObjPipeline /*|| !IsEnvironmentMappingSupported()*/) {
        return false;
    }
  //  memset(&g_GameLight, 0, sizeof(g_GameLight));
    m_gEnvMapPipeMatDataPool = new CustomEnvMapPipeMaterialDataPool(4096, "CustomEnvMapPipeMatDataPool");
    m_gEnvMapPipeAtmDataPool = new CustomEnvMapPipeAtomicDataPool(1024, "CustomEnvMapPipeAtmDataPool");
    m_gSpecMapPipeMatDataPool = new CustomSpecMapPipeMaterialDataPool(4096, "CustomSpecMapPipeMaterialDataPool");
    return true;
}


// x64 fixes
RwBool (*openglAtomicAllInOnePipelineInit)(RxPipelineNode *node);
RwBool openglAtomicAllInOnePipelineInit_hooked(RxPipelineNode *node)
{
    node->privateData = new _rxOpenGLAllInOnePrivateData;

    return openglAtomicAllInOnePipelineInit(node);
}

RwBool (*openglWorldSectorAllInOnePipelineInit)(RxPipelineNode *node);
RwBool openglWorldSectorAllInOnePipelineInit_hooked(RxPipelineNode *node)
{
    node->privateData = new _rxOpenGLAllInOnePrivateData;

    return openglWorldSectorAllInOnePipelineInit(node);
}

RpMaterial* CCustomCarEnvMapPipeline__CustomPipeMaterialSetup(RpMaterial* material, void* data)
{
    auto& flags = reinterpret_cast<uint32_t&>(material->surfaceProps.specular);

    flags = 0u;

    if (CHook::CallFunction<RpMatFXMaterialFlags>("_Z25RpMatFXMaterialGetEffectsPK10RpMaterial", material) == rpMATFXEFFECTENVMAP) // RpMatFXMaterialGetEffects
    {
        CHook::CallFunction<void>("_ZN25CCustomBuildingDNPipeline15SetFxEnvTextureEP10RpMaterialP9RwTexture", material, nullptr); // CCustomCarEnvMapPipeline::SetFxEnvTexture
    }

    if (CHook::CallFunction<float>("_ZN24CCustomCarEnvMapPipeline17GetFxEnvShininessEP10RpMaterial", material) != 0.0f) // CCustomCarEnvMapPipeline::GetFxEnvShininess
    {
        if (const auto tex = CHook::CallFunction<RwTexture*>("_ZN24CCustomCarEnvMapPipeline15GetFxEnvTextureEP10RpMaterial", material)) // CCustomCarEnvMapPipeline::GetFxEnvTexture
        {
            flags |= RwTextureGetName(tex)[0] == 'x' ? 0b10 : 0b01;
        }
    }

    auto getFxSpecSpecularity = CHook::CallFunction<float>("_ZN24CCustomCarEnvMapPipeline20GetFxSpecSpecularityEP10RpMaterial", material); // CCustomCarEnvMapPipeline::GetFxSpecSpecularity
    auto* getFxSpecTexture = CHook::CallFunction<RwTexture*>("_ZN24CCustomCarEnvMapPipeline16GetFxSpecTextureEP10RpMaterial", material); // CCustomCarEnvMapPipeline::GetFxSpecTexture
    if (getFxSpecSpecularity != 0.0f && getFxSpecTexture)
    {
        flags |= 0b100;
    }

    return material;
}

void CCustomCarEnvMapPipeline::InjectHooks() {
    /* เพิ่มจาก sasamp-main: CCustomCarEnvMapPipeline::InjectHooks */
    CHook::InlineHook(g_libGTASA + 0x7423C4, &openglWorldSectorAllInOnePipelineInit_hooked, &openglWorldSectorAllInOnePipelineInit);
    CHook::InlineHook(g_libGTASA + 0x741A7C, &openglAtomicAllInOnePipelineInit_hooked, &openglAtomicAllInOnePipelineInit);

    CHook::Write(g_libGTASA + 0x8377B0, &ObjPipeline);
    CHook::Write(g_libGTASA + 0x8377A8, &m_gEnvMapPipeMatDataPool);
    CHook::Write(g_libGTASA + 0x8377E8, &m_gEnvMapPipeAtmDataPool);
    CHook::Write(g_libGTASA + 0x8377F0, &m_gSpecMapPipeMatDataPool);
}

RwBool CCustomCarEnvMapPipeline::CustomPipeInstanceCB(void *object, RxOpenGLMeshInstanceData *instanceData, const RwBool instanceDLandVA, const RwBool reinstance) {
    return CHook::CallFunction<RwBool>("_ZN24CCustomCarEnvMapPipeline20CustomPipeInstanceCBEPvP24RxOpenGLMeshInstanceDataii", object, instanceData, instanceDLandVA, reinstance);
}

void CCustomCarEnvMapPipeline::CustomPipeRenderCB(RwResEntry *repEntry, void *object, RwUInt8 type, RwUInt32 flags) {
    return CHook::CallFunction<void>("_ZN24CCustomCarEnvMapPipeline18CustomPipeRenderCBEP10RwResEntryPvhj", repEntry, object, type, flags);
}
