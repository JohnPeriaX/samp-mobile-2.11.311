//
// Created by x1y2z on 23.11.2023.
//

#include "NodeName.h"
#include "vendor/patch/patch.h"

/* เพิ่มจาก sasamp-main: NodeNamePluginAttach */
RwBool NodeNamePluginAttach() {
    return CHook::CallFunction<RwBool>(g_libGTASA + 0x6017FC);
}

/* เพิ่มจาก sasamp-main: GetFrameNodeName */
const RwChar* GetFrameNodeName(RwFrame* frame) {
    return CHook::CallFunction<const RwChar*>(g_libGTASA + 0x6019AC, frame);
}

/* เพิ่มจาก sasamp-main: SetFrameNodeName */
void SetFrameNodeName(RwFrame* frame, const RwChar* name) {
    CHook::CallFunction<void>(g_libGTASA + 0x60197C, frame, name);
}
