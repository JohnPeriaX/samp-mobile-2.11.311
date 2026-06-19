//
// Created by x1y2z on 11.04.2023.
//

#include "RenderWare.h"
#include "gta-reversed/game_sa/common.h"
#include "vendor/patch/patch.h"

RpClump* RpClumpForAllAtomics(RpClump* clump, RpAtomicCallBack callback, void* data) {
    if(clump)
        return CHook::CallFunction<RpClump*>(g_libGTASA + 0x746E20, clump, callback, data);
}

RpGeometry* RpGeometryForAllMaterials(RpGeometry* geometry, RpMaterialCallBack fpCallBack, void* data) {
    return CHook::CallFunction<RpGeometry*>(g_libGTASA + 0x749D7C, geometry, fpCallBack, data);
}

RwBool RpClumpDestroy(RpClump* clump) {
    return CHook::CallFunction<RwBool>(g_libGTASA + 0x7478C4, clump);
}

RpClump* RpClumpRender(RpClump* clump) {
    return CHook::CallFunction<RpClump*>("_Z13RpClumpRenderP7RpClump", clump);
}

RpLight* RpLightCreate(RwInt32 type) {
    return CHook::CallFunction<RpLight*>(g_libGTASA + 0x74B110, type);
}

RwBool RpLightDestroy(RpLight* light) {
    return CHook::CallFunction<RwBool>(g_libGTASA + 0x74B2C4, light);
}

RpWorld* RpWorldCreate(RwBBox* boundingBox) {
    return CHook::CallFunction<RpWorld*>(g_libGTASA + 0x7537C8, boundingBox);
}

RpWorld* RpWorldAddCamera(RpWorld* world, RwCamera* camera) {
    return CHook::CallFunction<RpWorld*>(g_libGTASA + 0x754A30, world, camera);
}

RpLight* RpLightSetColor(RpLight* light, const RwRGBAReal* color) {
    return CHook::CallFunction<RpLight*>(g_libGTASA + 0x74A96C, light, color);
}

RpAtomic* AtomicDefaultRenderCallBack(RpAtomic* atomic) {
    return CHook::CallFunction<RpAtomic*>(g_libGTASA + 0x7468FC, atomic);
}

RpWorld* RpWorldAddLight(RpWorld* world, RpLight* light) {
    return CHook::CallFunction<RpWorld*>(g_libGTASA + 0x7557EC, world, light);
}

RpWorld* RpWorldRemoveLight(RpWorld* world, RpLight* light) {
    return CHook::CallFunction<RpWorld*>(g_libGTASA + 0x755858, world, light);
}

RwBool RpAtomicDestroy(RpAtomic* atomic) {
    return CHook::CallFunction<RwBool>(g_libGTASA + 0x74731C, atomic);
}

void RpClumpGtaCancelStream() {
    CHook::CallFunction<void>(g_libGTASA + 0x5FF320);
}

/* เพิ่มจาก sasamp-main: RwTexDictionaryRemoveTexture */
RwTexture* RwTexDictionaryRemoveTexture(RwTexture* texture) {
    return CHook::CallFunction<RwTexture*>(g_libGTASA + 0x76CD10, texture);
}

/* เพิ่มจาก sasamp-main: RwTexDictionaryForAllTextures */
RwTexDictionary* RwTexDictionaryForAllTextures(RwTexDictionary* dict, RwTextureCallBack fpCallBack, void* data) {
    return CHook::CallFunction<RwTexDictionary*>(g_libGTASA + 0x76C914, dict, fpCallBack, data);
}

/* เพิ่มจาก sasamp-main: RwTexDictionaryDestroy */
RwBool RwTexDictionaryDestroy(RwTexDictionary* dict) {
    return CHook::CallFunction<RwBool>(g_libGTASA + 0x76C858, dict);
}

/* เพิ่มจาก sasamp-main: RpMaterialSetTexture */
RpMaterial* RpMaterialSetTexture(RpMaterial* material, RwTexture* texture) {
    return CHook::CallFunction<RpMaterial*>(g_libGTASA + 0x74B6D4, material, texture);
}

/* เพิ่มจาก sasamp-main: RpClumpRemoveAtomic */
RpClump* RpClumpRemoveAtomic(RpClump* clump, RpAtomic* atomic) {
    return CHook::CallFunction<RpClump*>(g_libGTASA + 0x747A20, clump, atomic);
}

/* เพิ่มจาก sasamp-main: RpAtomicSetFrame */
RpAtomic* RpAtomicSetFrame(RpAtomic* atomic, RwFrame* frame) {
    return CHook::CallFunction<RpAtomic*>(g_libGTASA + 0x7473B0, atomic, frame);
}

/* เพิ่มจาก sasamp-main: RpAtomicInstance */
RwBool RpAtomicInstance(RpAtomic* atomic) {
    return CHook::CallFunction<RwBool>(g_libGTASA + 0x749068, atomic);
}

/* เพิ่มจาก sasamp-main: RwFrameTransform */
RwFrame* RwFrameTransform(RwFrame* frame, const RwMatrix* transform, RwOpCombineType combineOp) {
    return CHook::CallFunction<RwFrame*>(g_libGTASA + 0x768BB8, frame, transform, combineOp);
}

/* เพิ่มจาก sasamp-main: RpClumpStreamRead */
RpClump* RpClumpStreamRead(RwStream* stream) {
    return CHook::CallFunction<RpClump*>(g_libGTASA + 0x7488E0, stream);
}

/* เพิ่มจาก sasamp-main: RpAtomicClone */
RpAtomic* RpAtomicClone(RpAtomic* atomic) {
    return CHook::CallFunction<RpAtomic*>(g_libGTASA + 0x747550, atomic);
}
