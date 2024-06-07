#pragma once

#include <cstdint>
#include <memory>

namespace scout {
namespace vhal {

class ScoutVhalImpl;

class ScoutVhal {
   public:
    /*
     * Construct ScoutVhal instance
     */
    ScoutVhal();

    /*
     * Destruct ScoutVhal instance
     */
    ~ScoutVhal();

    /*
     * Get current speed in kmh
     *
     * @param speed_kmh  Reference to store current speed
     * @returns 0 on success, negative errno otherwise
     */
    int GetSpeed(uint8_t& speed_kmh);

    /*
     * Get historic speed (in kmh) for a given timestamp
     * If exact timestamp cannot be matched then largest timestamp
     * smaller than requested one is retrieved
     *
     * @param timestamp  Timestamp to search for
     * @param speed_kmh  Reference to store current speed
     * @returns 0 on success, negative errno otherwise
     */
    int GetHistoricSpeed(uint64_t timestamp, uint8_t& speed_kmh);

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
    std::unique_ptr<ScoutVhalImpl> scout_vhal_impl_;
};

}  // namespace vhal
}  // namespace scout
