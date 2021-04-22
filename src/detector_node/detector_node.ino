#include <Arduino.h>
#include <WiFiManager.h>
#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>
#include "EBYTE.h"

#include "flame_sensor.h"
#include "radio.h"
#include "notifications.h"

WiFiManager wifi_manager;
FlameSensor* flame_sensor;
MeshNetwork::Radio* radio; 
Notifications* event_log;

volatile bool notifying = false;
volatile bool dummy_send = false;
FireEvent* waiting_message = nullptr;

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
    if (flame_sensor->isDetectingFire()) event_log->addEvent(FlameSensor::generateEvent());
}

ICACHE_RAM_ATTR void sendDummyRadio()
{
    // waiting_message = new FireEvent();
    // strcpy(waiting_message->identifier, "1234");
    // FireEvent* dummy_event;
    // *dummy_event = {.identifier = "1234"};
    // FireEvent dummy_event = {.identifier = "1234"};
    // event_log->addEvent(dummy_event);
    event_log->addEvent(FlameSensor::generateEvent());
}

void setup()
{
    Serial.begin(MCU_BAUD);
    Serial.print("Serial logging - Check\n\r");
    String mac = WiFi.macAddress();
    Serial.println(mac);

    event_log = new Notifications();

    radio = new MeshNetwork::Radio(RX_PIN, TX_PIN, M0_PIN, M1_PIN, AUX_PIN);
    radio->displayParameters();

    pinMode(D1, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(D1), sendDummyRadio, FALLING);
}

void loop()
{
    // if (waiting_message != nullptr) {
    //     radio->transmit(*waiting_message);
    //     waiting_message = nullptr;
    // }

    while (radio->hasWaiting()) {
        FireEvent display_message = radio->getNextMessage();
        Serial.println(display_message.identifier);
    }

    while (event_log->hasUnprocessed())
        event_log->processNext(radio);

    delay(250);
}