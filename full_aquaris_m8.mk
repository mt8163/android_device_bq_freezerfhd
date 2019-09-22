# Inherit from the common Open Source product configuration
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base.mk)

# Inherit from hardware-specific part of the product configuration
$(call inherit-product, device/bq/aquaris_m8/device.mk)

PRODUCT_DEVICE := aquaris_m8
PRODUCT_NAME := full_aquaris_m8
PRODUCT_BRAND := google
PRODUCT_MODEL := Aquaris M8
PRODUCT_MANUFACTURER := bq
PRODUCT_RESTRICT_VENDOR_FILES := false

