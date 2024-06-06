#pragma once

#include <cstdint>
#include <memory>

class MockHwImpl;

class MockHw {
   public:
    explicit MockHw();

    ~MockHw();

    int GetSpeed();

    int SetSpeed(uint8_t speed_kmh);

   private:
    std::unique_ptr<MockHwImpl> mock_hw_impl_;
};
