#include <stdint.h>
#include <utils/Log.h>
#include <binder/IServiceManager.h>
#include <media/AudioSystem.h>
#include <media/IAudioFlinger.h>
#include <media/IAudioPolicyService.h>
#include <system/audio.h>

extern "C" {
    bool _ZN7android11AudioSystem24getVoiceUnlockDLInstanceEv(){
        return 0;
    }
    
    int _ZN7android11AudioSystem23GetVoiceUnlockDLLatencyEv(){
        return 0;
    }
 
    int _ZN7android11AudioSystem17SetVoiceUnlockSRCEjj(uint32_t outSR, uint32_t outChannel){
        return 0;
    }

    bool _ZN7android11AudioSystem18startVoiceUnlockDLEv(){
        return 0;
    }
 
    int _ZN7android11AudioSystem15ReadRefFromRingEPvjS1_(void*buf, uint32_t datasz, void* DLtime){
        return 0;
    }
    
    status_t AudioSystem::SetAudioData(int par1, size_t byte_len,void *ptr) {
         ALOGD("SetAudioData");
         const sp<IAudioFlinger>& af = AudioSystem::get_audio_flinger();
         if (af == 0)
         {
             ALOGE("AudioSystem::SetAAudioData Error!! PERMISSION_DENIED");
            return PERMISSION_DENIED;
         }
         return af->SetAudioData(par1,byte_len,ptr);
    }
    
    int _ZN7android11AudioSystem20GetVoiceUnlockULTimeEPv(void* DLtime) {
        return 0;
    }

    void _ZN7android11AudioSystem25freeVoiceUnlockDLInstanceEv(){}

    bool _ZN7android11AudioSystem17stopVoiceUnlockDLEv(){
        return 0;
    }
    
}

