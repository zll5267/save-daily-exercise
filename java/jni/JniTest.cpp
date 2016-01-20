#include "JniTest.h"
#include <iostream>


JNIEXPORT void JNICALL Java_JniTest_native_1helloworld
  (JNIEnv *, jclass)
{
    std::cout << "native Hello World" << std::endl;
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    JNIEnv* env = NULL;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        std::cout << "GetEnv failed" << std::endl;
        return JNI_ERR;
    }
    const char* kClassName = "JniTest";
    char* nativeName = (char*)"native_helloworld";
    char* signature = (char*)"()V";
    const JNINativeMethod kJniMethods[] = {
        { nativeName, signature,
            reinterpret_cast<void*>(Java_JniTest_native_1helloworld) },
    };

    jclass clazz = env->FindClass(kClassName);
    if (!clazz) {
        std::cout << "Find class:" << kClassName << " failed" << std::endl;
        return JNI_ERR;
    }
    env->RegisterNatives(clazz, kJniMethods, 1);//NELEM(kJniMethods));
    std::cout << "JNI_OnLoad OK" << std::endl;
    return JNI_VERSION_1_6;
}
