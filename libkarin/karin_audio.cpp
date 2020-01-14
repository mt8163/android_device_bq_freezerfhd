#include <log/log.h>
#include <stdint.h>

extern "C" {
   bool _ZN7android11AudioSystem24getVoiceUnlockDLInstanceEv(){
       ALOGI("libkarin: dlopen _ZN7android11AudioSystem24getVoiceUnlockDLInstanceEv\n");
       return 0;
       }
   int _ZN7android11AudioSystem23GetVoiceUnlockDLLatencyEv(){
       ALOGI("libkarin: dlopen _ZN7android11AudioSystem23GetVoiceUnlockDLLatencyEv\n");
       return 0;
       }
   int _ZN7android11AudioSystem17SetVoiceUnlockSRCEjj(uint32_t outSR, uint32_t outChannel){
       ALOGI("libkarin: dlopen _ZN7android11AudioSystem17SetVoiceUnlockSRCEjj\n");
       return 0;
       }
}
