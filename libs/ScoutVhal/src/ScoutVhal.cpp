#include <cstdint>
#include <memory>

#include "ScoutVhal.hpp"
#include "ScoutVhalImpl.hpp"

namespace scout {
namespace vhal {

ScoutVhal::ScoutVhal() { scout_vhal_impl_ = std::make_unique<ScoutVhalImpl>(); }

ScoutVhal::~ScoutVhal() {}

int ScoutVhal::GetSpeed(uint8_t& speed_kmh) { return scout_vhal_impl_->GetSpeed(speed_kmh); }

int ScoutVhal::SetSpeed(uint8_t speed_kmh) { return scout_vhal_impl_->SetSpeed(speed_kmh); }

int ScoutVhal::GetHistoricSpeed(uint64_t timestamp, uint8_t& speed_kmh) {
    return scout_vhal_impl_->GetHistoricSpeed(timestamp, speed_kmh);
}

void ScoutVhal::UnsetSpeed() { scout_vhal_impl_->UnsetSpeed(); }

}  // namespace vhal
}  // namespace scout
