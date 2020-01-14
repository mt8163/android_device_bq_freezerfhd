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

   bool _ZNK7android12CameraSource30isMetaDataStoredInVideoBuffersEv(){
     return _ZNK7android12CameraSource30isMetaDataStoredInVideoBuffersEv();
     }

   void _ZN7android12CameraSource16CreateFromCameraERKNS_2spINS_7ICameraEEERKNS1_INS_21ICameraRecordingProxyEEEiRKNS_8String16EjNS_4SizeEiRKNS1_INS_22IGraphicBufferProducerEEEb();

   void _ZN7android12CameraSource16CreateFromCameraERKNS_2spINS_7ICameraEEERKNS1_INS_21ICameraRecordingProxyEEEiRKNS_8String16EjNS_4SizeEiRKNS1_INS_22IGraphicBufferProducerEEEb();

}
