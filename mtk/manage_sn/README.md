Manage Android Serial Number
=================================================

* Android Serial Number Fixer/Changer. This binary runs at every boot and if enabled, will replace the serial number with one defined by the user.

* To enable set the prop ```ro.manage.serial.enabled``` to 1 in build.prop.

* To specify the serial that you want to change, set it to build.prop as ```ro.serial.override=12345678``` for example.

* The binary must be runned as root.
