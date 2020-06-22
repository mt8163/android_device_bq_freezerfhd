#include <media/AudioSystem.h>

/* audio.primary.mt8163.so (main module) */
extern "C" {
    int _ZN7android11AudioSystem12SetAudioDataEijPv(int /* par1 */, size_t /* byte_len */, void* /* ptr */) {
        return 0;
    }

    int _ZN7android11AudioSystem15SetAudioCommandEii(int /* var1 */, int /* var2 */) {
        return 0;
    }

    int _ZN7android11AudioSystem15GetAudioCommandEiPi(int /* var1 */) {
        return 0;
    }

    int _ZN7android13MediaRecorder13setOutputFileEixx(int /* a1 */, const char* /* a2 */, int /* a3 */) {
        return 0;
    }
}

/* libaudioprocessing.so (sound effect) */
extern "C" 
{
    /* libwebrtc_audio_processing.so exports */
    int _ZN6webrtc15AudioProcessing6CreateEi(int /* config */, void* /* nullptr */) { return 0; }

    int _ZN6webrtc15AudioProcessing6CreateEv(int config, void* /* nullptr */) {
        /* AudioProcessing::Create (M/N) */
        return _ZN6webrtc15AudioProcessing6CreateEi(config, nullptr);
    }
}
