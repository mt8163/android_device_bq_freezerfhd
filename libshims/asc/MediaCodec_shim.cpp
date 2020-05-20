#include <media/MediaCodecBuffer.h>
#include <media/stagefright/foundation/AHandler.h>
#include <media/stagefright/MediaCodec.h>
#include <media/stagefright/MediaCodecSource.h>
#include <media/stagefright/MediaCodecList.h>
#include <media/stagefright/ACodec.h>
#include <utils/Vector.h>

using namespace android;

extern "C"
{
    extern void* _ZN7android6ACodec17queryCapabilitiesEPKcS2_S2_bPNS_14MediaCodecInfo18CapabilitiesWriterE(const char* owner, const char* name, const char* mime, bool isEncoder,
        MediaCodecInfo::CapabilitiesWriter* caps);

    void _ZNK7android10MediaCodec15getInputBuffersEPNS_6VectorINS_2spINS_16MediaCodecBufferEEEEE(Vector<sp<ABuffer> > *buffers); /* Vector<sp<MediaCodecBuffer> > *buffers */
    void _ZNK7android10MediaCodec16getOutputBuffersEPNS_6VectorINS_2spINS_16MediaCodecBufferEEEEE(Vector<sp<ABuffer> > *buffers); /* Vector<sp<MediaCodecBuffer> > *buffers */

    int _ZN7android10MediaCodec12CreateByTypeERKNS_2spINS_7ALooperEEERKNS_7AStringEbPii(
		void*, void*, int, int*, pid_t) 
    {
        return 0;
    }

    int _ZN7android10MediaCodec12CreateByTypeERKNS_2spINS_7ALooperEEEPKcbPii(
		void *looper, void *mime, int encoder, int *err, pid_t pid)
    {
	    return _ZN7android10MediaCodec12CreateByTypeERKNS_2spINS_7ALooperEEERKNS_7AStringEbPii(
			looper, mime, encoder, err, pid);
    }

    void _ZNK7android10MediaCodec15getInputBuffersEPNS_6VectorINS_2spINS_7ABufferEEEEE(Vector<sp<ABuffer> > *buffers)
    {
	    _ZNK7android10MediaCodec15getInputBuffersEPNS_6VectorINS_2spINS_16MediaCodecBufferEEEEE(buffers);
    }

    void _ZNK7android10MediaCodec16getOutputBuffersEPNS_6VectorINS_2spINS_7ABufferEEEEE(Vector<sp<ABuffer> > *buffers)
    {
	    _ZNK7android10MediaCodec16getOutputBuffersEPNS_6VectorINS_2spINS_16MediaCodecBufferEEEEE(buffers);
    }

    void* _ZN7android11QueryCodecsERKNS_2spINS_4IOMXEEEPKcbbPNS_6VectorINS_17CodecCapabilitiesEEE(const char* owner, const char* name, const char* mime, bool isEncoder,
        MediaCodecInfo::CapabilitiesWriter* caps)
    {
        return _ZN7android6ACodec17queryCapabilitiesEPKcS2_S2_bPNS_14MediaCodecInfo18CapabilitiesWriterE(owner, name, mime, isEncoder, caps);
    }
}
