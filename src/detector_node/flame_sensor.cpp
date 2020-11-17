#include <Arduino.h>

#include "flame_sensor.h"

FlameSensor::FlameSensor() { }

FlameSensor::FlameSensor(uint8_t pin)
{
    pin_ = pin;

    pinMode(pin_, INPUT);
}

bool FlameSensor::isDetectingFire()
{
    bool response = digitalRead(pin_) == LOW;
    return response;
}