#include <errno.h>
#include <stdlib.h>

#include "MockHwImpl.hpp"

namespace scout {
namespace mock_hw {

MockHwImpl::MockHwImpl() {
    // There would be a file level construct here that would
    // prevent multiple processes to instantiate MockHw object
    // simultaneously at run time. For example, a char device
    // that can be acquired/opened by only one process at a time
}

MockHwImpl::~MockHwImpl() {
    // Release/close the underlying device
}

int MockHwImpl::GetSpeed(uint8_t &speed_kmh) {
    if (mode_ == DriveMode::Default) {
        speed_kmh = GetRandomSpeed();
    } else {
        speed_kmh = current_speed_;
    }
    return 0;
}

int MockHwImpl::SetSpeed(uint8_t speed_kmh) {
    // Can't cruise control at > 160 kmh
    if (speed_kmh > MOCKHW_MAX_SPEED) {
        return -EINVAL;
    }
    mode_ = DriveMode::Cruise;
    current_speed_ = speed_kmh;
    return 0;
}

void MockHwImpl::UnsetSpeed() { mode_ = DriveMode::Default; }

uint8_t MockHwImpl::GetRandomSpeed() {
    uint8_t rand_speed = 0;
    do {
        rand_speed = static_cast<uint8_t>(rand() & 0xff);
    } while (rand_speed == MOCKHW_MIN_SPEED || rand_speed > MOCKHW_MAX_SPEED);

    return rand_speed;
}

}  // namespace mock_hw
}  // namespace scout
