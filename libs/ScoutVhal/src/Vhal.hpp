#pragma once

class Vhal {
   public:
    virtual int GetSpeed(uint8_t &speed_kmh) = 0;

    virtual int GetHistoricSpeed(uint64_t timestamp, uint8_t &speed_kmh) = 0;

    virtual int SetSpeed(uint8_t speed_kmh) = 0;
};
