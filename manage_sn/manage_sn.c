/*
 * Copyright (C) 2020 Roger Ortiz Leal
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <cutils/properties.h>
#include <log/log.h>

#define LOG_TAG "manage_sn"
#define SERIAL_CLASS "/sys/class/android_usb/android0/iSerial"

char serial[1024];

int write_sn(char *sn) 
{
               FILE *sn_class;
               int sn_class_close;

               /* Open file */
               sn_class = fopen(SERIAL_CLASS, "w");

               if (sn_class == NULL) {
                   ALOGE("Cannot open serial class. Are you root?");
                   exit(1);
               }
                 
               /* Write serial */
               fprintf(sn_class, "%s" , sn);
               fflush(sn_class);

               /* Close file */
               sn_class_close = fclose(sn_class);

               if (sn_class_close != 0) {
                   ALOGE("Cannot close serial class");
                   exit(1);
               }
               
               return 0;
}

int main()
{
        ALOGI("*** START ***");

        __system_property_get("ro.serial.override", serial);

        if (strcmp(serial, "") == 0) {
            ALOGE("Didn't specified the serial to override. Abort!");
            exit(1);
        }

        ALOGI("Attempt to override serial: %s", serial);

        write_sn(serial);

        FILE *sn_class = fopen(SERIAL_CLASS, "r");

        if (sn_class == NULL) {
              ALOGE("Cannot open serial class. Are you root?");
              exit(1);
        }

        char iSerial[1024];

        while(fgets(iSerial, sizeof iSerial, sn_class)!= NULL) {}

        ALOGI("Recheck S/N: %s", iSerial);

        fclose(sn_class);

        if(strstr(iSerial, serial) != NULL) {
            ALOGI("Serial written succsesfully!");
            __system_property_set("ctl.restart", "adbd");
            ALOGI("*** END ***");        
            return 0;
            exit(0);
        }
        else {
            ALOGE("Something went wrong while writting the serial. Abort");
            return 1;
            exit(1);
        }

}
