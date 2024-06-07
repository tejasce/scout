#include <stdlib.h>

#include "MockHwImpl.hpp"

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
    if (mode_ == Mode::Default) {
        speed_kmh = GetRandomSpeed();
    } else {
        speed_kmh = current_speed_;
    }
    return 0;
}

int MockHwImpl::SetSpeed(uint8_t speed_kmh) {
    mode_ = Mode::Cruise;
    current_speed_ = speed_kmh;
    return 0;
}

void MockHwImpl::UnsetSpeed() { mode_ = Mode::Default; }

uint8_t MockHwImpl::GetRandomSpeed() {
    uint8_t rand_speed = 0;
    do {
        rand_speed = static_cast<uint8_t>(rand() & 0xff);
    } while (rand_speed == 0 || rand_speed > 160);  // arbitrary lower and upper bounds

    return rand_speed;
}
