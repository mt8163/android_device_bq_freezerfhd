LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
    mtk_asc.cpp \
    mtk_audio.cpp \
    mtk_omx.cpp \
    mtk_icu55.c \
    mtk_icu53.c \
    mtk_ssl.cpp

# 64bit libraries
LOCAL_SRC_FILES_64 := mtk_parcel.cpp
# 64bit libraries end

LOCAL_SHARED_LIBRARIES := libbinder liblog libgui libui libmedia libbase libstagefright_foundation libicuuc libicui18n libcrypto
LOCAL_MODULE := libmtk_symbols
LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)
