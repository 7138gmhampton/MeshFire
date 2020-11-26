#include <Arduino.h>
#include <pins_arduino.h>

#include "flame_sensor.h"
#include "transceiver.h"

#define FLAME_SENSOR_PIN D1
#define TRANSMITTER_PIN D3
#define RECEIVER_PIN D8
#define PACKET_LENGTH 32

FlameSensor* flame_sensor;
MeshNetwork::Transceiver* radio;

void notifyOfFire()
{
    if (flame_sensor->isDetectingFire()) {
        char message[PACKET_LENGTH];
        memset(message, 60, PACKET_LENGTH);

        radio->transmitData(message);
        Serial.println("Fire detected");
    }
}

void setup()
{
    Serial.begin(115200);
    
    flame_sensor = new FlameSensor(FLAME_SENSOR_PIN);
    radio = new MeshNetwork::Transceiver(RECEIVER_PIN, TRANSMITTER_PIN, PACKET_LENGTH);
    if (!radio->initialiseRadio()) Serial.println("Radio failed to initialise");
    
    attachInterrupt(digitalPinToInterrupt(D1), notifyOfFire, FALLING);
}

void loop()
{
    uint8_t receipt_buffer[PACKET_LENGTH];
    uint8_t buffer_length = sizeof(receipt_buffer);
    if (radio->receiveData(receipt_buffer)) {
        Serial.print("Received: ");
        Serial.println((char*)receipt_buffer);
    }
}