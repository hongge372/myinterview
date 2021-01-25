#!/bin/bash

export ANDROID_NDK=/Users/tools/sys/android-ndk-r10e

cd contrib/
sh compile-ffmpeg.sh armv7a
cd ..
sh compile-ijk.sh armv7a
