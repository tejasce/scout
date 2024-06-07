#pragma once

#include <cstdint>
#include <memory>

namespace scout {
namespace mock_hw {

class MockHwImpl;

class MockHw {
   public:
    /*
     * Construct a MockHw object
     */
    MockHw();

    /*
     * Destruct a MockHw object
     */
    ~MockHw();

    /*
     * Get current speed in kmh (always between 0 and 160)
     *
     * @param speed_kmh  Reference to store current speed
     * @returns 0 on success, negative errno otherwise
     */
    int GetSpeed(uint8_t &speed_kmh);

    /*
     * Set speed in kmh (must be between 0 and 160)
     *
     * @param speed_kmh  Speed in kmh to set to
     * @returns 0 on success, negative errno otherwise
     */
    int SetSpeed(uint8_t speed_kmh);

    /*
     * Unset previously set speed (no-op if no speed was set previously)
     */
    void UnsetSpeed();

   private:
    std::unique_ptr<MockHwImpl> mock_hw_impl_;
};

}  // namespace mock_hw
}  // namespace scout
