#include <chrono>
#include <memory>
#include <vector>

#include <ScoutVhal.hpp>
#include "gtest/gtest.h"

using ScoutVhal = scout::vhal::ScoutVhal;

class ScoutVhalTest : public ::testing::Test {
   protected:
    virtual void SetUp() { ASSERT_NO_THROW(scout_vhal_ = std::make_unique<ScoutVhal>()); }

    std::unique_ptr<ScoutVhal> scout_vhal_;
    uint8_t initial_speed_ = 45;
};

TEST_F(ScoutVhalTest, GetSpeedDefault) {
    // Get speed and test it returns an arbitrary value
    uint8_t speed_kmh{};
    int rc = scout_vhal_->GetSpeed(speed_kmh);
    EXPECT_EQ(rc, 0);
    EXPECT_LT(speed_kmh, 160);  // this is upper bound
}

TEST_F(ScoutVhalTest, SetSpeedCruise) {
    // Set speed to a value
    uint8_t speed_kmh = initial_speed_;
    int rc = scout_vhal_->SetSpeed(speed_kmh);
    EXPECT_EQ(rc, 0);

    // Make sure that repeated Get returns the same value
    for (int i = 0; i < 3; i++) {
        uint8_t new_speed_kmh = 0;
        rc = scout_vhal_->GetSpeed(new_speed_kmh);
        EXPECT_EQ(rc, 0);
        EXPECT_EQ(speed_kmh, new_speed_kmh);
    }
}

TEST_F(ScoutVhalTest, UnSetSpeedDefault) {
    // Set speed to a value
    uint8_t speed_kmh = initial_speed_ * 2;
    int rc = scout_vhal_->SetSpeed(speed_kmh);
    EXPECT_EQ(rc, 0);

    // Make sure that Get returns the same value
    uint8_t new_speed_kmh = 0;
    rc = scout_vhal_->GetSpeed(new_speed_kmh);
    EXPECT_EQ(rc, 0);
    EXPECT_EQ(speed_kmh, new_speed_kmh);

    // Unset the previously set speed
    scout_vhal_->UnsetSpeed();

    // Next Get should be unequal to previously set value
    // and should be less than upper bound
    new_speed_kmh = 0;
    rc = scout_vhal_->GetSpeed(new_speed_kmh);
    EXPECT_EQ(rc, 0);
    EXPECT_NE(new_speed_kmh, speed_kmh);
    EXPECT_LT(new_speed_kmh, 160);  // this is upper bound
}

TEST_F(ScoutVhalTest, GetHistoricSpeed) {
    // Get first historic speed and make sure it's as expected
    uint8_t speed_kmh = 0;
    int rc = scout_vhal_->GetHistoricSpeed(0, speed_kmh);
    EXPECT_EQ(rc, 0);
    EXPECT_EQ(speed_kmh, initial_speed_);

    // Set bunch of new speeds and get a speed for a timestamp
    // that's larger than the last timestamp in the index. Since
    // it doesn't exists, it should return the last entry
    auto now_us = []() -> uint64_t {
        using namespace std::chrono;
        return duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    };
    std::vector<uint8_t> speeds = {10, 20, 30};
    for (uint8_t speed : speeds) {
        int rc = scout_vhal_->SetSpeed(speed);
        EXPECT_EQ(rc, 0);
    }
    rc = scout_vhal_->GetHistoricSpeed(now_us(), speed_kmh);
    EXPECT_EQ(rc, 0);
    EXPECT_EQ(speed_kmh, speeds[speeds.size() - 1]);
}
