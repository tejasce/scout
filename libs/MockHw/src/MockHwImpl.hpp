#pragma once

#include <cstdint>

namespace scout {
namespace mock_hw {

/*
 * Note that, the mode MockHw implements in an opaque detail in this implementation.
 * Assumption here is that MockHw is responsible for supplying current speed as well
 * as maintaining a speed as requested by SetSpeed(). It does not expect its user to
 * implement any close loop using GetSpeed() and SetSpeed() to maintain a driving mode.
 * By default, MockHw is in Mock::Default mode. When SetSpeed() is used, it switches
 * to Mock::Cruise. This is internal detail however.
 */
enum class DriveMode {
    Default = 0,
    Cruise = 1,
};

class MockHwImpl {
   public:
    MockHwImpl();

    ~MockHwImpl();

    int GetSpeed(uint8_t& speed_kmh);

    int SetSpeed(uint8_t speed_kmh);

    void UnsetSpeed();

   private:
    uint8_t GetRandomSpeed();

    // arbitrary lower and upper bounds
    static constexpr uint8_t MOCKHW_MIN_SPEED = 0;
    static constexpr uint8_t MOCKHW_MAX_SPEED = 160;

    DriveMode mode_ = DriveMode::Default;
    uint8_t current_speed_ = 0;  // only applicable when mode = Mode::Cruise
};

}  // namespace mock_hw
}  // namespace scout
