#pragma once

#include <cstdint>
#include <memory>

namespace scout {

class ScoutVhalImpl;

class ScoutVhal {
   public:
    ScoutVhal();

    ~ScoutVhal();

    int GetSpeed(uint8_t& speed_kmh);

    int GetHistoricSpeed(uint64_t timestamp, uint8_t& speed_kmh);

    int SetSpeed(uint8_t speed_kmh);

    void UnsetSpeed();

   private:
    std::unique_ptr<ScoutVhalImpl> scout_vhal_impl_;
};

}  // namespace scout
