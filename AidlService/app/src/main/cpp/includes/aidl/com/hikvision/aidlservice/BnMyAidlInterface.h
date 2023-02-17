#pragma once

#include "aidl/com/hikvision/aidlservice/IMyAidlInterface.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace com {
namespace hikvision {
namespace aidlservice {
class BnMyAidlInterface : public ::ndk::BnCInterface<IMyAidlInterface> {
public:
  BnMyAidlInterface();
  virtual ~BnMyAidlInterface();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace aidlservice
}  // namespace hikvision
}  // namespace com
}  // namespace aidl
