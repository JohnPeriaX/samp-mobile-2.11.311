//
// Created by Traw-GG on 13.07.2025.
//
#pragma once

/* This class is used to control 2 sounds as one. There are 2 sounds
   created with PlayTwinLoopSound(), and one of them is playing when second
   is simply muted. When time m_nTimeToSwapSounds is reached, these sounds
   are switched: second starts playing, first begins being muted.
   The time m_nTimeToSwapSounds is calculated as:
   CAEAudioUtility::GetRandomNumberInRange(m_nPlayTimeMin, m_nPlayTimeMax);
   Notice these sounds must be situated in same bank slot.
   m_pBaseAudio is a pointer to audio which created twin sound. For example,
   this could be CAEVehicleAudioEntity for playing skid sounds.              */

#include "AEAudioEntity.h"

class CAETwinLoopSoundEntity : public CAEAudioEntity {
public:
    int16           m_nBankSlotId;
    int16           m_nSoundId1;
    int16           m_nSoundId2;
    CAEAudioEntity* m_pBaseAudio;
    int16           m_bIsInitialised;
    int16           unused_field_8A;
    int16           unused_field_8C;
    uint16          m_nPlayTimeMin;
    uint16          m_nPlayTimeMax;
    uint32          m_nTimeToSwapSounds;
    bool            m_bPlayingFirstSound;
    int16           m_nSoundPlayStart1; // 0 - 99 percentage
    int16           m_nSoundPlayStart2; // 0 - 99 percentage
    CAESound*       m_pSound1;
    CAESound*       m_pSound2;
};

VALIDATE_SIZE(CAETwinLoopSoundEntity, 0xC8);
