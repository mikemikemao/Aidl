#pragma once

#include <android/binder_interface_utils.h>

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace com {
namespace hikvision {
namespace aidlservice {
class IMyAidlInterface : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IMyAidlInterface();
  virtual ~IMyAidlInterface();



  static std::shared_ptr<IMyAidlInterface> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IMyAidlInterface>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IMyAidlInterface>* instance);
  static bool setDefaultImpl(std::shared_ptr<IMyAidlInterface> impl);
  static const std::shared_ptr<IMyAidlInterface>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus add(int32_t in_num1, int32_t in_num2, int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getNum(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus minus(int32_t in_num1, int32_t in_num2, int32_t* _aidl_return) = 0;
private:
  static std::shared_ptr<IMyAidlInterface> default_impl;
};
class IMyAidlInterfaceDefault : public IMyAidlInterface {
public:
  ::ndk::ScopedAStatus add(int32_t in_num1, int32_t in_num2, int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getNum(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus minus(int32_t in_num1, int32_t in_num2, int32_t* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace aidlservice
}  // namespace hikvision
}  // namespace com
}  // namespace aidl
