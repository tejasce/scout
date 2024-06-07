#include "MockHw.hpp"
#include "MockHwImpl.hpp"

namespace scout {
namespace mock_hw {

using namespace std;

MockHw::MockHw() { mock_hw_impl_ = make_unique<MockHwImpl>(); }

MockHw::~MockHw() {}

int MockHw::GetSpeed(uint8_t &speed_kmh) { return mock_hw_impl_->GetSpeed(speed_kmh); }

int MockHw::SetSpeed(uint8_t speed_kmh) { return mock_hw_impl_->SetSpeed(speed_kmh); }

void MockHw::UnsetSpeed() { mock_hw_impl_->UnsetSpeed(); }

}  // namespace mock_hw
}  // namespace scout
