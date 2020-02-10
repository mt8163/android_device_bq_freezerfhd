#include <string.h>
#include <log/log.h>
#include <stdio.h>
#include <stdlib.h>
#include <cutils/log.h>

extern "C" int _ZN7android13GraphicBufferC1EjjijNSt3__112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE(uint32_t Width, uint32_t Height, int Format, uint32_t Usage, char Requestor[]) {
    __android_log_print(3, "HW_GUI_SHIM", "Requested _ZN7android13GraphicBufferC1EjjijNSt3__112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE by %c for %u", Requestor, Usage);
    return 0;
}

extern "C" int _ZN7android13GraphicBufferC1Ejjij(uint32_t Width, uint32_t Height, int Format, uint32_t Usage) {
    char Requestor[] = "<NULL>";
    __android_log_print(3, "HW_GUI_SHIM", "_ZN7android13GraphicBufferC1Ejjij int: %u, %u, %i, %u", Width, Height, Format, Usage);
    _ZN7android13GraphicBufferC1EjjijNSt3__112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE(Width, Height, Format, Usage, Requestor);
    return 0;
}

