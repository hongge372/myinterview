#!/bin/bash

#********************************************************************************
#(1) #首先检查，或者如果发现有奇葩的问题时检查
#    比如ffmpeg编译configure死活不过，检查脚本是否有绝对路径(liujingcha)。
#(2) #编译64位ijkplayer时，需要先修改Application.mk，放开里面的64位编译开关。路径：
#    Trunk/PowerinfoInc/ijkplayer-android/android/ijkplayer/ijkplayer-armv7a/src/main/jni
#    如果放开后git发现64位没有更新，则检查是否添加到git中。
#(3) #ijk工程打aar的时候，使用ijkplayer-javax工程，并且只能使用assemblerelease
#(4) #sdk打包还需要修改：a. 打包编译的Application.mk,添加64位编译
#                     b. gradle的abifilter,添加64位编译
#    如果修改后编译有问题，可以先进到对应目录，直接ndk-build。看看是否可以。碰到个奇怪问题，gradle编译失败
#    ndk-build后奇迹般的好了
#********************************************************************************


#----------------------------------->
#准备工作：
#编译commonsdk
pushd Trunk/CommonModule/CommonSDKModule/CommonSDKModule.Android
sh BuildCommonSDKModuleForAndroid.sh armeabi-v7a
sh BuildCommonSDKModuleForAndroid.sh arm64-v8a
popd

#---------------------------------->
#编译ijk
export ANDROID_NDK=/Users/tools/android-ndk-r10e
clean_ffmpeg_in_ijk(){
    if [ -d "build" ]; then
	echo "old build is also exit"
#	rm -rf build
    fi
    sh compile-ffmpeg.sh clean
    rm `find ffmpeg-armv7a -name *.o`   
}

#compile ijkplayer
pushd Trunk/PowerinfoInc/ijkplayer-android/android
cd  contrib
echo "compile ffmpeg for arm64--->"
clean_ffmpeg_in_ijk
sh compile-ffmpeg.sh arm64
echo "64 end ---------------"
echo "compile ffmpeg for armv7--->"
clean_ffmpeg_in_ijk
sh compile-ffmpeg.sh armv7a
echo "v7 end ---------------"
cd ..
#当我们按照说明2放开64位编译选项后，这里会同时编译32和64位
#****************全部编译***********************#
sh compile-ijk.sh
#****************只v7**************************#
#sh compile-ijk.sh armv7a

#以下废弃------------>
#cd ijkplayer/ijkplayer-armv7a/src/main/jni
#当我们在Application.mk里面放开64位编译选项时，运行ndk-build可以直接编译两个版本。
#ndk-build <---------
popd #compile ijkplayer


#到这里结束
#打包sdk需要用androidstudio工程，里面打包（64位需要在abifilter中修改）
