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

- [x] Build memtrack:
```
02-14 03:10:31.326   192   192 E memtrack: Couldn't load memtrack module (No such file or directory)
```

- [ ] Fix AudioAlsaVoiceWakeUpController:
```
02-14 03:10:32.495   194   194 E AudioALSAVoiceWakeUpController: Error: Audio VOWCFG2 Data invalid value
02-14 03:10:32.495   194   194 E AudioALSAVoiceWakeUpController: Error: Audio VOWCFG3 Data invalid value
02-14 03:10:32.495   194   194 E AudioALSAVoiceWakeUpController: Error: Audio VOWCFG4 Data invalid value
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

- [x] Fix ALSA spam:
```
02-14 03:10:32.512   194   323 E AudioALSAStreamOut: -getPresentationPosition(), no playback handler, *frames = 0, return
```

- [x] Fix missing effects libs:
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

- [x] Fix Wi-Fi:
```
02-14 03:26:51.996   340   353 D WifiService: setWifiEnabled: true pid=669, uid=10029
02-14 03:26:51.996   340   600 E WifiMonitor: killSupplicant p2ptrue init.svc.wpa_supplicant=unknown init.svc.p2p_supplicant=unknown
02-14 03:26:52.154   205   593 E WifiHW  : Failed to write wlan fw path param (I/O error)
02-14 03:26:52.155   205   593 E SoftapController: Softap fwReload failed
02-14 03:26:52.157   340   600 E WifiStateMachine: Failed to reload STA firmware java.lang.IllegalStateException: command '22 softap fwreload wlan0 STA' failed with '400 22 SoftAP command has failed'
02-14 03:26:52.158   340   340 E WifiController: WifiControllerWifi turn on failed
```

- [ ] Fix "No internet":
```
01-07 15:33:47.871   206   628 E Netd    : interface wlan0 not assigned to any netId
01-07 15:33:47.871   379   631 E NetdConnector: NDC Command {267 bandwidth removeiquota wlan0} took too long (1243ms)
01-07 15:33:47.872   379   638 E NetdConnector: NDC Command {268 network route add 106 wlan0 0.0.0.0/0 XXXXXXXX} took too long (1243ms)
01-07 15:33:47.872   379   638 E ConnectivityService: Exception in addRoute for gateway: java.lang.IllegalStateException: command '268 network route add 106 wlan0 0.0.0.0/0 XXXXXXXX' failed with '400 268 addRoute() failed (No such device)'
01-07 15:33:47.872   379   638 D ConnectivityService: Setting DNS servers for network 106 to [/XXXXXXXX]
01-07 15:33:47.877   379   638 W ConnectivityExtension: ConnectivityExt jar file not present
01-07 15:33:47.881   379   638 W ConnectivityExtension: ConnectivityExt jar file not present
01-07 15:33:47.882   379   634 D WifiNetworkAgent: NetworkAgent: Received signal strength thresholds: []
01-07 15:33:47.883   379   638 D ConnectivityService: Switching to new default network: NetworkAgentInfo{ ni{[type: WIFI[], state: CONNECTED/CONNECTED, reason: (unspecified), extra: "AndroidAP_7760", failover: false, available: true, roaming: false, metered: false]}  network{106}  nethandle{455282969310}  lp{{InterfaceName: wlan0 LinkAddresses: [fe80::208:22ff:fe3e:3d20/64,XXXXXXX,]  Routes: [fe80::/64 -> :: wlan0,XXXXXXXXX -> 0.0.0.0 wlan0,0.0.0.0/0 -> XXXXXXXX wlan0,] DnsAddresses: [XXXXXXX,] Domains: null MTU: 0 TcpBufferSizes: 524288,1048576,2097152,262144,524288,1048576}}  nc{[ Transports: WIFI Capabilities: INTERNET&NOT_RESTRICTED&TRUSTED&NOT_VPN&FOREGROUND LinkUpBandwidth>=1048576Kbps LinkDnBandwidth>=1048576Kbps SignalStrength: -37]}  Score{20}  everValidated{false}  lastValidated{false}  created{true} lingering{false} explicitlySelected{true} acceptUnvalidated{false} everCaptivePortalDetected{false} lastCaptivePortalDetected{false} }
01-07 15:33:47.885   379  2946 D NetworkMonitor/NetworkAgentInfo [WIFI () - 106]: PROBE_DNS FAIL 2ms, connectivitycheck.gstatic.com
01-07 15:33:47.886   379  2945 D NetworkMonitor/NetworkAgentInfo [WIFI () - 106]: PROBE_DNS FAIL 2ms, www.google.com
01-07 15:33:47.886   379  2946 W System  : ClassLoader referenced unknown path: /system/framework/tcmclient.jar
01-07 15:33:47.888   379  2945 D NetworkMonitor/NetworkAgentInfo [WIFI () - 106]: Probably not a portal: exception java.net.UnknownHostException: Unable to resolve host "www.google.com": No address associated with hostname
01-07 15:33:47.888   379  2946 D NetworkMonitor/NetworkAgentInfo [WIFI () - 106]: Probably not a portal: exception java.net.UnknownHostException: Unable to resolve host "connectivitycheck.gstatic.com": No address associated with hostname
01-07 15:33:47.890   379  2907 D NetworkMonitor/NetworkAgentInfo [WIFI () - 106]: Probably not a portal: exception java.net.UnknownHostException: Unable to resolve host "www.google.com": No address associated with hostname
01-07 15:33:48.119   206   628 V IdletimerController: runCmd(/system/bin/ip6tables -w -t raw -A idletimer_raw_PREROUTING -i wlan0 -j IDLETIMER --timeout 15 --label 1 --send_nl_msg 1) res_ipv4=0, res_ipv6=0
01-07 15:33:48.353   206   628 V IdletimerController: runCmd(/system/bin/ip6tables -w -t mangle -A idletimer_mangle_POSTROUTING -o wlan0 -j IDLETIMER --timeout 15 --label 1 --send_nl_msg 1) res_ipv4=0, res_ipv6=0
01-07 15:33:48.356   379   638 D ConnectivityService: Sending CONNECTED broadcast for type 1 NetworkAgentInfo [WIFI () - 106] isDefaultNetwork=true
01-07 15:33:48.357   379   638 D ConnectivityService: NetworkAgentInfo [WIFI () - 106] EVENT_NETWORK_INFO_CHANGED, going from CONNECTED to DISCONNECTED
01-07 15:33:48.357   379   638 D ConnectivityService: NetworkAgentInfo [WIFI () - 106] validation failed
01-07 15:33:48.357   379   638 D ConnectivityService: NetworkAgentInfo [WIFI () - 106] got DISCONNECTED, was satisfying 4
01-07 15:33:48.359   379   634 D WifiNetworkAgent: NetworkAgent: NetworkAgent channel lost
01-07 15:33:48.362  1225  1225 D WeatherUpdateService: onCreate
01-07 15:33:48.363   379   638 W ConnectivityExtension: ConnectivityExt jar file not present
01-07 15:33:48.364  1225  1225 D WeatherUpdateService: Service started, but shouldn't update ... stopping
01-07 15:33:48.368  1225  1225 D WeatherUpdateService: onDestroy
01-07 15:33:48.600   206   628 V IdletimerController: runCmd(/system/bin/ip6tables -w -t raw -D idletimer_raw_PREROUTING -i wlan0 -j IDLETIMER --timeout 15 --label 1 --send_nl_msg 1) res_ipv4=0, res_ipv6=0
01-07 15:33:48.833   206   628 V IdletimerController: runCmd(/system/bin/ip6tables -w -t mangle -D idletimer_mangle_POSTROUTING -o wlan0 -j IDLETIMER --timeout 15 --label 1 --send_nl_msg 1) res_ipv4=0, res_ipv6=0
01-07 15:33:48.833   379   638 D ConnectivityService: Sending DISCONNECTED broadcast for type 1 NetworkAgentInfo [WIFI () - 106] isDefaultNetwork=true
```

- [x] Fix VSYNC:
```
02-14 03:26:54.265   174   224 W hwcomposer: [JOB] (0) Timed out waiting for vsync...
```

- [x] Fix bluetooth.
