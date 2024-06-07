#pragma once

#include <chrono>
#include <nlohmann/json.hpp>
#include <string>

#include "MockHw.hpp"
#include "TimestampIndex.hpp"
#include "Vhal.hpp"

namespace scout {
namespace vhal {

/*
 * This class implements VHAL interface for Scout
 */
class ScoutVhalImpl : public Vhal {
   public:
    ScoutVhalImpl();

    ~ScoutVhalImpl();

    int GetSpeed(uint8_t &speed_kmh) override;

    int GetHistoricSpeed(uint64_t timestamp, uint8_t &speed_kmh) override;

    int SetSpeed(uint8_t speed_kmh) override;

    void UnsetSpeed() override;

   private:
    uint64_t now_seconds() {
        using namespace std;
        // using system_clock with assumption that it is steady and doesn't jitter or fluctuate too much
        // after this library is loaded
        return chrono::duration_cast<chrono::seconds>(chrono::system_clock::now().time_since_epoch()).count();
    }

    // Assumption: Save the history of cruise control till the system
    // is restarted in order to limit the size of the history
    const std::string CC_JSON_FILE = "/tmp/cruise_control_history.json";

    // For MockHw interface
    mock_hw::MockHw mock_hw_{};

    // For book-keeping
    nlohmann::json cc_json_{};
    TimestampIndex ts_idx_{};
    uint32_t entry_count_ = 0;
};

}  // namespace vhal
}  // namespace scout
