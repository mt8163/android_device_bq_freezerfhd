/*
 * Copyright (C) 2007 The Android Open Source Project
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

#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <android/native_window.h>

#include <utils/CallStack.h>
#include <utils/Errors.h>
#include <utils/Log.h>
#include <utils/threads.h>

#include <binder/IPCThreadState.h>

#include <ui/DisplayInfo.h>
#include <ui/GraphicBuffer.h>
#include <ui/Rect.h>

#include <gui/ISurfaceComposer.h>
#include <gui/Surface.h>
#include <gui/SurfaceComposerClient.h>
#include <gui/SurfaceControl.h>

#define LOG_TAG "SurfaceControl_Shim"

/* Let's assume the validate checks passes */
#define NO_ERROR 0

namespace android {

SurfaceControl::SurfaceControl(
        const sp<SurfaceComposerClient>& client, 
        const sp<IBinder>& handle,
        const sp<IGraphicBufferProducer>& gbp)
    : mClient(client), mHandle(handle), mGraphicBufferProducer(gbp)
{
}

status_t _ZN7android14SurfaceControl8setLayerEj(int32_t layer) {
    //status_t mHandle = NO_ERROR;
    const sp<IBinder>& handle = NULL;
    status_t err = NO_ERROR; /* We assume the validate check just passed */
    if (err < 0) return err;
    const sp<SurfaceComposerClient>& client((client));
    return client->setLayer(handle, layer);
}

status_t _ZN7android14SurfaceControl8setLayerEi(int32_t layer){
    return _ZN7android14SurfaceControl8setLayerEj(static_cast<uint32_t>(layer));
}

}; // namespace android

