//
// Created by Traw-GG on 13.07.2025.
//
#pragma once
#include "AEBankLoader.h"

#include <algorithm>
#include <optional>
#include <ranges>

struct tVirtualChannelSettings {
    eSoundBankSlot BankSlotIDs[300]{};
    tSoundID       SoundIDs[300]{};

    tVirtualChannelSettings() {
        std::ranges::fill(BankSlotIDs, SND_BANK_SLOT_UNK);
        std::ranges::fill(SoundIDs, -1);
    }
};
VALIDATE_SIZE(tVirtualChannelSettings, 0x4B0);

class CAEMP3BankLoader : public CAEBankLoader {
public:
    static void InjectHooks();

    CAEMP3BankLoader() = default;

    bool   Initialise();
    uint8* GetBankSlotBuffer(eSoundBankSlot bankSlot, uint32& outLength);
    float  GetSoundHeadroom(tSoundID soundId, eSoundBankSlot bankSlot);
    bool   IsSoundBankLoaded(eSoundBank bankId, eSoundBankSlot bankSlot);
    bool   GetSoundBankLoadingStatus(eSoundBank bankId, eSoundBankSlot bankSlot);
    uint8* GetSoundBuffer(tSoundID soundId, eSoundBankSlot bankSlot, uint32& outIndex, uint16& outSampleRate);
    int32  GetLoopOffset(tSoundID soundId, eSoundBankSlot bankSlot);
    bool   IsSoundLoaded(eSoundBank bankId, tSoundID soundId, eSoundBankSlot bankSlot) const;
    bool   GetSoundLoadingStatus(eSoundBank bankId, tSoundID soundId, eSoundBankSlot bankSlot);
    void   UpdateVirtualChannels(tVirtualChannelSettings* settings, int16* lengths, int16* loopStartTimes);
    void   LoadSoundBank(eSoundBank bankId, eSoundBankSlot bankSlot);
    void   LoadSound(eSoundBank bankId, tSoundID soundId, eSoundBankSlot bankSlot);
    void   Service();

private:
    void AddRequest(eSoundBank bank, eSoundBankSlot slot, std::optional<tSoundID> sound);
};
//VALIDATE_SIZE(CAEMP3BankLoader, 0x6E4);
