#pragma once

#include <aidl/com/hikvision/aidlservice/BnMyAidlInterface.h>

using ndk::ScopedAStatus;

namespace aidl {
namespace com {
namespace hikvision {
namespace aidlservice {

class MyService : public BnMyAidlInterface
{
public:
    ScopedAStatus add(int32_t in_num1, int32_t in_num2, int32_t* _aidl_return) override;
    ScopedAStatus getNum(int32_t* _aidl_return) override;
    ScopedAStatus minus(int32_t in_num1, int32_t in_num2, int32_t* _aidl_return) override;
};

} // namespace example
} // namespace com
} // namespace aidl
}