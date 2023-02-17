#pragma once

#include "aidl/com/hikvision/aidlservice/IMyAidlInterface.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace com {
namespace hikvision {
namespace aidlservice {
class BpMyAidlInterface : public ::ndk::BpCInterface<IMyAidlInterface> {
public:
  BpMyAidlInterface(const ::ndk::SpAIBinder& binder);
  virtual ~BpMyAidlInterface();

  ::ndk::ScopedAStatus add(int32_t in_num1, int32_t in_num2, int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getNum(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus minus(int32_t in_num1, int32_t in_num2, int32_t* _aidl_return) override;
};
}  // namespace aidlservice
}  // namespace hikvision
}  // namespace com
}  // namespace aidl
