#include <Arduino.h>
#include <RadioHead.h>
#include <HardwareSerial.h>
#include <pins_arduino.h>
#include <RH_ASK.h>
#include <SPI.h>

#include "flame_sensor.h"

#define FLAME_SENSOR_PIN D1
#define TRANSMITTER_PIN D3
#define RECEIVER_PIN D8

FlameSensor flame_sensor;
RH_ASK radio(2000, RECEIVER_PIN, TRANSMITTER_PIN);

void setup()
{
    Serial.begin(115200);
    flame_sensor = FlameSensor(FLAME_SENSOR_PIN);
    // if (!driver)
    if (!radio.init()) Serial.println("Radio failed to initialise");
}

void loop()
{
    if (flame_sensor.isDetectingFire()) Serial.println("Fire!");
    else Serial.println("All clear...");

    Serial.print("Max msg length for this driver ");
    Serial.println(radio.maxMessageLength());

    delay(1000);
}