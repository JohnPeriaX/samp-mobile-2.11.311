//
// Created by x1y2z on 01.07.2023.
//

#include "ColStore.h"
#include "vendor/patch/patch.h"
#include "gta-reversed/game_sa/constants.h"

void CColStore::RequestCollision(const CVector *pos, int32 areaCode) {

}

void CColStore::RemoveCol(int32 colSlot)
{
   CHook::CallFunction<void>(g_libGTASA + 0x3C1E4C, colSlot);
}

void CColStore::AddCollisionNeededAtPosn(const CVector *pos) {
   CHook::CallFunction<void>(g_libGTASA + 0x3C2120, pos);
}

void CColStore::LoadCollision(CVector pos, bool bIgnorePlayerVeh)
{
   CHook::CallFunction<void>(g_libGTASA + 0x3C2340, pos, bIgnorePlayerVeh);
}

void CColStore::EnsureCollisionIsInMemory(const CVector* pos)
{
   CHook::CallFunction<void>(g_libGTASA + 0x3C26B8, pos);
}

/*
รอ MAP 2.11: CColStore::AddColSlot
int32 CColStore::AddColSlot(const char* name)
{
    return CHook::CallFunction<int32>("_ZN9CColStore10AddColSlotEPKc", name);
}
*/

void CColStore::Initialise()
{
    CHook::CallFunction<void>(g_libGTASA + 0x3C1828);

    /*
    รอ MAP 2.11: CColStore::Initialise จาก sasamp-main
    bool& ms_bCollisionNeeded = *(bool*)(g_libGTASA + 0x9760B8);

    const auto rect = CRect(-3000.0F, -3000.0F, 3000.0F, 3000.0F);
    ms_bCollisionNeeded = false;

    if (!ms_pColPool)
        ms_pColPool = new CColPool(TOTAL_COL_MODEL_IDS, "CollisionFiles");

    AddColSlot("generic");
    ms_pQuadTree = new CQuadTreeNode(rect, 3);
    */
}

/*
รอ MAP 2.11: CColStore::InjectHooks
void CColStore::InjectHooks()
{
    CHook::Write(g_libGTASA + 0x850CD0, &ms_pColPool);
    CHook::Write(g_libGTASA + 0x851EA0, &ms_pQuadTree);
}
*/
