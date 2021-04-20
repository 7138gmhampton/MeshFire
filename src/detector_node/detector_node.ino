#include <Arduino.h>
#include <pins_arduino.h>
// #include <WiFiManager.h>
#include <WiFiManager.h>
#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>
#include "EBYTE.h"

// #define FREQUENCY_868

// #include <LoRa_E32.h>

#include "flame_sensor.h"
// #include "transceiver.h"
#include "radio.h"

#define FLAME_SENSOR_PIN D1
#define TRANSMITTER_PIN D3
#define RECEIVER_PIN D8
#define PACKET_LENGTH 32

// #define FREQUENCY_868

WiFiManager wifi_manager;
FlameSensor* flame_sensor;
// MeshNetwork::Transceiver* radio;
// LoRa_E32 lora_transceiver(D2, D3);
// SoftwareSerial lora_serial(14, 12);
// EBYTE lora_transceiver(&lora_serial, 13, 15, 3);
MeshNetwork::Radio* radio; 

volatile bool notifying = false;
volatile bool dummy_send = false;

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
    // ResponseStatus response_status = lora_transceiver.sendMessage("Check...1...2...");
    // Serial.println("Button press message:");
    // Serial.println(response_status.getResponseDescription());
    dummy_send = true;
}

void setup()
{
    Serial.begin(115200);
    Serial.print("Serial logging - Check\n\r");

    // Connect to WiFi
    // wifi_manager.setConfigPortalTimeout(180);
    // WiFi.macAddress()
    // wifi_manager.setHostname()
    // wifi_manager.autoConnect();
    // Serial.print("IP Address: ");
    // Serial.println(WiFi.localIP());
    
    // flame_sensor = new FlameSensor(FLAME_SENSOR_PIN);
    
    // attachInterrupt(digitalPinToInterrupt(FLAME_SENSOR_PIN), fireDetect, FALLING);

    // lora_transceiver.begin();

    // ResponseStructContainer config_container = lora_transceiver.getConfiguration();
    // Configuration lora_config = *(Configuration*)config_container.data;
    // Serial.print("Channel - ");
    // Serial.println(lora_config.getChannelDescription());
    // // lora_config.CHAN = FREQUENCY_868;
    // lora_config.CHAN = 0x06;
    // Serial.print("Channel Set - ");
    // Serial.println(lora_config.getChannelDescription());
    // lora_transceiver.setConfiguration(lora_config);
    // int dummy = OPERATING_FREQUENCY;

    // ResponseStatus response_status = lora_transceiver.sendMessage("Hello, World?");
    // Serial.println(response_status.getResponseDescription());
    // pinMode(D7, INPUT_PULLUP);
    // attachInterrupt(digitalPinToInterrupt(D7), sendDummyRadio, FALLING);

    // lora_serial.begin(9600);
    // char this_dummy[11] = WiFi.hostname().toCharArray();
    // lora_transceiver.init();
    // lora_transceiver.PrintParameters();
    // lora_transceiver.
    // lora_serial.write("Check...1...2...\n\r");

    radio = new MeshNetwork::Radio(D5, D6, D7, D8, D9);
    radio->displayParameters();
}

void loop()
{
    // if (notifying) notifyOfIncident();
    
    // Serial.print(flame_sensor->isDetectingFire());
    // delay(1000);

    // Serial.println(digitalRead(D7));

    // if (dummy_send) {
    //     ResponseStatus response_status = lora_transceiver.sendMessage("Check...1...2...");
    //     Serial.println("Button press message:");
    //     Serial.println(response_status.getResponseDescription());
    //     dummy_send = false;
    // }

    // if (lora_transceiver.available() > 1) {
    //     ResponseContainer response_container = lora_transceiver.receiveMessage();
    //     if (response_container.status.code != 1) 
    //         Serial.println(response_container.status.getResponseDescription());
    //     else Serial.println(response_container.data);
    // }

    // delay(250);

    if (dummy_send) {
        // char message_buffer[11];
        // WiFi.macAddress().toCharArray(message_buffer, 11);
        // lora_serial.write(message_buffer);
        // Serial.write(message_buffer);
        // lora_serial.write("Check...1...2...\n\r");
        Serial.write("Send message\n\r");
        dummy_send = false;
    }

    // if (lora_serial.available()) {
    //     Serial.write("Message received - ");
    //     Serial.write(lora_serial.read());
    //     Serial.write("\n\r");
    // }
    // Serial.println("Check this");
    delay(250);
}