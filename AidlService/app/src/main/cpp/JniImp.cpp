//
// Created by pirate
//
#include <android/binder_ibinder.h>
#include "jni.h"
#include "utils/LogUtil.h"
#include "MyService.h"

#include <aidl/com/hikvision/aidlservice/IMyAidlInterface.h>
#include <android/binder_ibinder_jni.h>
using aidl::com::hikvision::aidlservice::MyService;
using namespace std;

extern "C" JNIEXPORT jobject JNICALL
Java_com_hikvision_HiAcs_createServiceBinder(
        JNIEnv* env,
        jobject /* this */)
{
    static MyService myService;
    return env->NewGlobalRef(AIBinder_toJavaBinder(env, myService.asBinder().get()));
}
