#include <Arduino.h>
#include <pins_arduino.h>
// #include <WiFiManager.h>
#include <WiFiManager.h>
#include <ESP8266HTTPClient.h>

#include "flame_sensor.h"
#include "transceiver.h"

#define FLAME_SENSOR_PIN D1
#define TRANSMITTER_PIN D3
#define RECEIVER_PIN D8
#define PACKET_LENGTH 32

WiFiManager wifi_manager;
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

void notifyOfIncident()
{
    if (flame_sensor->isDetectingFire()) {
        short incident_number = random(9999);
        char incident_characters[5];
        sprintf(incident_characters, "%4d", incident_number);
        String incident_code = String(incident_characters);
    }
}

void setup()
{
    Serial.begin(115200);

    // Connect to WiFi
    wifi_manager.setConfigPortalTimeout(180);
    wifi_manager.autoConnect();
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    
    flame_sensor = new FlameSensor(FLAME_SENSOR_PIN);
    // radio = new MeshNetwork::Transceiver(RECEIVER_PIN, TRANSMITTER_PIN, PACKET_LENGTH);
    // if (!radio->initialiseRadio()) Serial.println("Radio failed to initialise");
    
    // attachInterrupt(digitalPinToInterrupt(D1), notifyOfFire, FALLING);
}

void loop()
{
    // uint8_t receipt_buffer[PACKET_LENGTH];
    // uint8_t buffer_length = sizeof(receipt_buffer);
    // if (radio->receiveData(receipt_buffer)) {
    //     Serial.print("Received: ");
    //     Serial.println((char*)receipt_buffer);
    // }
    Serial.print(flame_sensor->isDetectingFire());
    delay(1000);
}