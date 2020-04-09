#include <media/MediaCodecBuffer.h>
#include <media/stagefright/foundation/AHandler.h>
#include <media/stagefright/MediaCodec.h>
#include <media/stagefright/MediaCodecSource.h>
#include <media/stagefright/MediaCodecList.h>
#include <utils/Vector.h>

using namespace android;

extern "C"
{
    void _ZN7android10MediaCodec12CreateByTypeERKNS_2spINS_7ALooperEEERKNS_7AStringEbPiij(const sp<ALooper> &looper, const AString &mime, bool encoder, status_t *err, pid_t pid, uid_t uid);

    void _ZNK7android10MediaCodec15getInputBuffersEPNS_6VectorINS_2spINS_16MediaCodecBufferEEEEE(Vector<sp<ABuffer> > *buffers); /* Vector<sp<MediaCodecBuffer> > *buffers */
    void _ZNK7android10MediaCodec16getOutputBuffersEPNS_6VectorINS_2spINS_16MediaCodecBufferEEEEE(Vector<sp<ABuffer> > *buffers); /* Vector<sp<MediaCodecBuffer> > *buffers */

    void _ZN7android10MediaCodec12CreateByTypeERKNS_2spINS_7ALooperEEERKNS_7AStringEbPii(const sp<ALooper> &looper, const AString &mime, bool encoder, status_t *err, pid_t pid)
    {
	    _ZN7android10MediaCodec12CreateByTypeERKNS_2spINS_7ALooperEEERKNS_7AStringEbPiij(looper, mime, encoder, err, pid, 0);
    }

    void _ZNK7android10MediaCodec15getInputBuffersEPNS_6VectorINS_2spINS_7ABufferEEEEE(Vector<sp<ABuffer> > *buffers)
    {
	    _ZNK7android10MediaCodec15getInputBuffersEPNS_6VectorINS_2spINS_16MediaCodecBufferEEEEE(buffers);
    }

    void _ZNK7android10MediaCodec16getOutputBuffersEPNS_6VectorINS_2spINS_7ABufferEEEEE(Vector<sp<ABuffer> > *buffers)
    {
	    _ZNK7android10MediaCodec16getOutputBuffersEPNS_6VectorINS_2spINS_16MediaCodecBufferEEEEE(buffers);
    }
}
