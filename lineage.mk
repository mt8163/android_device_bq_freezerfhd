# Inherit some common Lineage stuff.
$(call inherit-product, vendor/lineage/config/common_full_tablet_wifionly.mk)

# Inherit device configuration for the BQ Aquaris M8
$(call inherit-product, device/bq/aquaris_m8/lineage_aquaris_m8.mk)

# Product defines
PRODUCT_NAME := lineage_aquaris_m8
PRODUCT_RELEASE_NAME := aquaris_m8
