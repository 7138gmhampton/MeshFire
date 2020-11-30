#ifndef FLAME_SENSOR_H
#define FLAME_SENSOR_H

#include <Arduino.h>

/// Represents YGS1006 based breakout board for sensing flames using infrared
class FlameSensor
{
    private:
        uint8_t pin;

    public:
        FlameSensor(uint8_t pin);
        bool isDetectingFire();
};

#endif // FLAME_SENSOR_H