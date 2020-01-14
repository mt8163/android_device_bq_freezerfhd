#include <log/log.h>
#define LOG_TAG "AUDIO_SHIM"

ALOGI("libkarin: dlopen audio_shim");
extern "C" void _ZN7android11AudioSystem24getVoiceUnlockDLInstanceEv(void) {}
extern "C" void _ZN7android11AudioSystem23GetVoiceUnlockDLLatencyEv(void) {}
extern "C" void _ZN7android11AudioSystem17SetVoiceUnlockSRCEjj(void) {}
