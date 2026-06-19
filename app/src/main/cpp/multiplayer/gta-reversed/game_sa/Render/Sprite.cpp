#include "Sprite.h"
#include "vendor/patch/patch.h"

/* เพิ่มจาก sasamp-main: CSprite::CalcScreenCoors */
bool CSprite::CalcScreenCoors(const RwV3d& posn, RwV3d* out, float* w, float* h, bool checkMaxVisible, bool checkMinVisible)
{
    return CHook::CallFunction<bool>(g_libGTASA + 0x5F449C, &posn, out, w, h, checkMaxVisible, checkMinVisible);
}

/* เพิ่มจาก sasamp-main: CSprite::RenderOneXLUSprite */
void CSprite::RenderOneXLUSprite(CVector pos, float sizeX, float sizeY, uint8 r, uint8 g, uint8 b, int16 intensity, float rhw, uint8 alpha, uint8 udir, uint8 vdir)
{
    CHook::CallFunction<void>(g_libGTASA + 0x5F4ACC, pos, sizeX, sizeY, r, g, b, intensity, rhw, alpha, udir, vdir, 0.0f, 0.0f);
}

/* เพิ่มจาก sasamp-main: CSprite::InitSpriteBuffer */
void CSprite::InitSpriteBuffer()
{
    CHook::CallFunction<void>(g_libGTASA + 0x5F475C);
}

/* เพิ่มจาก sasamp-main: CSprite::RenderBufferedOneXLUSprite_Rotate_Dimension */
void CSprite::RenderBufferedOneXLUSprite_Rotate_Dimension(float x, float y, float z, float sizeX, float sizeY, uint8 r, uint8 g, uint8 b, int16 intensity, float rz, float rotation, uint8 alpha)
{
    CHook::CallFunction<void>(g_libGTASA + 0x5F5474, x, y, z, sizeX, sizeY, r, g, b, intensity, rz, rotation, alpha);
}

/* เพิ่มจาก sasamp-main: CSprite::RenderBufferedOneXLUSprite */
void CSprite::RenderBufferedOneXLUSprite(float screenX, float screenY, float screenZ, float sizeX, float sizeY, uint8 r, uint8 g, uint8 b, int16 intensity, float recipNearZ, uint8 alpha)
{
    CHook::CallFunction<void>(g_libGTASA + 0x5F47E0, screenX, screenY, screenZ, sizeX, sizeY, r, g, b, intensity, recipNearZ, alpha);
}

/* เพิ่มจาก sasamp-main: CSprite::FlushSpriteBuffer */
void CSprite::FlushSpriteBuffer()
{
    CHook::CallFunction<void>(g_libGTASA + 0x5F46B0);
}

/* เพิ่มจาก sasamp-main: CSprite::RenderBufferedOneXLUSprite2D */
void CSprite::RenderBufferedOneXLUSprite2D(float posX, float posY, float sizeX, float sizeY, const CRGBA* color, int16 intensity, uint8 alpha)
{
    CHook::CallFunction<void>(g_libGTASA + 0x5F61E4, posX, posY, sizeX, sizeY, color, intensity, alpha);
}

/* เพิ่มจาก sasamp-main: CSprite::InitSpriteBuffer2D */
void CSprite::InitSpriteBuffer2D()
{
    CHook::CallFunction<void>(g_libGTASA + 0x5F478C);
}

/* เพิ่มจาก sasamp-main: CSprite::Initialise */
void CSprite::Initialise()
{
    CHook::CallFunction<void>(g_libGTASA + 0x5F4494);
}

/* เพิ่มจาก sasamp-main: CSprite::Draw3DSprite */
void CSprite::Draw3DSprite(float x, float y, float z, float sizeX, float sizeY, float u1, float v1, float u2, float v2)
{
    CHook::CallFunction<void>(g_libGTASA + 0x5F4498, x, y, z, sizeX, sizeY, u1, v1, u2, v2);
}

/* เพิ่มจาก sasamp-main: CSprite::CalcHorizonCoors */
float CSprite::CalcHorizonCoors()
{
    return CHook::CallFunction<float>(g_libGTASA + 0x5F4608);
}

/*
รอ MAP 2.11: CSprite::InjectHooks
*/
void CSprite::InjectHooks()
{
}
