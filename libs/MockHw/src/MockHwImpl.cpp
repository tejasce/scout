#include "MockHwImpl.hpp"

MockHwImpl::MockHwImpl() {
    // There would be a file level construct here that would
    // prevent multiple processes to instantiate MockHw object
    // at run time. For example, a char device that can be
    // acquired/opened by only one process at a time
}

MockHwImpl::~MockHwImpl() {
    // Release/close the underlying device
}

int MockHwImpl::GetSpeed() { return 0; }

int MockHwImpl::SetSpeed(uint8_t speed_kmh [[maybe_unused]]) { return 0; }
