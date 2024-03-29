#ifndef FLAME_SENSOR_H
#define FLAME_SENSOR_H

#include <Arduino.h>
#include <ESP8266WiFi.h>

#include "common.h"

/// Represents YGS1006 based breakout board for sensing flames using infrared
class FlameSensor
{
    private:
        uint8_t pin;

        static String generateRandomIdentifier();

    public:
        FlameSensor(uint8_t pin);
        
        bool isDetectingFire();
        static FireIncident generateEvent();
};

#endif // FLAME_SENSOR_H