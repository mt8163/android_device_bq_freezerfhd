#include <gui/BufferQueue.h>
#define LOG_TAG "HW_UI_SHIM"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <ui/GraphicBufferMapper.h>
#include <ui/PixelFormat.h>
#include <log/log.h>
#include <dlfcn.h>
#include <string>

extern "C" void _ZN7android11BufferQueue17createBufferQueueEPNS_2spINS_22IGraphicBufferProducerEEEPNS1_INS_22IGraphicBufferConsumerEEEb(
    void *outProducer, void *outConsumer, bool consumerIsSurfaceFlinger);

extern "C" void _ZN7android11BufferQueue17createBufferQueueEPNS_2spINS_22IGraphicBufferProducerEEEPNS1_INS_22IGraphicBufferConsumerEEERKNS1_INS_19IGraphicBufferAllocEEE(
    void *outProducer, void *outConsumer, void *allocator __unused) {
  _ZN7android11BufferQueue17createBufferQueueEPNS_2spINS_22IGraphicBufferProducerEEEPNS1_INS_22IGraphicBufferConsumerEEEb(
      outProducer, outConsumer, false);
}

extern "C" {
    void _ZN7android4Rect10EMPTY_RECTE();

    void _ZTVN7android15HdrCapabilitiesE();

    void _ZN7android5Fence5mergeEPKcRKNS_2spIS0_EES6_();

    void _ZN7android8hardware7camera26params24VendorTagDescriptorCache14readFromParcelEPKNS_6ParcelE();

    void _ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8Ejjij();

    void _ZN7android18BufferItemConsumerC2ERKNS_2spINS_22IGraphicBufferConsumerEEEmib();

    void _ZN7android18BufferItemConsumerC1ERKNS_2spINS_22IGraphicBufferConsumerEEEjib();

    void _ZN7android18BufferItemConsumerC2ERKNS_2spINS_22IGraphicBufferConsumerEEEyib();

    void _ZN7android11BufferQueue17createBufferQueueEPNS_2spINS_22IGraphicBufferProducerEEEPNS1_INS_22IGraphicBufferConsumerEEEb();

    void _ZN7android11BufferQueue17createBufferQueueEPNS_2spINS_22IGraphicBufferProducerEEEPNS1_INS_22IGraphicBufferConsumerEEERKNS1_INS_19IGraphicBufferAllocEEE();

}
