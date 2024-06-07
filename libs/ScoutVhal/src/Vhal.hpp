#pragma once

/*
 * This class defines abstraction for VHAL. An OEM must
 * implement its pure methods
 */
class Vhal {
   public:
    /*
     * See ScoutVhal#GetSpeed
     */
    virtual int GetSpeed(uint8_t &speed_kmh) = 0;

    /*
     * See ScoutVhal#GetHistoricSpeed
     */
    virtual int GetHistoricSpeed(uint64_t timestamp, uint8_t &speed_kmh) = 0;

    /*
     * See ScoutVhal#SetSpeed
     */
    virtual int SetSpeed(uint8_t speed_kmh) = 0;

    /*
     * See ScoutVhal#UnsetSpeed
     */
    virtual void UnsetSpeed() = 0;
};
