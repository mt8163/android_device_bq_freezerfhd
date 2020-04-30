#include <media/MediaCodecBuffer.h>
#include <media/stagefright/foundation/AHandler.h>
#include <media/stagefright/MediaCodec.h>
#include <media/stagefright/MediaCodecSource.h>
#include <media/stagefright/MediaCodecList.h>
#include <utils/Vector.h>

using namespace android;

extern "C"
{
    void _ZNK7android10MediaCodec15getInputBuffersEPNS_6VectorINS_2spINS_16MediaCodecBufferEEEEE(Vector<sp<ABuffer> > *buffers); /* Vector<sp<MediaCodecBuffer> > *buffers */
    void _ZNK7android10MediaCodec16getOutputBuffersEPNS_6VectorINS_2spINS_16MediaCodecBufferEEEEE(Vector<sp<ABuffer> > *buffers); /* Vector<sp<MediaCodecBuffer> > *buffers */

    int _ZN7android10MediaCodec12CreateByTypeERKNS_2spINS_7ALooperEEERKNS_7AStringEbPii(
		void*, void*, int, int*, pid_t);

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

    int _ZN7android11QueryCodecsERKNS_2spINS_4IOMXEEEPKcbbPNS_6VectorINS_17CodecCapabilitiesEEE(int a1, int a2, int a3, signed int a4, int a5)
    {
        int v13;
        int v9 = a3 ^ 1;
        //android::VectorImpl::VectorImpl(&v13, 8, 0);
        v13 = 8;
        //android::VectorImpl::clear(a5);
        return v9;
    }
}
