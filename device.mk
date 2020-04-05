DEVICE_PATH := device/bq/aquaris_m8

# Call the Vendor Makefile
$(call inherit-product, vendor/bq/aquaris_m8/aquaris_m8-vendor.mk)

# Dalvik/HWUI
$(call inherit-product, frameworks/native/build/tablet-7in-hdpi-1024-dalvik-heap.mk)
$(call inherit-product-if-exists, frameworks/native/build/phone-xxhdpi-2048-hwui-memory.mk)

# HIDL (HAL Interface Definition Language)
-include $(DEVICE_PATH)/hidl.mk

# GC
PRODUCT_TAGS += dalvik.gc.type-precise

# Overlays
DEVICE_PACKAGE_OVERLAYS += \
         $(DEVICE_PATH)/overlay \
         $(DEVICE_PATH)/overlay-lineage

# Display
TARGET_SCREEN_HEIGHT := 1280
TARGET_SCREEN_WIDTH := 800

# Screen density
PRODUCT_AAPT_CONFIG := normal
PRODUCT_AAPT_PREF_CONFIG := xxhdpi

# Recovery allowed devices
TARGET_OTA_ASSERT_DEVICE := Aquaris_M8,aquaris_m8,karin

# Camera
PRODUCT_PACKAGES += Camera2

# MediaTek's YGPS
PRODUCT_PACKAGES += YGPS

# Shim symbols
PRODUCT_PACKAGES += \
    libshim_bionic \
    libshim_audio \
    libshim_omx \
    libshim_ui \
    libshim_gui \
    libshim_xlog \
    libshim_gps \
    libshim_program_binary_service \
    libshim_wvm \
    libshim_drm \
    libshim_asc

# Power
PRODUCT_PACKAGES += power.mt8163

# Lights
PRODUCT_PACKAGES += lights.mt8163

# MTK WPA Supplicant Libraries
PRODUCT_PACKAGES += lib_driver_cmd_mt66xx

# Network
PRODUCT_PACKAGES += \
    netd \
    wpa_supplicant \
    wpa_cli \
    hostapd \
    hostapd_cli

# Graphic
PRODUCT_PACKAGES += \
    libGLES_android \
    libgralloc_extra \
    libion \
    libgui_ext \
    libui_ext

# Bluetooth
PRODUCT_PACKAGES += \
    libbt-vendor \
    libbluetooth_mtk

# DRM
PRODUCT_PACKAGES += libmockdrmcryptoplugin

# FM Radio
PRODUCT_PACKAGES += \
	FMRadio \
	libfmcust

# Audio
PRODUCT_PACKAGES += \
    audio.a2dp.default \
    audio.r_submix.default \
    audio.usb.default \
    libaudio-resampler \
    libtinyalsa \
    libtinyxml \
    tinymix

# XML Parser
PRODUCT_PACKAGES += libxml2

# USB
PRODUCT_PACKAGES += com.android.future.usb.accessory

# Ramdisk
PRODUCT_COPY_FILES += \
    $(call find-copy-subdir-files,*,$(LOCAL_PATH)/rootdir,root)

# Permissions
PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/android.hardware.bluetooth_le.xml:system/etc/permissions/android.hardware.bluetooth_le.xml \
    frameworks/native/data/etc/android.hardware.bluetooth.xml:system/etc/permissions/android.hardware.bluetooth.xml \
    frameworks/native/data/etc/android.hardware.camera.front.xml:system/etc/permissions/android.hardware.camera.front.xml \
    frameworks/native/data/etc/android.hardware.camera.xml:system/etc/permissions/android.hardware.camera.xml \
    frameworks/native/data/etc/android.hardware.sensor.accelerometer.xml:system/etc/permissions/android.hardware.sensor.accelerometer.xml \
    frameworks/native/data/etc/android.hardware.sensor.light.xml:system/etc/permissions/android.hardware.sensor.light.xml \
    frameworks/native/data/etc/android.hardware.touchscreen.multitouch.jazzhand.xml:system/etc/permissions/android.hardware.touchscreen.multitouch.jazzhand.xml \
    frameworks/native/data/etc/android.hardware.usb.accessory.xml:system/etc/permissions/android.hardware.usb.accessory.xml \
    frameworks/native/data/etc/android.hardware.usb.host.xml:system/etc/permissions/android.hardware.usb.host.xml \
    frameworks/native/data/etc/android.hardware.wifi.direct.xml:system/etc/permissions/android.hardware.wifi.direct.xml \
    frameworks/native/data/etc/android.hardware.wifi.xml:system/etc/permissions/android.hardware.wifi.xml \
    frameworks/native/data/etc/android.software.sip.voip.xml:system/etc/permissions/android.software.sip.voip.xml \
    frameworks/native/data/etc/tablet_core_hardware.xml:system/etc/permissions/tablet_core_hardware.xml

# Camera
PRODUCT_COPY_FILES += $(DEVICE_PATH)/configs/init/mediaserver.rc:system/etc/init/mediaserver.rc

# Audio Wakelock
PRODUCT_COPY_FILES += $(DEVICE_PATH)/configs/init/audioserver.rc:system/etc/init/audioserver.rc

# Media
PRODUCT_COPY_FILES += \
    frameworks/av/media/libstagefright/data/media_codecs_google_audio.xml:system/etc/media_codecs_google_audio.xml \
    frameworks/av/media/libstagefright/data/media_codecs_google_telephony.xml:system/etc/media_codecs_google_telephony.xml \
    frameworks/av/media/libstagefright/data/media_codecs_google_video_le.xml:system/etc/media_codecs_google_video_le.xml \
    $(LOCAL_PATH)/configs/media/media_profiles.xml:system/etc/media_profiles.xml \
    $(LOCAL_PATH)/configs/media/media_codecs.xml:system/etc/media_codecs.xml \
    $(LOCAL_PATH)/configs/media/media_codecs_performance.xml:system/etc/media_codecs_performance.xml \
    $(LOCAL_PATH)/configs/media/media_codecs_mediatek_video.xml:system/etc/media_codecs_mediatek_video.xml \
    $(LOCAL_PATH)/configs/media/media_codecs_mediatek_audio.xml:system/etc/media_codecs_mediatek_audio.xml

# Audio
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/audio/audio_effects.conf:system/etc/audio_effects.conf \
    $(LOCAL_PATH)/configs/audio/audio_device.xml:system/etc/audio_device.xml \
    $(LOCAL_PATH)/configs/audio/audio_em.xml:system/etc/audio_em.xml \
    $(LOCAL_PATH)/configs/audio/AudioParamOptions.xml:system/etc/audio_param/AudioParamOptions.xml

# Wifi Configs
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/wifi/wpa_supplicant.conf:system/vendor/etc/wifi/wpa_supplicant.conf \
    $(LOCAL_PATH)/configs/wifi/wpa_supplicant_overlay.conf:system/vendor/etc/wifi/wpa_supplicant_overlay.conf \
    $(LOCAL_PATH)/configs/wifi/p2p_supplicant_overlay.conf:system/vendor/etc/wifi/p2p_supplicant_overlay.conf \
    $(LOCAL_PATH)/configs/ecc_list.xml:system/etc/ecc_list.xml \
    $(LOCAL_PATH)/configs/spn-conf.xml:system/etc/spn-conf.xml

# Vulkan
PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/android.hardware.vulkan.level-0.xml:system/vendor/etc/permissions/android.hardware.vulkan.level.xml \
    frameworks/native/data/etc/android.hardware.vulkan.version-1_0_3.xml:system/vendor/etc/permissions/android.hardware.vulkan.version.xml

# Seccomp policy
PRODUCT_COPY_FILES += \
    $(DEVICE_PATH)/seccomp/mediacodec.policy:system/vendor/etc/seccomp_policy/mediacodec.policy \
    $(DEVICE_PATH)/seccomp/mediaextractor.policy:system/vendor/etc/seccomp_policy/mediaextractor.policy

# Filesystem management tools
PRODUCT_PACKAGES += \
	e2fsck \
	fibmap.f2fs \
	fsck.f2fs \
	mkfs.f2fs \
	make_ext4fs \
	resize2fs \
	setup_fs \
	ext4_resize \
	libext2_blkid \
	libext2_uuid_static \
	superumount \
	mount.exfat \
	fsck.exfat \
	mkfs.exfat \
	fsck.ntfs \
	mkfs.ntfs \
	mount.ntfs

# Property Overrides
PRODUCT_DEFAULT_PROPERTY_OVERRIDES += \
    ro.allow.mock.location=1 \
    ro.zygote=zygote64_32 \
    camera.disable_zsl_mode=1 \
    ro.dalvik.vm.native.bridge=0 \
    persist.sys.usb.config=mtp,adb \
    persist.debug.xlog.enable=0 \
    ro.adb.secure=0 \
    ro.secure=0 \
    ro.allow.mock.location=1

# Camera Legacy
PRODUCT_PROPERTY_OVERRIDES += \
     media.stagefright.legacyencoder=true \
     media.stagefright.less-secure=true
