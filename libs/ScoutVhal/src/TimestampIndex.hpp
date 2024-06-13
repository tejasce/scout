#pragma once

#include <vector>

#include <errno.h>

namespace scout {
namespace vhal {

class TimestampIndex {
   public:
    /*
     * Construct TimestampIndex instance
     */
    TimestampIndex() = default;

    /*
     * Destruct TimestampIndex instance
     */
    ~TimestampIndex() = default;

    /*
     * Store {timestamp, speedk_kmh} pair in the index
     *
     * @param timestamp  timestamp value
     * @param speed_kmh  Speed value
     */
    void Set(uint64_t timestamp, uint8_t speed_kmh) { ts_index_[timestamp] = speed_kmh; }

    /*
     * Retrive speedk_kmh for a given timestamp from the index
     * If the index is non-empty and if the exact timestamp cannot be matched
     * then retrieve the largest timestamp smaller than the requested on.
     * A special case of timestamp=0 is supported where it returns the first entry
     *
     * @param timestamp  timestamp value
     * @param speed_kmh  Refrence to store speed value
     * @return 0 on success, negative errno otherwise
     */
    int Get(uint64_t timestamp, uint8_t& speed_kmh) {
        if (ts_index_.empty()) {
            return -ENODATA;  // no data
        }

        auto it = upper_bound(ts_index_.begin(), ts_index_.end(), timestamp,
            [](const uint64_t& a, const std::pair<uint64_t, uint8_t>& b) { return a < b.first; });
        if (it != ts_index_.begin()) {
            it--;
        }
        speed_kmh = it->second;
        return 0;
    }

   private:
    // Since any new timestamp stored in the index is gonna be largest, a vector would suffice
    // with O(1) insert and O(n) for search. Map (with red-black tree) can improve on it with
    // O(logn) for both insert and search. With each timestamp being at microsecond granularity
    // going to be unique and map is viable option.
    // unordered_map isn't an option since it can't be iterated (needed to support retrieving
    // largest value smaller than requested timestamp if there's no exact match)
    std::map<uint64_t, uint8_t> ts_index_;  // timestamp to speed mapping
};

}  // namespace vhal
}  // namespace scout
