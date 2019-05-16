LOCAL_PATH := $(call my-dir)

ifneq ($(filter omni_Aquaris_M8,$(TARGET_DEVICE)),)
include $(call all-makefiles-under,$(LOCAL_PATH))
endif
