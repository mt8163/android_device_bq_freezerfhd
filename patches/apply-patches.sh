#!bin/bash

PATCHES_DIR="device/bq/aquaris_m8/patches" # Change this with your device path!

echo "Applying patches..."

cd external/apache-http

git apply -v ../../$PATCHES_DIR/external/apache-http/0001-FIX-APACHE-HTTP-BUILD-ERROR.patch

cd ../..

echo "Patching complete!"

