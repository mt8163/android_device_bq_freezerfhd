/*
   Copyright (c) 2020, The LineageOS Project. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <log/log.h>
#include "vendor_init.h"
#include "property_service.h"
#include <android-base/file.h>
#include <android-base/logging.h>
#include <android-base/strings.h>
#include <android-base/properties.h>
#include <cutils/properties.h>
#include <sys/sysinfo.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#define SERIAL_CLASS "/sys/class/android_usb/android0/iSerial"
#define LOG_TAG "init_aquaris_m8"

using android::init::property_set;
using android::base::GetProperty;

void write_serial(std::string serial) {
    FILE *sn_class;

    /* Open the serial class */
    sn_class = fopen(SERIAL_CLASS, "w");

    if (sn_class == NULL) {
        ALOGE("[-] Could not open serial class!");
        android::init::property_set("ro.serial.helper.status", "failed");
    }

    /* Write the serial */
    fprintf(sn_class, "%s" , serial.c_str());
    fflush(sn_class);

    android::init::property_set("ro.serial.helper.status", "success");

    /* Close the serial class */
    fclose(sn_class);
} 

void property_override(char const prop[], char const value[])
{
    prop_info *pi;
    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void vendor_load_properties()
{
    const std::string override_serial = GetProperty("ro.override.serialno", "");
    const std::string device = GetProperty("ro.product.device", "");

    if (device.find("aquaris_m8") == 0) {
        ALOGI("[?] Setting propreties for Aquaris M8...");
        android::init::property_set("ro.build.fingerprint", "bq/Aquaris_M8/Aquaris_M8:6.0/MRA58K/1537280831:user/release-keys");
        android::init::property_set("ro.build.description", "full_bq_aquaris_m8-user 6.0 MRA58K 1537280832 release-keys");
        android::init::property_set("ro.product.device_is_m8", "true");
        android::init::property_set("ro.product.model", "Aquaris M8");
        android::init::property_set("ro.product.customer", "bq");
    } else {
        ALOGI("[?] Setting propreties for unknown device...");
        android::init::property_set("ro.product.device_is_m8", "false");
        android::init::property_set("ro.product.model", "Unknown");
        android::init::property_set("ro.product.customer", "unknown");
    }

     GetProperty("ro.override.serialno", "");

    /* Not real NULL, just a string with word 'NULL' */
    if (override_serial.find("NULL") != 0) {
        ALOGI("[?] Attempt to override the serial...");
        write_serial(override_serial);
    }

    ALOGI("[?] Exiting libinit...");
}
