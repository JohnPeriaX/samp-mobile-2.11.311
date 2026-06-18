//
// Created by x1y2z on 27.04.2023.
//

#include "Vector.h"
#include "Vector2D.h"

CVector2D::CVector2D(const CVector& v3) :
        CVector2D{v3.x, v3.y}
{
}

/* เพิ่มจาก sasamp-main: Normalise */
void CVector2D::Normalise(float *outMag) {
    const auto mag = Magnitude();
    if (mag > 0.0f) {
        const auto recip = 1.0f / mag;
        x *= recip;
        y *= recip;
    } else {
        x = 1.0f;
    }

    if (outMag) {
        *outMag = mag;
    }
}
