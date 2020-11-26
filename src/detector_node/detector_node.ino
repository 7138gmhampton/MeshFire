#include <Arduino.h>
#include <RadioHead.h>
#include <HardwareSerial.h>
#include <pins_arduino.h>
#include <RH_ASK.h>
#include <SPI.h>

#include "flame_sensor.h"
#include "transceiver.h"

#define FLAME_SENSOR_PIN D1
#define TRANSMITTER_PIN D3
#define RECEIVER_PIN D8
#define PACKET_LENGTH 32

FlameSensor* flame_sensor;
// RH_ASK radio(2000, RECEIVER_PIN, TRANSMITTER_PIN);
// const char *notification = "Fire detected!";
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
    // if (!driver)
    // if (!radio.init()) Serial.println("Radio failed to initialise");
    radio = new MeshNetwork::Transceiver(RECEIVER_PIN, TRANSMITTER_PIN, PACKET_LENGTH);
    if (!radio->initialiseRadio()) Serial.println("Radio failed to initialise");
    
    attachInterrupt(digitalPinToInterrupt(D1), notifyOfFire, FALLING);
}

void loop()
{
    // if (flame_sensor.isDetectingFire()) {
    //     Serial.println("Fire!");
    //     // const char *notification = "Fire detected!";
    //     bool success = radio.send((uint8_t*)notification, strlen(notification));
    //     radio.waitPacketSent();
    //     const char* user_notification = success ? "Transmitted" : "Not transmitted";
    //     Serial.println(user_notification);
    // }
    // else Serial.println("All clear...");

    // bool success = radio.send((uint8_t*)notification, strlen(notification));
    // radio.waitPacketSent();
    // Serial.println(success);

    // uint8_t buffer[strlen(notification)];
    // uint8_t buffer_length = sizeof(buffer);
    // if (radio.recv(buffer, &buffer_length)) {
    //     Serial.print("Received: ");
    //     Serial.println((char*)buffer);
    // }

    // Serial.print("Max msg length for this driver ");
    // Serial.println(radio.maxMessageLength());

    // Serial.println(analogRead(A0));

    // delay(500);

    // uint8_t receipt_buffer[PACKET_LENGTH];
    // uint8_t buffer_length = sizeof(receipt_buffer);
    // if (radio.recv(receipt_buffer, &buffer_length)) {

    // }
    uint8_t receipt_buffer[PACKET_LENGTH];
    uint8_t buffer_length = sizeof(receipt_buffer);
    if (radio->receiveData(receipt_buffer)) {
        Serial.print("Received: ");
        Serial.println((char*)receipt_buffer);
    }
}