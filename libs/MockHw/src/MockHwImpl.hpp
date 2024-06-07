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

    int GetSpeed(uint8_t& speed_kmh);

    int SetSpeed(uint8_t speed_kmh);

    void UnsetSpeed();

   private:
    uint8_t GetRandomSpeed();

    Mode mode_ = Mode::Default;
    uint8_t current_speed_ = 0;  // only applicable when mode = Mode::Cruise
};
