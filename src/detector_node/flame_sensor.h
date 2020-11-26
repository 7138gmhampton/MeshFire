#ifndef FLAME_SENSOR_H
#define FLAME_SENSOR_H

#include <stdint.h>

class FlameSensor
{
    private:
        uint8_t pin;

    public:
        FlameSensor();
        FlameSensor(uint8_t pin);
        bool isDetectingFire();
};

#endif // FLAME_SENSOR_H