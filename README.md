Device Tree For BQ Aquaris M8
=================================================
About Device:
![alt text](http://i1.wp.com/www.blogtecnologia.es/wp-content/uploads/2017/02/bq.jpg)
=====================================
Basic   | Spec Sheet
-------:|:-------------------------
CPU     | 1.30 Mhz Quad-Core 
CHIPSET | Mediatek MT8163B
GPU     | MediaTek Mali-T720 MP2
Kernel  | 3.18.22+
Memory  | 2 GB
Shipped Android Version | Android 6.0.1
Storage | 16GB
MicroSD | 256 GB
Battery | LiPo 7280 mAh (non-removable)
Dimensions | 246 x 171 x 8.2 mm
Display | 1280 x 800 pixels, 8"
Rear Camera  | 5.0 MP
Front Camera | 2.0 MP

This branch is for building CyanogenMod 14.1/LineageOS 14.1 or any other Android 7.x based ROM.

### BUILD ###
```
export ANDROID_JACK_VM_ARGS="-Dfile.encoding=UTF-8 -XX:+TieredCompilation -Xmx4G"
source ./build/envsetup.sh
lunch lineage_aquaris_m8-userdebug
brunch lineage_aquaris_m8-userdebug -j12
```

### WORKING/BUGS ###
- [x] Wi-Fi
- [x] Bluetooth
- [x] OMX
- [x] Radio FM
- [x] Boots
- [x] HWC
- [x] Gralloc
- [ ] GPS
- [ ] Camera
- [ ] Video Recording
- [x] Sound
- [x] Offline charging
