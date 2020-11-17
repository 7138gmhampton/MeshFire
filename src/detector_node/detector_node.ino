#include <Arduino.h>
#include <HardwareSerial.h>
#include <pins_arduino.h>

#include "flame_sensor.h"

#define FLAME_SENSOR_PIN D1

FlameSensor flame_sensor;

void setup()
{
    Serial.begin(115200);
    flame_sensor = FlameSensor(FLAME_SENSOR_PIN);
}

void loop()
{
    if (flame_sensor.isDetectingFire()) Serial.println("Fire!");
    else Serial.println("All clear...");

    delay(1000);
}