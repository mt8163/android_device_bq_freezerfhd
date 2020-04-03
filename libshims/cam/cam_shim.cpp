#include <string.h>
#include <utils/RefBase.h>
#include <gui/SurfaceComposerClient.h>

extern "C" void* _ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8EjjijPNS_14SurfaceControlEjj(android::String8 const & s, uint32_t w, uint32_t h,
        android::PixelFormat fmt, uint32_t flags, void *parent, uint32_t windowType, uint32_t ownerUid);

// sp<SurfaceControl> android::SurfaceComposerClient::createSurface(android::String8 const&, unsigned int, unsigned int, int, unsigned int)
extern "C" void* _ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8Ejjij(android::String8 const& s, uint32_t w, uint32_t h,
        android::PixelFormat fmt, uint32_t flags) {
    return _ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8EjjijPNS_14SurfaceControlEjj(s, w, h, fmt, flags, NULL, 0, 0);
}
