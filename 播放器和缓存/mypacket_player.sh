#!/bin/bash

pushd ../../../../Trunk/PowerinfoInc/ijkplayer-android/android/ijkplayer/ijkplayer-java/build/outputs/aar
mkdir ddd
cp -v ijkplayer-java-release.aar ddd
cd ddd
mv ijkplayer-java-release.aar ijkplayer-java-release.zip
unzip -o ijkplayer-java-release.zip
cd ..
popd
cp -v ../../../../Trunk/PowerinfoInc/ijkplayer-android/android/ijkplayer/ijkplayer-java/build/outputs/aar/ddd/classes.jar   ../../../../Trunk/ClientSDK/LiveVideo/Platform/Android/VideoSenderAS/MeeLiveVideo/libs/ijkplayer-java.jar
