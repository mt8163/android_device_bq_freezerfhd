#!bin/bash

PATCHES_DIR="device/bq/aquaris_m8/patches" # Change this with your device path!

echo "Applying patches..."

cd external/apache-http

git apply -v ../../$PATCHES_DIR/external/apache-http/0001-FIX-APACHE-HTTP-BUILD-ERROR.patch

cd ../..

cd system/core

git apply -v ../../$PATCHES_DIR/system/core/0002-FIX-MISSING-XLOG-SYMBOL.patch

cd ../..

cd frameworks/native

git apply -v ../../$PATCHES_DIR/frameworks/native/0003-MTK-PATCH-FOR-FRAMEWORKS-NATIVE.patch

cd ../..

echo "Patching complete!"
