//
// Created by Traw-GG on 13.07.2025.
//
#pragma once

#include "gta-reversed/game_sa/common.h"
#include "gta-reversed/game_sa/Core/Vector.h"

#include "gta-reversed/game_sa/Audio/managers/AESoundManager.h"
#include "gta-reversed/game_sa/Audio/loaders/AEMP3BankLoader.h"

union CAEAudioHardwarePlayFlags {
    uint16 m_nFlags{};
    struct {
        uint16 m_bIsFrontend : 1;
        uint16 m_bIsUncompressable : 1;
        uint16 m_bIsUnduckable : 1;
        uint16 m_bIsStartPercentage : 1;
        uint16 m_bIsMusicMastered : 1;
        uint16 : 1;
        uint16 m_bIsRolledOff : 1;
        uint16 m_bIsSmoothDucking : 1;

        uint16 m_bIsForcedFront : 1;
        uint16 m_bUnpausable : 1;
    };

    void CopyFromAESound(const CAESound& sound) {
        m_bIsFrontend        = sound.GetFrontEnd();
        m_bIsUncompressable  = sound.GetUncompressable();
        m_bIsUnduckable      = sound.GetUnduckable();
        m_bIsStartPercentage = sound.GetStartPercentage();
        m_bIsMusicMastered   = sound.GetMusicMastered();
        m_bIsRolledOff       = sound.GetRolledOff();
        m_bIsSmoothDucking   = sound.GetSmoothDucking();
        m_bIsForcedFront     = sound.GetForcedFront();
        m_bUnpausable        = m_bIsFrontend ? sound.GetUnpausable() : false;
    }
};

class CAEAudioHardware {
public:
    uint8                   audioHardware[0xD98];

public:
    static void InjectHooks();

    void LoadSoundBank(uint16 bankId, int16 bankSlotId);
    bool IsSoundBankLoaded(uint16 bankId, int16 bankSlotId);
    void RequestVirtualChannelSoundInfo(uint16 idx, uint16 sfxId, uint16 bankSlotId);

    static inline CAEAudioHardware* AEAudioHardware;
    static CAEAudioHardware* getAEAudioHardware() {
        /*
        รอ MAP 2.11: CAEAudioHardware global instance
        sasamp-main 64-bit candidate was g_libGTASA + 0xBA9640
        */
        return AEAudioHardware;
    }
};
VALIDATE_SIZE(CAEAudioHardware, 0xD98);
