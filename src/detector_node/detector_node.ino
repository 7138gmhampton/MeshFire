#include <Arduino.h>
#include <HardwareSerial.h>
#include <pins_arduino.h>
// #include <flame_sensor.h>

#include "flame_sensor.h"
// #include "flame_sensor.h"

#define FLAME_SENSOR_PIN D1
// #define FLAME_SENSOR_ANALOGUE A0

// int message_count{0};
FlameSensor flame_sensor;

void setup()
{
    Serial.begin(115200);
    // int message_count{0};
    // pinMode(FLAME_SENSOR, INPUT);
    flame_sensor = FlameSensor(FLAME_SENSOR_PIN);
    // if (flame_sensor.isDetectingFire()) Serial.println("Fire!");
}

void loop()
{
    // Serial.print("This is message number ");
    // ++message_count;
    // Serial.println(message_count);
    
    // delay(2000);
    // if (digitalRead(FLAME_SENSOR) == HIGH) {
    //     Serial.println("Fire detected!");
    // }
    // int digital_reading{digitalRead(FLAME_SENSOR)};
    // int analog_reading{analogRead(A0)};

    // Serial.print("Fire digital read - ");
    // Serial.println(digitalRead(FLAME_SENSOR));
    // Serial.print("Analogue signal - ");
    // Serial.println(analog_reading);

    if (flame_sensor.isDetectingFire()) Serial.println("Fire!");
    else Serial.println("All clear...");
    // flame_sensor.testPrint();

    delay(1000);
}