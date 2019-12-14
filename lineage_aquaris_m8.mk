$(call inherit-product, vendor/lineage/config/common_full_tablet_wifionly.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/product_launched_with_n_mr1.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/languages_full.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base.mk)
$(call inherit-product, device/common/gps/gps_us_supl.mk)
$(call inherit-product, device/bq/aquaris_m8/device.mk)

PRODUCT_CHARACTERISTICS := tablet

PRODUCT_DEVICE := aquaris_m8
PRODUCT_NAME := lineage_aquaris_m8
PRODUCT_BRAND := google
PRODUCT_MODEL := Aquaris M8
PRODUCT_BOARD := aquaris_m8
PRODUCT_MANUFACTURER := bq
