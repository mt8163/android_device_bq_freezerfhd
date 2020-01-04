LOCAL_PATH := $(call my-dir)

ifeq ($(TARGET_INCLUDE_LIBKARIN),true)
    include $(CLEAR_VARS)
    LOCAL_MODULE := libkarin
    LOCAL_MODULE_TAGS := optional
    LOCAL_C_INCLUDES := system/core/include/ frameworks/rs/server/ frameworks/av/include/ hardware/libhardware/include/
    LOCAL_SRC_FILES := \
        karin_audio.cpp \
        karin_xlog.c \
        karin_framework.cpp \
        karin_gui.cpp \
        karin_thermal.cpp
include $(BUILD_SHARED_LIBRARY)
endif