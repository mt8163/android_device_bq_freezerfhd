#include <media/stagefright/MPEG4Writer.h>
#include <media/stagefright/MediaBuffer.h>
#include <media/stagefright/MetaData.h>
#include <media/stagefright/MediaDefs.h>
#include <media/stagefright/MediaErrors.h>
#include <media/stagefright/MediaSource.h>
#include <media/stagefright/NuMediaExtractor.h>

#include <media/stagefright/Utils.h>

#include <camera/CameraBase.h>
#include <camera/CameraUtils.h>

#include <camera/android/hardware/ICamera.h>
#include <camera/android/hardware/ICameraClient.h>

#include <media/AudioTrack.h>

#include "include/Media_shim.h"

namespace android {

#ifdef __cplusplus
extern "C"
{
#endif

/* Android N exports */
extern void _ZNK7android16NuMediaExtractor14getTrackFormatEjPNS_2spINS_8AMessageEEEj(size_t index, sp<AMessage> *format, uint32_t flags) {} //FIXME
/*----------------------------------------------------*/
extern int _ZN7android6Camera7connectEiRKNS_8String16Eii(void *, int, void **, int, int);
/*----------------------------------------------------*/
extern void _ZN7android10AudioTrackC1E19audio_stream_type_tj14audio_format_tjj20audio_output_flags_tPFviPvS4_ES4_i15audio_session_tNS0_13transfer_typeEPK20audio_offload_info_tjiPK18audio_attributes_tbf(
    audio_stream_type_t streamType,
    uint32_t sampleRate,
    audio_format_t format,
    audio_channel_mask_t channelMask,
    size_t frameCount,
    audio_output_flags_t flags,
    AudioTrack::callback_t cbf,
    void* user,
    int32_t notificationFrames,
    audio_session_t sessionId,
    AudioTrack::transfer_type transferType,
    const audio_offload_info_t *offloadInfo,
    uid_t uid,
    pid_t pid,
    const audio_attributes_t* pAttributes,
    bool doNotReconnect,
    float maxRequiredSpeed) {} //FIXME
/*----------------------------------------------------*/
extern int _ZN7android11AudioSourceC1E14audio_source_tRKNS_8String16Ejjjji(uint32_t inputSource, const String16 &opPackageName,
    uint32_t sampleRate, uint32_t channelCount, uint32_t outSampleRate,
    uid_t uid, pid_t pid);
/*----------------------------------------------------*/
extern int _ZN7android8hardware14ICameraService11asInterfaceERKNS_2spINS_7IBinderEEE(const sp<hardware::ICameraService>& cameraService,
    const sp<android::hardware::ICameraClient>& cameraClient,
    const String16& clientPackageName,
    const String8& cameraIdStr, 
    int cameraFacing,
    int clientPid, uid_t clientUid,
    int servicePid);
/*----------------------------------------------------*/
extern status_t _ZN7android11MPEG4Writer5resetEb(bool stopSource);
/*----------------------------------------------------*/
extern int _ZN7android8hardware15BpCameraService13getCameraInfoEiPNS0_10CameraInfoE(int cameraId,
    struct hardware::CameraInfo* cameraInfo);

/* 
* FUNCTION NAME: DataSource::RegisterDefaultSniffers.
* USE: Register Default Sniffer (?).
* NOTES: This is a proprietary function from MediaTek.
*/
void _ZN7android10DataSource23RegisterDefaultSniffersEv() {}

/* 
* FUNCTION NAME: NuMediaExtractor::getTrackFormat.
* USE: Returns the track format.
* NOTES: It looks like this function was renamed in N. Stub out to the correct call.
*/
void _ZNK7android16NuMediaExtractor14getTrackFormatEmPNS_2spINS_8AMessageEEE(size_t index, sp<AMessage> *format, uint32_t flags)
{
    _ZNK7android16NuMediaExtractor14getTrackFormatEjPNS_2spINS_8AMessageEEEj(index, format, flags);
}

/* 
* FUNCTION NAME: android::FindAVCSPSInfo.
* USE: Finds and returns the AVCSP Info (?).
* NOTES: This is a proprietary function from MediaTek.
*/
#ifdef __LP64__
void _ZN7android14FindAVCSPSInfoEPhmPNS_7SPSInfoE(uint8_t *seqParamSet, size_t size, struct SPSInfo *pSPSInfo) {} //SPSInfo
#else
void _ZN7android14FindAVCSPSInfoEPhmPNS_7SPSInfoEb(uint8_t *seqParamSet, size_t size, struct SPSInfo *pSPSInfo) {} //SPSInfo
#endif

/* 
* FUNCTION NAME: android::CameraConnect.
* USE: Connect with the camera (?).
* NOTES: It looks like this function was renamed in N. Stub out to the correct call.
*/
int _ZN7android6Camera7connectEiRKNS_8String16Ei(void *thiz, int cameraId, void **str16P, int clientUid)
{
    /* Camera::connect(android::Camera *this, int, const android::String16 *, int, int) */
    return _ZN7android6Camera7connectEiRKNS_8String16Eii(thiz, cameraId, str16P, clientUid, 1000);
}

/* 
* FUNCTION NAME: AudioTrack::AudioTrack.
* USE: AudioTrack (?).
* NOTES: It looks like this function was renamed in N. Stub out to the correct call.
*/
void _ZN7android10AudioTrackC1E19audio_stream_type_tj14audio_format_tjm20audio_output_flags_tPFviPvS4_ES4_jiNS0_13transfer_typeEPK20audio_offload_info_tiiPK18audio_attributes_tb(
    audio_stream_type_t streamType,
    uint32_t sampleRate,
    audio_format_t format,
    audio_channel_mask_t channelMask,
    size_t frameCount,
    audio_output_flags_t flags,
    AudioTrack::callback_t cbf,
    void* user,
    int32_t notificationFrames,
    audio_session_t sessionId,
    AudioTrack::transfer_type transferType,
    const audio_offload_info_t *offloadInfo,
    uid_t uid,
    pid_t pid,
    const audio_attributes_t* pAttributes,
    bool doNotReconnect,
    float maxRequiredSpeed)
{
    _ZN7android10AudioTrackC1E19audio_stream_type_tj14audio_format_tjj20audio_output_flags_tPFviPvS4_ES4_i15audio_session_tNS0_13transfer_typeEPK20audio_offload_info_tjiPK18audio_attributes_tbf(
        streamType,
        sampleRate,
        format,
        channelMask,
        frameCount,
        flags,
        cbf,
        user,
        notificationFrames,
        sessionId,
        transferType,
        offloadInfo,
        uid,
        pid,
        pAttributes,
        doNotReconnect,
        maxRequiredSpeed);
}

/* 
* FUNCTION NAME: AudioSource::AudioSource.
* USE: AudioSource (?).
* NOTES: It looks like this function was renamed in N. Stub out to the correct call.
*/
int _ZN7android11AudioSourceC1E14audio_source_tRKNS_8String16Ejjj(uint32_t inputSource, const String16 &PackageName,
    uint32_t sampleRate, uint32_t channelCount, uint32_t outSampleRate,
        uid_t uid, pid_t pid) 
{
    return _ZN7android11AudioSourceC1E14audio_source_tRKNS_8String16Ejjjji(inputSource, PackageName, sampleRate, channelCount, outSampleRate, uid, pid);
}
 
/* 
* FUNCTION NAME: CameraService::CameraService.
* USE: CameraService (?).
* NOTES: It looks like this function was renamed in N. Stub out to the correct call.
*/
int _ZN7android14ICameraService11asInterfaceERKNS_2spINS_7IBinderEEE(const sp<hardware::ICameraService>& cameraService,
    const sp<android::hardware::ICameraClient>& cameraClient,
    const String16& clientPackageName,
    const String8& cameraIdStr, int cameraFacing,
    int clientPid, uid_t clientUid,
    int servicePid)
{
    return _ZN7android8hardware14ICameraService11asInterfaceERKNS_2spINS_7IBinderEEE(cameraService, cameraClient, clientPackageName, cameraIdStr, cameraFacing, clientPid, clientUid, servicePid);
}

/* 
* FUNCTION NAME: MPEG4Writer::reset.
* USE: Resets the MPEG4Writer give thread.
* NOTES: It looks like this function was renamed in N. Stub out to the correct call.
*/
status_t _ZN7android11MPEG4Writer5resetEv(bool stopSource)
{
    /* android::MPEG4Writer::reset */
    return _ZN7android11MPEG4Writer5resetEb(stopSource);
}

/* 
* FUNCTION NAME: MPEG4Writer::reset.
* USE: Resets the MPEG4Writer give thread.
* NOTES: It looks like this function was renamed in N. Stub out to the correct call.
*/
int _ZN7android10CameraBaseINS_6CameraENS_12CameraTraitsIS1_EEE13getCameraInfoEiPNS_10CameraInfoE(int cameraId,
    struct hardware::CameraInfo* cameraInfo)
{
    return _ZN7android8hardware15BpCameraService13getCameraInfoEiPNS0_10CameraInfoE(cameraId, cameraInfo);
}

#ifdef __cplusplus
}
#endif

} // namespace android
