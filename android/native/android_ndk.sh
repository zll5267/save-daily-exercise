#!/bin/bash
#ndk-build NDK_PROJECT_PATH=.  TARGET_PLATFORM=android-14 TARGET_ARCH=arm TARGET_ABI=android-14-armeabi-v7a TARGET_ARCH_ABI=armeabi-v7a APP_BUILD_SCRIPT=./Android.mk
#this is only a example to compile for android
#before run this script, ndk should be installed and ndk-build command should work.
#ndk-build NDK_PROJECT_PATH=.  APP_PLATFORM=android-14 APP_BUILD_SCRIPT=./Android.mk TARGET_OUT='out/android/$(TARGET_ARCH_ABI)' $@
#ndk-build NDK_PROJECT_PATH=.  APP_ABI=armeabi-v7a APP_PLATFORM=android-14 APP_BUILD_SCRIPT=./Android.mk TARGET_OUT='out/android/$(TARGET_ARCH_ABI)' $@
ndk-build NDK_PROJECT_PATH=.  APP_PLATFORM=android-14 APP_BUILD_SCRIPT=./Android.mk TARGET_OUT='out/android/$(TARGET_ARCH_ABI)' $@
