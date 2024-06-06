#pragma once

#include <cstdint>

enum class Mode {
    Default = 0,
    Cruise = 1,
};

class MockHwImpl {
   public:
    MockHwImpl();

    ~MockHwImpl();

    int GetSpeed();

    int SetSpeed(uint8_t speed_kmh);

   private:
    Mode mode_ = Mode::Default;
    uint8_t current_speed_ = 0;
};
