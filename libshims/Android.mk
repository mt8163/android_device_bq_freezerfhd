LOCAL_PATH := $(call my-dir)

# GPS Shim
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	gps/crypto_shim.cpp \
	gps/icu_shim.cpp \
	gps/ssl_shim.cpp

LOCAL_SHARED_LIBRARIES := \
	liblog \
	libicuuc \
	libssl \
	libcrypto

LOCAL_MODULE := libshim_gps
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_SHARED_LIBRARY)

# Audio Shim
include $(CLEAR_VARS)

LOCAL_SRC_FILES := audio/audio_shim.cpp

LOCAL_SHARED_LIBRARIES := \
	libbinder \
	libmedia

LOCAL_MODULE := libshim_audio
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_SHARED_LIBRARY)

# GUI Shim (Graphics)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	gui/SensorManager.cpp \
    gui/gui_shim.cpp

LOCAL_SHARED_LIBRARIES := \
	libbinder \
	libgui \
	liblog \
	libsensor \
	libui \
	libutils

LOCAL_MODULE := libshim_gui

LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_SHARED_LIBRARY)

# Atomic Shim
include $(CLEAR_VARS)

LOCAL_SRC_FILES := misc/atomic_shim.cpp

LOCAL_MODULE := libshim_atomic

LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_SHARED_LIBRARY)

# Bionic Shim
include $(CLEAR_VARS)

LOCAL_SRC_FILES := misc/bionic_shim.cpp

LOCAL_MODULE := libshim_bionic

LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SHARED_LIBRARIES := libc
include $(BUILD_SHARED_LIBRARY)

# OMX Shim
include $(CLEAR_VARS)

LOCAL_SRC_FILES := misc/omx_shim.cpp

LOCAL_MODULE := libshim_omx

LOCAL_PROPRIETARY_MODULE := true
LOCAL_SHARED_LIBRARIES := libdpframework
include $(BUILD_SHARED_LIBRARY)

# XLOG Shim
include $(CLEAR_VARS)

LOCAL_SRC_FILES := misc/xlog_shim.c

LOCAL_SHARED_LIBRARIES := liblog

LOCAL_MODULE := libxlog

LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_SHARED_LIBRARY)

# UI Shim (Graphics)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	ui/ui_shim.cpp

LOCAL_SHARED_LIBRARIES := \
	libbinder \
	libui \
	libutils

LOCAL_MODULE := libshim_ui

LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_SHARED_LIBRARY)

# DRM Shim
include $(CLEAR_VARS)

LOCAL_SRC_FILES := drm/drm_shim.cpp

LOCAL_SHARED_LIBRARIES := \
	libcrypto

LOCAL_MODULE := libshim_drm

LOCAL_MODULE_TAGS := optional
LOCAL_SHARED_LIBRARIES := liblog libcrypto
LOCAL_LDLIBS := -ldl
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_SHARED_LIBRARY)

# Program Binary Service Shim
include $(CLEAR_VARS)

LOCAL_SRC_FILES := misc/program_binary_service_shim.cpp

LOCAL_MODULE := libshim_program_binary_service

LOCAL_MODULE_TAGS := optional
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_SHARED_LIBRARY)

# WVM Shim
include $(CLEAR_VARS)

LOCAL_SRC_FILES := wvm/wvm_shim.cpp

LOCAL_MODULE := libshim_wvm

LOCAL_SHARED_LIBRARIES := liblog libstagefright_foundation libmedia libstagefright_omx libdrmframework libstagefright
LOCAL_MODULE_TAGS := optional
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_SHARED_LIBRARY)

# Media Shim
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
    media/Media_shim.cpp \
	media/DisplayEvent_shim.cpp \
	media/MediaBuffer_shim.cpp \
    media/MediaCodec_shim.cpp \
    media/SurfaceControl_shim.cpp \
    media/CameraSource_shim.cpp

LOCAL_MODULE := libshim_media

LOCAL_SHARED_LIBRARIES := \
    liblog \
    libui \
    libgui \
    libstagefright_foundation \
    libmedia \
    libstagefright \
    libcutils \
    libutils \
    libcamera_client \
    libbinder \
    libssl \
    libaudiomanager \
    libaudioutils \
    libaudioclient \
    libbase \
    android.hidl.token@1.0-utils \
    android.hardware.graphics.bufferqueue@1.0

LOCAL_CFLAGS := -Wno-unused-variable -Wno-unused-parameter -Wall -Wextra
LOCAL_MODULE_TAGS := optional
LOCAL_PROPRIETARY_MODULE := true
include $(BUILD_SHARED_LIBRARY)
