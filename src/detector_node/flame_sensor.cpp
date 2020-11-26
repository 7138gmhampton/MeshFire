#include <Arduino.h>

#include "flame_sensor.h"

FlameSensor::FlameSensor() { }

FlameSensor::FlameSensor(uint8_t pin)
{
    this->pin = pin;

    pinMode(pin, INPUT);
}

bool FlameSensor::isDetectingFire()
{
    bool response = digitalRead(pin) == LOW;
    return response;
}