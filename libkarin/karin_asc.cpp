#include <stdint.h>

extern "C" {
    int _ZN7android14FindAVCSPSInfoEPhmPNS_7SPSInfoE(unsigned char *, unsigned long){
         return 0;
         }
    void _ZN7android14SurfaceControl8setLayerEj(uint32_t);
    void _ZN7android14SurfaceControl8setLayerEi(int32_t layer){
        _ZN7android14SurfaceControl8setLayerEj(static_cast<uint32_t>(layer));
    }
}


