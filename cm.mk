$(call inherit-product-if-exists, vendor/cm/config/common_full_tablet_wifionly.mk)

$(call inherit-product, device/bq/aquaris_m8/full_aquaris_m8.mk)


TARGET_SCREEN_WIDTH := 1280
TARGET_SCREEN_HEIGHT := 800

PRODUCT_CHARACTERISTICS := tablet

PRODUCT_NAME := cm_aquaris_m8
PRODUCT_RELEASE_NAME := aquaris_m8
