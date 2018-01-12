LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_LDLIBS += -L$(SYSROOT)/usr/lib -llog
LOCAL_MODULE := lltest
LOCAL_SRC_FILES := src/ll_test.c
LOCAL_C_INCLUDES := include/
LOCAL_EXPORT_C_INCLUDES := include/

include $(BUILD_SHARED_LIBRARY)

