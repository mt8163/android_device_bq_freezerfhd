Android Device Tree For BQ Aquaris M8
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

This branch is for building LineageOS 15.1 or any other Android 8.1 based ROM.

### BUILD ###
```
export ANDROID_JACK_VM_ARGS="-Dfile.encoding=UTF-8 -XX:+TieredCompilation -Xmx4G"
source ./build/envsetup.sh
lunch lineage_aquaris_m8-userdebug
brunch lineage_aquaris_m8-userdebug -j12
```

### WORKING/BUGS ###
- [ ] Wi-Fi
- [ ] Bluetooth
- [ ] OMX
- [ ] Radio FM
- [ ] Boots
- [ ] HWC
- [ ] Gralloc
- [ ] GPS
- [ ] Camera
- [ ] Video Recording
- [ ] Sound
- [ ] Offline charging

### Thanks To ###
- Kaijones23
- ibilux for the Hermes Device Tree
- carlitos900 for the Kernel
- huckleberrypie
- JMPF6