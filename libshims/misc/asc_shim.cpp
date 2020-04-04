/*
* Copyright (C) 2020 The LineageOS Project
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include <string.h>
#include <inttypes.h>
#include <log/log.h>

#define LOG_TAG "ASC_SHIM"

extern "C" {
    int _ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8EjjijPNS_14SurfaceControlEjj(const char s, uint32_t w, uint32_t h, uint32_t fmt, uint32_t flags, void *parent, uint32_t windowType, uint32_t ownerUid) 
    {
        ALOGI("CreateSurface: s=%c, w=%u, h=%u, fmt=%u, flags=%u, parent=%p, windowType=%u, ownerUid=%u", s, w, h, fmt, flags, parent, windowType, ownerUid);
        return 0;
    }
 
    int _ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8Ejjij(const char s, uint32_t w, uint32_t h, uint32_t fmt, uint32_t flags)
    {
        ALOGI("_ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8Ejjij begin...");
        return _ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8EjjijPNS_14SurfaceControlEjj(s, w, h, fmt, flags, NULL, 0, 0);
    }

    int _ZN7android13GraphicBufferC1EjjijjjP13native_handleb(char handle, const char method, uint32_t width, uint32_t height, int format, uint32_t layerCount, uint64_t usage, uint32_t stride)
    {
        return 0;
    }

    int _ZN7android13GraphicBufferC1EjjijjP13native_handleb(uint32_t inWidth, uint32_t inHeight, int inFormat, uint32_t inUsage, uint32_t inStride, char inHandle, bool keepOwnership)
    {
        return 0;
    }

    int _ZN7android20DisplayEventReceiverC1ENS_16ISurfaceComposer11VsyncSourceE()
    {
        return 0;
    }

    int _ZN7android20DisplayEventReceiverC1Ev() 
    {
        return _ZN7android20DisplayEventReceiverC1ENS_16ISurfaceComposer11VsyncSourceE();
    }

    int _ZN7android14SurfaceControl8setLayerEj(uint32_t layer)
    {
        ALOGI("SetLayer: %u", layer);
        return 0;
    }

    int _ZN7android14SurfaceControl8setLayerEi(int32_t layer){
        return _ZN7android14SurfaceControl8setLayerEj(static_cast<uint32_t>(layer));
    }
}

