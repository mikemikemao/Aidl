#include "MyService.h"
#include "utils/LogUtil.h"

using aidl::com::hikvision::aidlservice::MyService;

ScopedAStatus MyService::add(int32_t in_num1, int32_t in_num2, int32_t* _aidl_return)
{
    *_aidl_return = in_num1 + in_num2;
    LOGCATD("[MyService] [cpp] add: int=%d, long=%ld, _aidl_return=%d",in_num1, in_num2, *_aidl_return);
    return ScopedAStatus::ok();
}

ScopedAStatus MyService::getNum(int32_t* _aidl_return)
{
    *_aidl_return = 10;
    LOGCATD("[MyService] [cpp] getNum");
    return ScopedAStatus::ok();
}

ScopedAStatus MyService::minus(int32_t in_num1, int32_t in_num2, int32_t* _aidl_return)
{
    *_aidl_return = in_num1 - in_num2;
    LOGCATD("[MyService] [cpp] minus: int=%d, long=%ld, _aidl_return=%d",in_num1, in_num2, *_aidl_return);
    return ScopedAStatus::ok();
}
