#pragma once

#include <cstdint>

namespace scout {
namespace mock_hw {

enum class Mode {
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

    Mode mode_ = Mode::Default;
    uint8_t current_speed_ = 0;  // only applicable when mode = Mode::Cruise
};

}  // namespace mock_hw
}  // namespace scout
