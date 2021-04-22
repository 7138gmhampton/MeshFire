#include "flame_sensor.h"

FlameSensor::FlameSensor(uint8_t pin)
{
    this->pin = pin;

    pinMode(pin, INPUT);
}

bool FlameSensor::isDetectingFire() { return digitalRead(pin) == LOW; }

FireEvent FlameSensor::generateEvent()
{
    short event_number = random(9999);
    FireEvent event;

    sprintf(event.identifier, "%4d", event_number);

    return event;
}