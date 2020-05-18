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
#include <stdint.h>
#include <inttypes.h>
#include <log/log.h>
#include <cutils/native_handle.h>
#include <ui/GraphicBuffer.h>
#include <media/stagefright/foundation/AHandler.h>
#include <media/stagefright/CameraSource.h>
#include <media/stagefright/CameraSourceTimeLapse.h>
#include <camera/CameraBase.h>
#include <utils/Log.h>
#include <gui/Surface.h>
#include <utils/String8.h>
#include <gui/SurfaceControl.h>
#include <cutils/properties.h>
#include <utils/RefBase.h>
#include <gui/SurfaceComposerClient.h>
#include <system/window.h>
#include <ui/PixelFormat.h>
#include <ui/Rect.h>

#define LOG_TAG "ASC_SHIM"

using namespace android;

extern "C" {
    void* _ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8EjjijPNS_14SurfaceControlEjj(android::String8 const & s, uint32_t w, uint32_t h,
        android::PixelFormat fmt, uint32_t flags, void *parent, uint32_t windowType, uint32_t ownerUid);
	
    /* sp<SurfaceControl> android::SurfaceComposerClient::createSurface(android::String8 const&, unsigned int, unsigned int, int, unsigned int) */
	
    void* _ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8Ejjij(android::String8 const& s, uint32_t w, uint32_t h, android::PixelFormat fmt, uint32_t flags) 
    {
        ALOGI("_ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8Ejjij begin...");
        return _ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8EjjijPNS_14SurfaceControlEjj(s, w, h, fmt, flags, NULL, 0, 0);
    }

    void _ZN7android20DisplayEventReceiverC1ENS_16ISurfaceComposer11VsyncSourceE();
	
    void _ZN7android20DisplayEventReceiverC1Ev() {
        _ZN7android20DisplayEventReceiverC1ENS_16ISurfaceComposer11VsyncSourceE;	
    }

    void _ZN7android13GraphicBufferC1EjjijjjP13native_handleb(
        const native_handle_t* handle,
        android::GraphicBuffer::HandleWrapMethod method,
        uint32_t width,
        uint32_t height,
        int format,
        uint32_t layerCount,
        uint64_t usage,
        uint32_t stride);

    void _ZN7android13GraphicBufferC1EjjijjP13native_handleb(uint32_t inWidth, uint32_t inHeight, int inFormat, uint32_t inUsage, uint32_t inStride, native_handle_t* inHandle, bool keepOwnership)
    {
        android::GraphicBuffer::HandleWrapMethod inMethod = (keepOwnership ? android::GraphicBuffer::TAKE_HANDLE : android::GraphicBuffer::WRAP_HANDLE);
        _ZN7android13GraphicBufferC1EjjijjjP13native_handleb(inHandle, inMethod, inWidth, inHeight, inFormat, static_cast<uint32_t>(1), static_cast<uint64_t>(inUsage), inStride);
    }

    void _ZN7android12CameraSource16CreateFromCameraERKNS_2spINS_7ICameraEEERKNS1_INS_21ICameraRecordingProxyEEEiRKNS_8String16EjNS_4SizeEiRKNS1_INS_22IGraphicBufferProducerEEEb(
        const sp<Camera>& camera,
        const sp<ICameraRecordingProxy>& proxy,
        int32_t cameraId,
        const String16& clientName,
        uid_t clientUid,
        Size videoSize,
        int32_t frameRate,
        const sp<IGraphicBufferProducer>& surface,
        bool storeMetaDataInVideoBuffers)
    {
        const char* clientName_str = String8(clientName).string();
        ALOGI("CreateFromCamera: size=%zu clientUid=%ld, clientName=%s", videoSize, (long)clientUid, clientName_str);
    }

    int _ZN7android10CameraBaseINS_6CameraENS_12CameraTraitsIS1_EEE13getCameraInfoEiPNS_10CameraInfoE(long a1, int a2, int a3)
    {
        int v3;
        int v5 = a2;
        int v6 = a3;

        if (v5) {
            v3 = v5 + 24;
        } else {
            v3 = 2147483648;
        }
        return v3;
    }

    /* Fix this */
    int _ZNK7android12CameraSource30isMetaDataStoredInVideoBuffersEv(uint32_t video)
    {
        return 0;
    }
        
}

