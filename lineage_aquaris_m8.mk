#
# Copyright (C) 2016 The CyanogenMod Project
# Copyright (C) 2017 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# Inherit framework first
$(call inherit-product, $(SRC_TARGET_DIR)/product/languages_full.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base.mk)

# Inherit from aqauris_m8 device
$(call inherit-product, device/bq/aquaris_m8/device.mk)

# Inherit from common device
$(call inherit-product, device/common/gps/gps_us_supl.mk)

# Inherit some common LineageOS stuff.
$(call inherit-product, vendor/lineage/config/common_full_tablet_wifionly.mk)

PRODUCT_CHARACTERISTICS := tablet

# Set those variables here to overwrite the inherited values.
PRODUCT_DEVICE := aquaris_m8
PRODUCT_NAME := lineage_aquaris_m8
PRODUCT_BRAND := google
PRODUCT_MODEL := Aquaris M8
PRODUCT_BOARD := aquaris_m8
PRODUCT_MANUFACTURER := bq

PRODUCT_BUILD_PROP_OVERRIDES += \
   PRODUCT_NAME=aquaris_m8
