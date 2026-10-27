#pragma once

// clang-format off
/* === MODULE MANIFEST V2 ===
module_description: CAN 设备抽象基类与总线错误快照
depends: []
standalone: false
=== END MANIFEST === */
// clang-format on

#include <cstdint>

#include "can.hpp"

struct CanErrorInfo
{
  uint32_t count = 0;
  LibXR::CAN::ErrorID last = LibXR::CAN::ErrorID::CAN_ERROR_ID_GENERIC;
  LibXR::CAN::ErrorState state {};
};

class CanDevice
{
 public:
  CanDevice(uint32_t host_id_, uint32_t motor_id_)
      : host_id(host_id_), motor_id(motor_id_)
  {
  }

  virtual ~CanDevice() = default;

  virtual void OnClassicFrame(const LibXR::CAN::ClassicPack& frame) = 0;

  virtual void OnFdFrame(const LibXR::FDCAN::FDPack& frame)
  {
    (void)frame;
  }

  void SetBusError(const CanErrorInfo& info)
  {
    can_error = info;
  }

  /// 发送帧 ID / TX frame id.
  const uint32_t host_id;
  /// 接收帧 ID，也是总线分发时的匹配键 / RX frame id, the dispatch key.
  const uint32_t motor_id;
  CanErrorInfo can_error;
};
