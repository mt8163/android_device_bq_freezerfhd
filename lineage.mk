# Release name
PRODUCT_RELEASE_NAME := aquaris_m8
CM_VENDOR := vendor/cm

# Inherit some common Lineage stuff.
$(call inherit-product, $(SRC_TARGET_DIR)/product/languages_full.mk)
$(call inherit-product, $(CM_VENDOR)/config/common_full_tablet_wifionly.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base.mk)

# Inherit device configuration
$(call inherit-product, device/bq/aquaris_m8/device_aquaris_m8.mk)

# Screen
TARGET_SCREEN_HEIGHT := 800
TARGET_SCREEN_WIDTH := 1280

# This is a tablet
PRODUCT_CHARACTERISTICS := tablet

# Bootanimation
TARGET_BOOTANIMATION_PRELOAD := true
TARGET_BOOTANIMATION_TEXTURE_CACHE := true

# Device identifier. This must come after all inclusions
PRODUCT_DEVICE := aquaris_m8
PRODUCT_NAME := lineage_aquaris_m8
PRODUCT_BRAND := google
PRODUCT_MODEL := Aquaris m8
PRODUCT_MANUFACTURER := bq

# GMS
PRODUCT_GMS_CLIENTID_BASE := android-bq

# Available languages
PRODUCT_LOCALES := en_US en_GB ru_RU uk_UA tr_TR sk_SK vi_VN fr_FR ar_EG
