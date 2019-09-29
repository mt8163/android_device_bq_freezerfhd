$(call inherit-product-if-exists, vendor/cm/config/common_full_tablet_wifionly.mk)

$(call inherit-product, device/bq/freezerfhd/full_freezerfhd.mk)


TARGET_SCREEN_WIDTH := 1920
TARGET_SCREEN_HEIGHT := 1200

PRODUCT_CHARACTERISTICS := tablet

PRODUCT_NAME := cm_freezerfhd
PRODUCT_RELEASE_NAME := freezerfhd
