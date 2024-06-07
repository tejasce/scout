#pragma once

#include <nlohmann/json.hpp>

#include "MockHw.hpp"
#include "TimestampIndex.hpp"
#include "Vhal.hpp"

namespace scout {

class ScoutVhalImpl : public Vhal {
   public:
    ScoutVhalImpl();

    ~ScoutVhalImpl();

    int GetSpeed(uint8_t &speed_kmh) override;

    int GetHistoricSpeed(uint64_t timestamp, uint8_t &speed_kmh) override;

    int SetSpeed(uint8_t speed_kmh) override;

   private:
    uint64_t now_seconds() {
        using namespace std;
        // use monotonic (vs system_clock which can be adjusted and hence may not be suitable for measuring intervals)
        return chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now().time_since_epoch()).count();
    }

    // For MockHw interface
    MockHw mock_hw_{};

    // For book-keeping
    nlohmann::json cc_json_{};
    TimestampIndex ts_idx_{};
    uint32_t entry_count_ = 0;
};

}  // namespace scout
