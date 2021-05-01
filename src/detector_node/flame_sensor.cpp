#include "flame_sensor.h"

FlameSensor::FlameSensor(uint8_t pin)
{
    this->pin = pin;

    pinMode(pin, INPUT);
}

bool FlameSensor::isDetectingFire() { return digitalRead(pin) == LOW; }

FireEvent FlameSensor::generateEvent()
{
    FireEvent event;

    generateRandomIdentifier().toCharArray(event.identifier, sizeof(event.identifier));
    WiFi.macAddress().toCharArray(event.source_mac_address, sizeof(event.source_mac_address));

    return event;
}

String FlameSensor::generateRandomIdentifier()
{
    const String base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    String identifier = "";

    while (identifier.length() < 7) {
        int random_number = random(64);
        identifier += base64[random_number];
    }

    return identifier;
}