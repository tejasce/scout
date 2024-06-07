#include <cassert>
#include <cstdint>
#include <fstream>
#include <string>

#include "ScoutVhalImpl.hpp"

namespace scout {
namespace vhal {

using namespace std;

/*
 * Example CC_JSON_FILE
 * {
 *  "entry0" : { "timestamp": <number>, "speed_kmh": <number> },
 *  "entry1" : { "timestamp": <number>, "speed_kmh": <number> },
 *  "entry2" : { "timestamp": <number>, "speed_kmh": <number> }
 * }
 */
ScoutVhalImpl::ScoutVhalImpl() {
    ifstream file(CC_JSON_FILE, ifstream::in);

    // If history exist, load it in memory for retrieval+update
    if (file.good()) {
        cc_json_ = nlohmann::json::parse(file);
        for (;; entry_count_++) {
            string entry = "entry" + to_string(entry_count_);
            if (!cc_json_.contains(entry)) {
                break;
            }
            uint64_t timestamp = cc_json_[entry]["timestamp"];
            uint8_t speed_kmh = cc_json_[entry]["speed_kmh"];
            ts_idx_.Set(timestamp, speed_kmh);
        }
    }
}

ScoutVhalImpl::~ScoutVhalImpl() {
    // Update the data on the disk upon exit
    ofstream file(CC_JSON_FILE, ofstream::out);
    file << cc_json_.dump();
}

int ScoutVhalImpl::GetSpeed(uint8_t &speed_kmh) {
    int rc = mock_hw_.GetSpeed(speed_kmh);
    if (rc != 0) {
        return rc;
    }

    return 0;
}

int ScoutVhalImpl::GetHistoricSpeed(uint64_t timestamp, uint8_t &speed_kmh) {
    return ts_idx_.Get(timestamp, speed_kmh);
}

int ScoutVhalImpl::SetSpeed(uint8_t speed_kmh) {
    int rc = mock_hw_.SetSpeed(speed_kmh);
    if (rc != 0) {
        return rc;
    }

    string entry = "entry" + to_string(entry_count_++);
    uint64_t timestamp = now_seconds();
    cc_json_[entry]["timestamp"] = timestamp;
    cc_json_[entry]["speed_kmh"] = speed_kmh;
    ts_idx_.Set(timestamp, speed_kmh);
    return 0;
}

void ScoutVhalImpl::UnsetSpeed() { mock_hw_.UnsetSpeed(); }

}  // namespace vhal
}  // namespace scout
