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
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <sstream>
#include <ctime>

#include <sys/sysinfo.h>

#include <log/log.h>
#include <cutils/properties.h>

#include "vendor_init.h"
#include "property_service.h"

#include <android-base/file.h>
#include <android-base/logging.h>
#include <android-base/strings.h>
#include <android-base/properties.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#define SERIAL_LENGTH 17

using android::init::property_set;
using android::base::GetProperty;

void write_serial(std::string serial) {

    const std::string proinfo = "/dev/block/platform/soc/11230000.mmc/by-name/proinfo";

    /* Sanity check of the serial length */
    if (serial.length() != SERIAL_LENGTH) {
        LOG(ERROR) << "[!] Serial lenght is invalid. Expected 17 but got " << serial.length() <<std::endl;
        exit(1);
    }

    /* Before overwriting the PRO_INFO block create a copy in /data/local/tmp so user can restore it if the overwriting was not expected */
    LOG(ERROR) << "[!] WARNING WARNING WARNING WARNING: You're about to overwrite the PRO_INFO block";
    LOG(ERROR) << "[!] If this is not expected, restore the backup of PRO_INFO (/data/local/tmp/proinfo_backup) in next boot";
    LOG(ERROR) << "[!] And disable the serial overwriting in the build prop!\n";

    /* Copy backup */
    std::ifstream srce(proinfo, std::ios::binary);
    std::ofstream dest("/data/local/tmp/proinfo_backup", std::ios::binary);
    dest << srce.rdbuf();

    /* Open PRO_INFO block */
    std::fstream processedFile(proinfo.c_str());
    std::stringstream fileData;

    /* Write the serial */
    LOG(ERROR) << "[?] Writing " << serial << " with length of " << serial.length() << " to the PRO_INFO block...";
    fileData << serial;

    fileData << processedFile.rdbuf();
    processedFile.close();

    processedFile.open(proinfo.c_str(), std::fstream::out | std::fstream::trunc); 
    processedFile << fileData.rdbuf();

    android::init::property_set("ro.serial.helper.status", "success");
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

void property_override_dual(char const system_prop[],
        char const vendor_prop[], char const value[])
{
    property_override(system_prop, value);
    property_override(vendor_prop, value);
}

void vendor_load_properties()
{
    LOG(ERROR) << "[#] Starting libinit...\n";

    const std::string override_serial = GetProperty("ro.override.serialno", "");
    const std::string device = GetProperty("ro.product.device", "");

    std::ifstream model;
    std::string line;

    model.open("/sys/firmware/devicetree/base/model");

    /* Check for MT8163 */
    while(getline(model, line)) {
        if (line.find("MT8163") == 0) {
            LOG(ERROR) << "[?] Setting platform to mt8163...\n";
            property_override("ro.board.platform", "mt8163");
        } else {
            property_override("ro.board.platform", "unknown");
        }
    }

    /* Check for device (aquaris_m8) */
    if (device.find("aquaris_m8") == 0) {
        LOG(ERROR) << "[?] Setting propreties for Aquaris M8...\n";
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "bq/Aquaris_M8/Aquaris_M8:6.0/MRA58K/1537280831:user/release-keys");
        property_override("ro.build.description", "full_bq_aquaris_m8-user 6.0 MRA58K 1537280832 release-keys");
        property_override("ro.product.device_is_m8", "true");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "Aquaris M8");
        property_override("ro.product.customer", "bq");
    } else {
        LOG(ERROR) << "[?] Setting propreties for unknown device...\n";
        property_override("ro.product.device_is_m8", "false");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "Unknown");
        property_override("ro.product.customer", "unknown");
    }

    /* Not real NULL, just a string with word 'NULL' */
    /* Serial overwriting is not recommended as may mess up PRO_INFO block. THIS IS ONLY FOR TESTING. You have been warned.. */
    if (override_serial.find("NULL") != 0) {
        LOG(ERROR) << "[?] Attempt to override the serial...\n";
        write_serial(override_serial);
    }

    LOG(ERROR) << "[?] Exiting libinit...";
}
