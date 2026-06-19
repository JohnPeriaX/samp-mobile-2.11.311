#pragma once

#include "gta-reversed/game_sa/RenderWare/RenderWare.h"
#include "gta-reversed/game_sa/RGBA.h"
#include "gta-reversed/game_sa/common.h"

class CSprite {
public:
    static void InjectHooks();

    static void Initialise();
    static void InitSpriteBuffer();
    static void InitSpriteBuffer2D();
    static void FlushSpriteBuffer();

    static void RenderBufferedOneXLUSprite2D(float posX, float posY, float sizeX, float sizeY, const CRGBA* color, int16 intensity, uint8 alpha);
    static void RenderBufferedOneXLUSprite(float screenX, float screenY, float screenZ, float sizeX, float sizeY, uint8 r, uint8 g, uint8 b, int16 intensity, float recipNearZ, uint8 alpha);
    static void RenderOneXLUSprite(CVector pos, float sizeX, float sizeY, uint8 r, uint8 g, uint8 b, int16 intensity, float rhw, uint8 alpha, uint8 udir, uint8 vdir);
    static void RenderBufferedOneXLUSprite_Rotate_Dimension(float x, float y, float z, float sizeX, float sizeY, uint8 r, uint8 g, uint8 b, int16 intensity, float rz, float rotation, uint8 alpha);
    static void Draw3DSprite(float x, float y, float z, float sizeX, float sizeY, float u1, float v1, float u2, float v2);

    static bool  CalcScreenCoors(const RwV3d& posn, RwV3d* out, float* w, float* h, bool checkMaxVisible, bool checkMinVisible);
    static float CalcHorizonCoors();
};
