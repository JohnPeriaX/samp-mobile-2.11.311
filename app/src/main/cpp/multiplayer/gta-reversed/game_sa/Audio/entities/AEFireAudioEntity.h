//
// Created by Traw-GG on 13.07.2025.
//
#pragma once

#include "AEAudioEntity.h"

class FxSystem_c;

class CAEFireAudioEntity : public CAEAudioEntity {
public:
    CAESound*   m_SoundLeft;
    CAESound*   m_SoundRight;
    FxSystem_c* m_FxSystem;

    static uint8& m_snLastFireFrequencyIndex;

public:
    static void InjectHooks();

};
VALIDATE_SIZE(CAEFireAudioEntity, 0xA8);