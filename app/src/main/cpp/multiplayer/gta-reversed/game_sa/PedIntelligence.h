//
// Created by x1y2z on 07.04.2023.
//

#pragma once

#include "samp/main.h"
#include "gta-reversed/game_sa/Tasks/TaskManager.h"
#include "gta-reversed/game_sa/Events/EventHandler.h"
#include "gta-reversed/game_sa/Events/EventGroup.h"

class CTaskSimpleJetPack;
class CTaskSimpleUseGun;
class CTaskSimpleDuck;

class CPedIntelligence
{
public:
    class CPedGTA* m_pPed;
    CTaskManager   m_TaskMgr;
    CEventHandler  m_eventHandler;
    CEventGroup    m_eventGroup;

    int     m_iDecisionMakerType;
    int     m_iDecisionMakerTypeInGroup;
    float   m_fHearingRange;
    float   m_fSeeingRange;

    int     m_iMaxNumFriendsToInform;
    float   m_fMaxInformFriendDistance;
    float   m_fFollowNodeThresholdDistance;

    int8    m_iNextEventResponseSequence;
    uint8   m_iHighestPriorityEventType;
    uint8   m_iHighestPriorityEventPriority;
    uint8   pad0;

    uint8   pad1[0x2C8];

public:
    static void InjectHooks();

    CPedIntelligence(CPedGTA* ped);
    ~CPedIntelligence();

    void Process();
    void FlushImmediately(bool bSetPrimaryDefaultTask);

    void FlushIntelligence();
    void ProcessAfterProcCol();
    void ProcessAfterPreRender();

    CTaskSimpleJetPack* GetTaskJetPack();
    CTaskSimpleUseGun* GetTaskUseGun();
    CTaskSimpleDuck* GetTaskDuck(bool bIgnoreCheckingForSimplestActiveTask = true);
};
VALIDATE_SIZE(CPedIntelligence, 0x440);

