#!/system/bin/sh

#
# Bluetooth setup helper
#

BLUETOOTH_FOLDER=/system/etc/bluetooth

LOGI="log -p i -t bt_init"
LOGE="log -p w -e bt_init"
LOGW="log -p w -t bt_init"
LOGF="log -p f -t bt_init"

$LOGI "Bluetooth INIT Start"

id | grep uid=0\(root\)
ROOT=$?

if [ "$ROOT" != 0 ]; then
   $LOGF " *** CANNOT CONTINUE! NOT RUNNING AS ROOT! ***"
   exit 1
fi

mount -o rw,remount /system
RES=$?

if [ "$RES" != 0 ]; then
   $LOGE "Cannot mount system as r/w... Abort!"
   exit 1
fi

mount -o rw,remount /
RES=$?

if [ "$RES" != 0 ]; then
   $LOGE "Cannot mount initramfs as r/w... Abort!"
   exit 1
fi

$LOGI "Symlink: $BLUETOOTH_FOLDER /etc/bluetooth"

ln -s /system/etc/bluetooth /etc/bluetooth
RES=$?

if [ "$RES" != 0 ]; then
   $LOGE "Cannot symlink bluetooth folder... Abort!"
   exit 1
fi

mount -o ro,remount /system
mount -o ro,remount /

$LOGI "All seems to be in his place. Exit as 0"

$LOGI "Bluetooth INIT end"

exit 0
