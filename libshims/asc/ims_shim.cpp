#include <inttypes.h>
#include <sys/types.h>
#include <log/log.h>
#include <media/AudioTrack.h>
#include <media/stagefright/MPEG4Writer.h>
#include <media/stagefright/MediaBuffer.h>
#include <media/stagefright/MetaData.h>
#include <media/stagefright/MediaDefs.h>
#include <media/stagefright/MediaErrors.h>
#include <media/stagefright/MediaSource.h>
#include <media/stagefright/Utils.h>

#define LOG_TAG "IMS_SHIM"

extern "C"
{
    int _ZN7android10MediaCodec12CreateByTypeERKNS_2spINS_7ALooperEEERKNS_7AStringEbPii(
		void*, void*, int, int*, pid_t);

    int _ZN7android10MediaCodec12CreateByTypeERKNS_2spINS_7ALooperEEEPKcbPii(
		void *looper, void *mime, int encoder, int *err, pid_t pid)
    {
	    return _ZN7android10MediaCodec12CreateByTypeERKNS_2spINS_7ALooperEEERKNS_7AStringEbPii(
			looper, mime, encoder, err, pid);
    }

    int _ZN7android10DataSource23RegisterDefaultSniffersEv()
    {
        return 0;
    }

    int _ZNK7android16NuMediaExtractor14getTrackFormatEmPNS_2spINS_8AMessageEEE(uint64_t track_name)
    {
        return 0;
    }

    int _ZN7android14FindAVCSPSInfoEPhmPNS_7SPSInfoE(uint32_t info_name)
    {
        return 0;
    }

    /* Camera::connect(android::Camera *this, int, const android::String16 *, int, int) */
    int _ZN7android6Camera7connectEiRKNS_8String16Eii(void *, int, void **, int, int);

    int _ZN7android6Camera7connectEiRKNS_8String16Ei(void *thiz, int cameraId, void **str16P, int clientUid)
    {
	    return _ZN7android6Camera7connectEiRKNS_8String16Eii(thiz, cameraId, str16P, clientUid, 1000);
    }

    int _ZN7android10AudioTrackC1E19audio_stream_type_tj14audio_format_tjm20audio_output_flags_tPFviPvS4_ES4_jiNS0_13transfer_typeEPK20audio_offload_info_tiiPK18audio_attributes_tb(
        uint32_t, 
	    uint32_t, 
	    uint32_t, 
	    uint32_t, 
	    void **, 
	    size_t,
	    uint32_t, 
	    void*, 
	    uint32_t, 
	    int, 
	    uint32_t, 
	    uint32_t, 
	    int, 
	    pid_t, 
	    uint32_t)
    {
        return 0;
    }

    int _ZN7android11AudioRecordC1E14audio_source_tj14audio_format_tjRKNS_8String16EjPFviPvS6_ES6_jiNS0_13transfer_typeE19audio_input_flags_tiiPK18audio_attributes_tb(
	    uint32_t inputSource, 
	    uint32_t sampleRate, 
	    uint32_t format, 
	    uint32_t channelMask, 
	    void **opPackageName, 
	    size_t frameCount,
	    uint32_t cbf, 
	    void* user, 
	    uint32_t notificationFrames, 
	    int sessionId, 
	    uint32_t transferType, 
	    uint32_t flags, 
	    int uid, 
	    pid_t pid, 
	    uint32_t pAttributes)
    {
	    return _ZN7android10AudioTrackC1E19audio_stream_type_tj14audio_format_tjm20audio_output_flags_tPFviPvS4_ES4_jiNS0_13transfer_typeEPK20audio_offload_info_tiiPK18audio_attributes_tb(
	       inputSource,
	       sampleRate,
	       format,
	       channelMask,
	       opPackageName,
	       frameCount,
	       cbf,
	       user,
	       notificationFrames,
	       sessionId,
	       transferType,
	       flags,
	       uid,
	       pid,
	       pAttributes);
    }

    int _ZN7android11AudioSourceC1E14audio_source_tRKNS_8String16Ejjj(uint32_t input, char **format, uint32_t sample, uint64_t frames, uint32_t flags)
    {
        return 0;
    }

    int _ZN7android14ICameraService11asInterfaceERKNS_2spINS_7IBinderEEE(uint32_t cameraid, uint32_t clientid)
    {
        ALOGI("CameraServiceInterfaceBinder: Camera ID=%u, Client ID=%u", cameraid, clientid);
        return 0;
    }

    /* android::MPEG4Writer::reset */
    int _ZN7android11MPEG4Writer5resetEv(int thread)
    {
        ALOGI("MPEG4Writer: reset ++ thread=%d", thread);
        //android::MPEG4Writer::stopWriterThread(thread);
        return 0;
    }

}
