# TWRP device tree for Aquaris M8
## Build Instructions
```sh
cd device
mkdir malatamobile
cd malatamobile
git clone https://github.com/R0rtiz2/android_device_bq_Aquaris_M8.git
mv android_device_bq_Aquaris_M8 Aquaris_M8
cd ..
cd ..
export ALLOW_MISSING_DEPENDENCIES=true
. build/envsetup.sh
lunch Aquaris_M8-eng
mka recoveryimage
```
Thanks to @diplomatic (xda)
