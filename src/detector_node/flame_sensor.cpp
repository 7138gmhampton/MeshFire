#include "flame_sensor.h"

FlameSensor::FlameSensor(uint8_t pin)
{
    this->pin = pin;

    pinMode(pin, INPUT);
}

bool FlameSensor::isDetectingFire() { return digitalRead(pin) == LOW; }