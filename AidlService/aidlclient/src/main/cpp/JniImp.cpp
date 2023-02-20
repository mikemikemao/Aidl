//
// Created by pirate
//
#include <android/binder_ibinder.h>
#include "jni.h"
#include "utils/LogUtil.h"
#include <android/binder_ibinder_jni.h>
#include "aidl/com/hikvision/aidlservice/IMyAidlInterface.h"

using namespace std;
using aidl::com::hikvision::aidlservice::IMyAidlInterface;
std::shared_ptr<IMyAidlInterface> g_spMyService;

extern "C" JNIEXPORT void JNICALL
Java_com_hikvision_HiAcs_onServiceConnected(
        JNIEnv* env,
        jobject /* this */,
        jobject binder)
{
    if( g_spMyService == nullptr){
        AIBinder* pBinder = AIBinder_fromJavaBinder(env, binder);
        const ::ndk::SpAIBinder spBinder(pBinder);
        g_spMyService = IMyAidlInterface::fromBinder(spBinder);
        LOGCATD("[App] [cpp] onServiceConnected");
    } else{
        LOGCATD("please disconnect first");
    }

}

extern "C" JNIEXPORT void JNICALL
Java_com_hikvision_HiAcs_onServiceDisconnected(
        JNIEnv* env,
        jobject /* this */)
{
    if (g_spMyService != nullptr){
        g_spMyService = nullptr;
    }
    LOGCATD("[App] [cpp] onServiceDisconnected");
}

extern "C" JNIEXPORT void JNICALL
Java_com_hikvision_HiAcs_operation(
        JNIEnv* env,
        jobject /* this */,
        jint command)
{
    int result = 0;
    if (g_spMyService != nullptr){
        g_spMyService->add(3,5,&result);
        LOGCATD("[App] [cpp] result = %d",result);
    }

}