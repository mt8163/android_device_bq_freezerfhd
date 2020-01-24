#include <stdint.h>

extern "C" {
    void _ZN7android14SurfaceControl8setLayerEj(uint32_t);

    void _ZNK7android8hardware7camera26params19VendorTagDescriptor13writeToParcelEPNS_6ParcelE();

    void _ZN7android14SurfaceControl8setLayerEi(int32_t layer){
        _ZN7android14SurfaceControl8setLayerEj(static_cast<uint32_t>(layer));
    }
}
