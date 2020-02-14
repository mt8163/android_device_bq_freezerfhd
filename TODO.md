### TODO LIST ###
- [ ] Camera missing symbols:
```
02-14 03:10:29.637   195   195 E HAL     : load: module=/system/lib/hw/camera.mt8163.so
02-14 03:10:29.637   195   195 E HAL     : dlopen failed: cannot locate symbol "_ZN7android13GraphicBufferC1Ejjij" referenced by "/system/lib/libcam_utils.so"...
02-14 03:10:29.637   195   195 E CameraService: Could not load camera HAL module: -22 (Invalid argument)
```

- [ ] Fix agps permissions:
```
02-14 03:10:29.744   186   186 D agps    : [MNL2AGPS] mnl2agps_mnl_reboot
02-14 03:10:29.745   186   186 E agps    : ERR: [MNL2AGPS] sendto dest=[/data/agps_supl/mnl_to_agps] len=8 reason=[No such file or directory]
02-14 03:10:29.745   186   186 E agps    : ERR: [MNL2AGPS] external_snd_cmd safe_sendto failed
02-14 03:10:29.746   186   186 E MNLD    : hal_sock_mnld: bind failed path=[/data/gps_mnl/hal2mnld] reason=[Permission denied]
```

- [ ] Build memtrack:
```
02-14 03:10:31.326   192   192 E memtrack: Couldn't load memtrack module (No such file or directory)
```

- [ ] Fix AudioAlsaVoiceWakeUpController:
```
02-14 03:10:32.495   194   194 E AudioALSAVoiceWakeUpController: Error: Audio VOWCFG2 Data invalid value
02-14 03:10:32.495   194   194 E AudioALSAVoiceWakeUpController: Error: Audio VOWCFG3 Data invalid value
02-14 03:10:32.495   194   194 E AudioALSAVoiceWakeUpController: Error: Audio VOWCFG4 Data invalid value```
```

- [ ] Fix nvram's fstab:
```
02-14 03:10:32.496   194   194 D NVRAM   : failed to read /data/nvram/fstab.mt8163 
02-14 03:10:32.496   194   194 D NVRAM   : failed to read fstab 
02-14 03:10:32.496   194   194 D NVRAM   : failed to get partition path
```

- [ ] Fix invalid values for audio:
```
02-14 03:10:32.497   194   194 E AudioALSAVolumeController: Error: Headset_PGAL_GAIN invalid value
02-14 03:10:32.497   194   194 E AudioALSAVolumeController: Error: SetSpeakerGain invalid value
```

- [ ] Fix ALSA spam:
```
02-14 03:10:32.512   194   323 E AudioALSAStreamOut: -getPresentationPosition(), no playback handler, *frames = 0, return
```

- [ ] Fix missing effects libs:
```
02-14 03:10:32.511   194   194 W EffectsFactory: loadLibrary() failed to open /system/vendor/lib/soundfx/libswdap.so
02-14 03:10:32.511   194   194 W EffectsFactory: loadLibrary() failed to open /system/vendor/lib/soundfx/libhwdap.so
```

- [ ] Fix FFMPEG:
```
02-14 03:10:32.554   192   192 E FFMPEGSoftCodec: Failed to load FFMPEG plugin: (null)
```

- [ ] Fix sensors:
```
02-14 03:11:01.235   340   357 E SensorService: sensor batch failed 0x7f7a659c00 1 0 66667000 100000000 err=Operation not permitted
02-14 03:11:01.235   340   357 E Sensors : handleToDriver handle(0)
02-14 03:11:01.235   340   357 E Sensors : handleToDriver handle(0)
02-14 03:11:01.239   340   357 E Sensors : new setDelay handle(0),ns(66667000)m, error(0), index(2)
02-14 03:11:01.240   340   357 E Sensors : sensor 0 go to common batch
02-14 03:11:12.118   340   396 E PROXIMITY: ProximitySensor: unknown event (type=3, code=0)
```

- [ ] Fix null pointer reference (LiveDisplay):
```
02-14 03:11:01.397   669   779 W Tile.LiveDisplayTile: java.lang.NullPointerException: Attempt to invoke virtual method 'boolean cyanogenmod.hardware.LiveDisplayConfig.hasModeSupport()' on a null object reference
```

- [ ] Fix Wi-Fi:
```
02-14 03:26:51.996   340   353 D WifiService: setWifiEnabled: true pid=669, uid=10029
02-14 03:26:51.996   340   600 E WifiMonitor: killSupplicant p2ptrue init.svc.wpa_supplicant=unknown init.svc.p2p_supplicant=unknown
02-14 03:26:52.154   205   593 E WifiHW  : Failed to write wlan fw path param (I/O error)
02-14 03:26:52.155   205   593 E SoftapController: Softap fwReload failed
02-14 03:26:52.157   340   600 E WifiStateMachine: Failed to reload STA firmware java.lang.IllegalStateException: command '22 softap fwreload wlan0 STA' failed with '400 22 SoftAP command has failed'
02-14 03:26:52.158   340   340 E WifiController: WifiControllerWifi turn on failed
```

- [ ] Fix VSYNC:
```
02-14 03:26:54.265   174   224 W hwcomposer: [JOB] (0) Timed out waiting for vsync...
```
