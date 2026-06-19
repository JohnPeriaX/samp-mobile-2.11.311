//
// Created by Traw-GG on 13.07.2025.
//
#pragma once

#include "gta-reversed/game_sa/Audio/AESound.h"
#include "gta-reversed/game_sa/Enums/eAudioEvents.h"

struct CEntityGTA;

class CAEAudioEntity {
public:
    CEntityGTA* m_pEntity;
    CAESound m_tempSound;

private:
    static inline int8* m_pAudioEventVolumes;

public:
    static void InjectHooks();

    virtual void UpdateParameters(CAESound* sound, int16 curPlayPos) { /* Empty on purpose */ };

    static float GetDefaultVolume(eAudioEvents event) { return m_pAudioEventVolumes ? static_cast<float>(m_pAudioEventVolumes[event]) : 0.0f; }
};

VALIDATE_SIZE(CAEAudioEntity, 0x90);
