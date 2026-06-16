#pragma once

#include "gta-reversed/game_sa/Core/Vector.h"
#include "gta-reversed/game_sa/Entity/CEntityGTA.h"

struct RemoveBuildingInfo {
    uint32_t modelId;
    CVector position;
    float radius;
};

class CBuildingRemoval {
public:
    static constexpr int MAX_REMOVALS = 1000;
    static inline RemoveBuildingInfo m_RemoveBuildings[MAX_REMOVALS];
    static inline int m_TotalRemovedObjects = 0;

public:
    static void AddRemoveBuilding(uint32_t modelId, const CVector& pos, float radius);
    static void ProcessRemoveBuilding(uint32_t modelId, const CVector& pos, float radius);
    static void RemoveOccluders(const CVector& position, float radius);

    static void RemoveBuildingByPtr(CEntityGTA* pEntity);
    static bool IsEntityValidForRemoval(CEntityGTA* entity);
    static bool DoesRemoveRuleMatch(uint32_t removeModelId, const CVector& removePos, float removeRadius, uint32_t entityModelId, const CVector& entityPos);
    static bool ShouldRemoveObjectInstance(uint32_t modelId, const CVector& pos);
    static bool ShouldRemoveEntity(CEntityGTA* entity, uint32_t removeModelId, const CVector& pos, float radius);
    static float GetDistanceBetween3DPoints(const CVector* point1, const CVector* point2);

    // Helper template for pool processing
    template <typename PoolT>
    static void RemoveBuildingsInPool(PoolT* pool, uint32_t uiModel, const CVector& pos, float radius);
};
