#include "MockHw.hpp"
#include "MockHwImpl.hpp"

using namespace std;

MockHw::MockHw() { mock_hw_impl_ = make_unique<MockHwImpl>(); }

MockHw::~MockHw() {}

int MockHw::GetSpeed() { return mock_hw_impl_->GetSpeed(); }

int MockHw::SetSpeed(uint8_t speed_kmh) { return mock_hw_impl_->SetSpeed(speed_kmh); }