//
// Created by Traw-GG on 13.07.2025.
//
#include "AESoundManager.h"
#include "vendor/patch/patch.h"

bool CAESoundManager::Initialise() {
    /*const auto availChannels = AEAudioHardware.GetNumAvailableChannels();
    if (availChannels <= 10) {
        return false;
    }

    m_NumAllocatedPhysicalChannels = availChannels >= MAX_NUM_SOUNDS ? MAX_NUM_SOUNDS : availChannels;
    m_AudioHardwareHandle       = AEAudioHardware.AllocateChannels(m_NumAllocatedPhysicalChannels);
    if (m_AudioHardwareHandle == -1) {
        return false;
    }

    // BUG? There's some int16 weird logic in the original code, I simplified it to what's actually used i think
    m_PhysicallyPlayingSoundList = new tSoundReference[m_NumAllocatedPhysicalChannels];
    m_ChannelPosition            = new int16[m_NumAllocatedPhysicalChannels];
    m_PrioritisedSoundList       = new tSoundReference[m_NumAllocatedPhysicalChannels];

    for (CAESound& sound : m_VirtuallyPlayingSoundList) {
        sound.m_nIsUsed             = 0;
        sound.m_IsPhysicallyPlaying = 0;
    }

    std::fill_n(m_PhysicallyPlayingSoundList, m_NumAllocatedPhysicalChannels, -1);

    m_TimeLastCalled         = CTimer::GetTimeInMS();
    m_WasGamePausedLastFrame = false;
    m_TimeLastCalledUnpaused = 0;
    m_IsManuallyPaused       = false;*/
    return true;
}

CAESound* CAESoundManager::RequestNewSound(CAESound* pSound) {
    return CHook::CallFunction<CAESound*>("_ZN15CAESoundManager15RequestNewSoundEP8CAESound", getAESoundManager(), pSound);
    /*size_t sidx;
    auto   s = GetFreeSound(&sidx);
    if (s) {
        *s = *pSound;
        pSound->UnregisterWithPhysicalEntity();
        s->NewVPSLentry();
        CAEAudioHardware::AEAudioHardware->RequestVirtualChannelSoundInfo((uint16)sidx, s->m_nSoundIdInSlot, s->m_nBankSlotId);
    }
    return s;*/
}

CAESound* CAESoundManager::PlaySound(tSoundPlayParams p) {
    if (p.RegisterWithEntity) {
        p.Flags |= SOUND_LIFESPAN_TIED_TO_PHYSICAL_ENTITY;
    }
    CAESound s{};
    s.Initialise(
            p.BankSlotID,
            p.SoundID,
            p.AudioEntity,
            p.Pos,
            p.Volume,
            p.RollOffFactor,
            p.Speed,
            p.Doppler,
            p.FrameDelay,
            p.Flags,
            p.FrequencyVariance,
            p.PlayTime
    );
    s.m_nEvent         = p.EventID;
    s.m_ClientVariable = p.ClientVariable;
    if (p.Flags & SOUND_LIFESPAN_TIED_TO_PHYSICAL_ENTITY) {
        s.RegisterWithPhysicalEntity(p.RegisterWithEntity);
    }
    return RequestNewSound(&s);
}

void CAESoundManager::InjectHooks() {
    /*
    รอ MAP 2.11: CAESoundManager::InjectHooks
    sasamp-main 64-bit candidate was g_libGTASA + 0xBAC900
    */
}