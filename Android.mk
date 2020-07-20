LOCAL_PATH := $(call my-dir)
ifneq ($(filter freezerfhd,$(TARGET_DEVICE)),)

include $(call all-makefiles-under,$(LOCAL_PATH))

NVDATA_SYMLINK := $(TARGET_OUT_VENDOR)/nvdata
$(NVDATA_SYMLINK): $(LOCAL_INSTALLED_MODULE)
	@echo "fstab link: $@"
	@mkdir -p $(dir $@)
	@rm -rf $@
	$(hide) ln -sf /data/nvram $@

ALL_DEFAULT_INSTALLED_MODULES +=  \
    $(NVDATA_SYMLINK)

endif
