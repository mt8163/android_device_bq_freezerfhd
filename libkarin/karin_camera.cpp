/*
 * Copyright (C) 2020 Roger Ortiz
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
 *
 * MediaTek Camera Shim for the Aquaris M8
 */

#include <stdio.h>
#define LOG_TAG "KARIN_CAM_SHIM"
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <utils/Log.h>
#include <hardware/power.h>
#include <hardware/hardware.h>

extern "C" {

   int _ZN7android8hardware7camera26params24VendorTagDescriptorCache22getVendorTagDescriptorEyPNS_2spINS_19VendorTagDescriptorEEE(){
     return 0;
     }

   int _ZN7android8hardware7camera26params24VendorTagDescriptorCache22getVendorTagDescriptorEmPNS_2spINS_19VendorTagDescriptorEEE(){
     return 0;
     }

   int _ZN7android6Camera32releaseRecordingFrameHandleBatchENSt3__16vectorIP13native_handleNS1_9allocatorIS4_EEEE(){
     return 0;
     }

   int _ZNK7android14CameraMetadata6unlockEPK15camera_metadata();

   int _ZN7android14CameraMetadata6unlockEPK15camera_metadata() {
     return _ZNK7android14CameraMetadata6unlockEPK15camera_metadata();
     }

   void _ZN7android12CameraSource16CreateFromCameraERKNS_2spINS_7ICameraEEERKNS1_INS_21ICameraRecordingProxyEEEiRKNS_8String16EjNS_4SizeEiRKNS1_INS_22IGraphicBufferProducerEEEb();

   void _ZN7android12CameraSource16CreateFromCameraERKNS_2spINS_7ICameraEEERKNS1_INS_21ICameraRecordingProxyEEEiRKNS_8String16EjNS_4SizeEiRKNS1_INS_22IGraphicBufferProducerEEEb();

}
