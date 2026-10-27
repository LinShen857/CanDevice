# CanDevice

## 1. 模块作用

CAN 设备抽象基类：定义 `host_id`（发送帧 ID）、`motor_id`（接收帧 ID）与两条接收虚函数，并携带总线错误快照 `CanErrorInfo`。本身不可实例化（`standalone: false`），供电机、功率计等设备模块继承。

Base class for CAN devices. It carries the TX/RX frame ids and the bus error snapshot, and is not instantiable on its own.

## 2. 构造接口

```cpp
CanDevice(uint32_t host_id, uint32_t motor_id);
```

## 3. Topic

无 / None

## 4. 配置示例

库模块，不能被 `xrobot instance add` 实例化，只作为其他模块的依赖。

## 5. 依赖与硬件

模块依赖 / Module dependencies:

无 / None

硬件 / Hardware:

- 无（仅使用 `LibXR::CAN` 的类型定义）
