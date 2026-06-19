//
// Created by Traw-GG on 13.07.2025.
//
#include "AEAudioHardware.h"
#include "vendor/patch/patch.h"

void CAEAudioHardware::InjectHooks() {
    /*
    รอ MAP 2.11: CAEAudioHardware::InjectHooks
    sasamp-main 64-bit candidate was g_libGTASA + 0xBA9640
    */
}

void CAEAudioHardware::LoadSoundBank(uint16 bankId, int16 bankSlotId) {
    CHook::CallFunction<void>("_ZN16CAEAudioHardware13LoadSoundBankEts", getAEAudioHardware(), bankId, bankSlotId);
}

bool CAEAudioHardware::IsSoundBankLoaded(uint16 bankId, int16 bankSlotId) {
    return CHook::CallFunction<bool>("_ZN16CAEAudioHardware17IsSoundBankLoadedEts", getAEAudioHardware(), bankId, bankSlotId);
}

void CAEAudioHardware::RequestVirtualChannelSoundInfo(uint16 idx, uint16 sfxId, uint16 bankSlotId) {
    CHook::CallFunction<void>("_ZN16CAEAudioHardware30RequestVirtualChannelSoundInfoEttt", getAEAudioHardware(), idx, sfxId, bankSlotId);
};