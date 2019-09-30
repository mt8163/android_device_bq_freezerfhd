DEVICE_BASE := device/bq/freezerfhd
DEVICE_VENDOR := vendor/bq/freezerfhd

# Device overlay
DEVICE_PACKAGE_OVERLAYS += $(DEVICE_BASE)/overlay

# Install init.d scripts
PRODUCT_COPY_FILES += \
    $(DEVICE_BASE)/configs/99exfat-support:system/etc/init.d/99exfat-support

$(call inherit-product, $(SRC_TARGET_DIR)/product/languages_full.mk)

# Device uses high-density artwork where available
PRODUCT_AAPT_CONFIG := normal mdpi
PRODUCT_AAPT_PREF_CONFIG := mdpi

# Set locale
PRODUCT_DEFAULT_LANGUAGE := en
PRODUCT_DEFAULT_REGION   := US

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

# Ramdisk
PRODUCT_COPY_FILES += \
    $(call find-copy-subdir-files,*,$(DEVICE_BASE)/rootdir,root)

# Config files
PRODUCT_COPY_FILES += \
    $(DEVICE_BASE)/configs/media_codecs_ffmpeg.xml:system/etc/media_codecs_ffmpeg.xml \
    $(DEVICE_BASE)/configs/media_codecs_google_audio.xml:system/etc/media_codecs_google_audio.xml \
    $(DEVICE_BASE)/configs/media_codecs_google_video_le.xml:system/etc/media_codecs_google_video_le.xml \
    $(DEVICE_BASE)/configs/media_codecs_mediatek_audio.xml:system/etc/media_codecs_mediatek_audio.xml \
    $(DEVICE_BASE)/configs/media_codecs_mediatek_video.xml:system/etc/media_codecs_mediatek_video.xml \
    $(DEVICE_BASE)/configs/media_codecs_performance.xml:system/etc/media_codecs_performance.xml \
    $(DEVICE_BASE)/configs/media_codecs.xml:system/etc/media_codecs.xml \
    $(DEVICE_BASE)/configs/media_profiles.xml:system/etc/media_profiles.xml \
    $(DEVICE_BASE)/configs/audio_device.xml:system/etc/audio_device.xml \
    $(DEVICE_BASE)/configs/mtk_omx_core.cfg:system/etc/mtk_omx_core.cfg \
    $(DEVICE_BASE)/configs/ds1-default.xml:system/etc/ds1-default.xml

# Audio
PRODUCT_PACKAGES += \
    audio.a2dp.default \
    audio.r_submix.default \
    audio.usb.default \
    audio_policy.stub \
    libalsautils \
    libaudio-resampler \
    libtinyalsa \
    libtinycompress \
    libtinyxml \
    libaudioroute

#OMX    
PRODUCT_PACKAGES += \
    libdashplayer

# Bluetooth
PRODUCT_PACKAGES += \
    bluetooth.default
	
# Graphics
PRODUCT_PACKAGES += \
    libion \
    libgui_ext \
    libui_ext \
    libcap

# MISC
PRODUCT_PACKAGES += \
    librs_jni \
    com.android.future.usb.accessory

# Memtrack
PRODUCT_PACKAGES += \
    memtrack.mt8163

# Lights
PRODUCT_PACKAGES += \
    lights.mt8163

# Power
PRODUCT_PACKAGES += \
    power.default \
    power.mt8163

# network
PRODUCT_PACKAGES += \
    netd
    
# IPv6 tethering
PRODUCT_PACKAGES += \
    ebtables \
    ethertypes

# libmtk_symbols
PRODUCT_PACKAGES += \
    libmtk_symbols

# Shims
PRODUCT_PACKAGES += \
    libshim_vold \
    libshim_media \
    libshim_audio

# Camera
PRODUCT_PACKAGES += \
    Snap

# Zygote
PRODUCT_DEFAULT_PROPERTY_OVERRIDES += \
	ro.zygote=zygote64_32

# ADB on boot
PRODUCT_DEFAULT_PROPERTY_OVERRIDES += \
	ro.adb.secure=0 \
	ro.secure=0 \
	ro.allow.mock.location=0 \
	ro.debuggable=1

# FM Radio
PRODUCT_PACKAGES += \
    FMRadio \
    libfmjni

# Wi-Fi
PRODUCT_PACKAGES += \
    wifi2agps \
    libwpa_client \
    hostapd \
    dhcpcd.conf \
    wpa_supplicant \
    wpa_supplicant.conf

WITH_EXFAT := true

PRODUCT_BUILD_PROP_OVERRIDES += BUILD_UTC_DATE=0

# MTP
PRODUCT_DEFAULT_PROPERTY_OVERRIDES += \
	persist.sys.usb.config=adb,mtp

# call dalvik heap config
$(call inherit-product, frameworks/native/build/tablet-10in-xhdpi-2048-dalvik-heap.mk)

# call hwui memory config
$(call inherit-product-if-exists, frameworks/native/build/phone-xxhdpi-2048-hwui-memory.mk)

$(call inherit-product-if-exists, vendor/bq/aquaris_m8/aquaris_m8-vendor.mk)
