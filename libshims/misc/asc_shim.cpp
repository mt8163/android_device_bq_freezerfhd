#include <string.h>

extern "C"
{
    void _ZN7android14SurfaceControl8setLayerEj(uint32_t);

    void _ZN7android14SurfaceControl8setLayerEi(int32_t layer){
        _ZN7android14SurfaceControl8setLayerEj(static_cast<uint32_t>(layer));
    }

    void _ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8EjjijPNS_14SurfaceControlEjj(const char s, uint32_t w, uint32_t h, uint32_t fmt, 
        uint32_t flags, void *parent, uint32_t windowType, uint32_t ownerUid) {}

    void _ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8Ejjij(const char s, uint32_t w, uint32_t h, uint32_t fmt, uint32_t flags) {}
}
