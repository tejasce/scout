#pragma once

#include <chrono>
#include <vector>

#include <errno.h>

namespace scout {

class TimestampIndex {
   public:
    void Set(uint64_t timestamp, uint8_t speed_kmh) { ts_index_.push_back({timestamp, speed_kmh}); }

    int Get(uint64_t timestamp, uint8_t& speed_kmh) {
        if (ts_index_.empty()) {
            return -ENODATA;  // no data
        } else if (timestamp == 0) {
            speed_kmh = ts_index_[0].second;  // first entry
            return 0;
        }

        auto it = upper_bound(ts_index_.begin(), ts_index_.end(), timestamp, comp_pair());
        int idx = static_cast<int>(it - ts_index_.begin() - 1);
        if (idx >= 0 && idx < static_cast<int>(ts_index_.size())) {
            speed_kmh = ts_index_[idx].second;
            return 0;
        }
        return 0;
    }

    std::vector<std::pair<uint64_t, uint8_t>> GetIndex() { return ts_index_; }

   private:
    struct comp_pair {
        bool operator()(const uint64_t& a, const std::pair<uint64_t, uint8_t>& b) { return a < b.first; }
    };
    std::vector<std::pair<uint64_t, uint8_t>> ts_index_;  // timestamp to speed mapping
};

}  // namespace scout
