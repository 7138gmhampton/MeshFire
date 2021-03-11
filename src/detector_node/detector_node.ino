#include <Arduino.h>
#include <pins_arduino.h>
// #include <WiFiManager.h>
#include <WiFiManager.h>
#include <ESP8266HTTPClient.h>
#include <LoRa_E32.h>

#include "flame_sensor.h"
#include "transceiver.h"

#define FLAME_SENSOR_PIN D1
#define TRANSMITTER_PIN D3
#define RECEIVER_PIN D8
#define PACKET_LENGTH 32

WiFiManager wifi_manager;
FlameSensor* flame_sensor;
MeshNetwork::Transceiver* radio;
LoRa_E32 lora_transceiver(D2, D3);

volatile bool notifying = false;

void notifyOfIncident()
{
    if (flame_sensor->isDetectingFire()) {
        short incident_number = random(9999);
        char incident_characters[5];
        sprintf(incident_characters, "%4d", incident_number);
        String incident_code = String(incident_characters);

        HTTPClient http;
        http.begin("http://139.59.173.54/mesh-fire/scripts/server/append-incident.php?incident=" + incident_code);

        http.GET();

        http.end();
    }

    notifying = false;
}

ICACHE_RAM_ATTR void fireDetect()
{
    if (flame_sensor->isDetectingFire()) notifying = true;
}

ICACHE_RAM_ATTR void sendDummyRadio()
{
    ResponseStatus response_status = lora_transceiver.sendMessage("Check...1...2...");
    Serial.println("Button press message:");
    Serial.println(response_status.getResponseDescription());
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
    
    attachInterrupt(digitalPinToInterrupt(FLAME_SENSOR_PIN), fireDetect, FALLING);

    lora_transceiver.begin();
    ResponseStatus response_status = lora_transceiver.sendMessage("Hello, World?");
    Serial.println(response_status.getResponseDescription());
    attachInterrupt(digitalPinToInterrupt(D7), sendDummyRadio, RISING);
}

void loop()
{
    // if (notifying) notifyOfIncident();
    
    // Serial.print(flame_sensor->isDetectingFire());
    // delay(1000);

    if (lora_transceiver.available() > 1) {
        ResponseContainer response_container = lora_transceiver.receiveMessage();
        if (response_container.status.code != 1) 
            Serial.println(response_container.status.getResponseDescription());
        else Serial.println(response_container.data);
    }

    delay(250);
}