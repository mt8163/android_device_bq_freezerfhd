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

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"
#include <sys/sysinfo.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#define SERIAL_CLASS "/sys/class/android_usb/android0/iSerial"

int write_serial(char *serial) {
    FILE *sn_class

    /* Open the serial class */
    sn_class = fopen(SERIAL_CLASS, "w");

    if (sn_class == NULL) {
        ERROR("[-] Could not open serial class!");
        return -1;
    }

    /* Write the serial */
    fprintf(sn_class, "%s" , serial);
    fflush(sn_class);

    INFO("[+] Wrote %s to the serial class...", serial);

    /* Close the serial class */
    fclose(sn_class);
    return 0;
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
    std::string platform;
    std::string device;
    std::string override_serial;

    device = property_get("ro.product.device");

    if (device == "aquaris_m8") {
        property_set("ro.build.fingerprint", "bq/Aquaris_M8/Aquaris_M8:6.0/MRA58K/1537280831:user/release-keys");
        property_set("ro.product.device_is_m8", "true");
        property_set("ro.product.model", "Aquaris M8");
        property_set("ro.product.customer", "bq");
    } else {
        property_set("ro.product.device_is_m8", "false");
        property_set("ro.product.model", "Unknown");
        property_set("ro.product.customer", "unknown");
    }

    override_serial = property_get("ro.override.serialno");

    if (override_serial[0] != '\0') {
        INFO("[?] Attempt to override the serial...");
        write_serial(override_serial);
    }

    INFO("[?] Exiting libinit...");
}
