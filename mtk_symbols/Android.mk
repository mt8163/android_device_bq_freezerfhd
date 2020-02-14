LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
    mtk_asc.cpp \
    mtk_audio.cpp \
    mtk_omx.cpp \
    mtk_ui.cpp \
    mtk_ssl.cpp \
    mtk_wvm.cpp

# only for 64bit libraries
LOCAL_SRC_FILES_64 := mtk_parcel.cpp

LOCAL_SHARED_LIBRARIES := libbinder liblog libgui libui libmedia libbase libstagefright_foundation
LOCAL_MODULE := libmtk_symbols
LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)

# for libshim_mtkcam
# /system/lib/libcam_utils.so ( _ZN7android13GraphicBufferC1Ejjij )
#include $(CLEAR_VARS)
#LOCAL_LDLIBS := -llog
#LOCAL_SRC_FILES := mtk_cam.cpp
#LOCAL_MODULE := libshim_mtkcam
#LOCAL_MODULE_CLASS := SHARED_LIBRARIES
#LOCAL_PROPRIETARY_MODULE := true
#include $(BUILD_SHARED_LIBRARY)
