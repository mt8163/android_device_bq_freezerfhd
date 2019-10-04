# Inherit from the common Open Source product configuration
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base.mk)

# Inherit from hardware-specific part of the product configuration
$(call inherit-product, device/bq/freezerfhd/device.mk)

PRODUCT_DEVICE := freezerfhd
PRODUCT_NAME := full_freezerfhd
PRODUCT_BRAND := google
PRODUCT_MODEL := Aquaris M10 FHD
PRODUCT_MANUFACTURER := bq # Bonito por fuera y feo por dentro xD
PRODUCT_RESTRICT_VENDOR_FILES := false

