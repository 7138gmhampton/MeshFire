#ifndef FLAME_SENSOR_H
#define FLAME_SENSOR_H

#include <Arduino.h>

class FlameSensor
{
    private:
        uint8_t pin;

    public:
        FlameSensor(uint8_t pin);
        bool isDetectingFire();
};

#endif // FLAME_SENSOR_H