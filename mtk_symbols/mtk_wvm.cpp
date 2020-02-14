#include <media/IMediaSource.h>

extern "C" {
    /* MediaBufferGroup::MediaBufferGroup */
    int _ZN7android16MediaBufferGroupC1Ej(unsigned int);
    int _ZN7android16MediaBufferGroupC1Ev() {
        return _ZN7android16MediaBufferGroupC1Ej(0);
    }
}

/* IMediaSource::ReadOptions::getSeekTo */
extern "C" bool _ZNK7android12IMediaSource11ReadOptions9getSeekToEPxPNS1_8SeekModeE(int64_t*, android::IMediaSource::ReadOptions::SeekMode*);
extern "C" bool _ZNK7android11MediaSource11ReadOptions9getSeekToEPxPNS1_8SeekModeE(int64_t *time_us, android::IMediaSource::ReadOptions::SeekMode *mode) {
    return _ZNK7android12IMediaSource11ReadOptions9getSeekToEPxPNS1_8SeekModeE(time_us, mode);
}

/* IMediaSource::ReadOptions::getNonBlocking */
extern "C" bool _ZNK7android12IMediaSource11ReadOptions14getNonBlockingEv();
extern "C" bool _ZNK7android11MediaSource11ReadOptions14getNonBlockingEv() {
    return _ZNK7android12IMediaSource11ReadOptions14getNonBlockingEv();
}
