#include <Arduino.h>
#include <WiFiManager.h>
#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>
#include "EBYTE.h"

#include "flame_sensor.h"
#include "radio.h"
#include "event_log.h"
#include "wifi_portal.h"

FlameSensor* flame_sensor;
MeshNetwork::Radio* radio; 
EventLog* event_log;
Dispatcher* dispatcher;
WifiPortal* web;

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
}

ICACHE_RAM_ATTR void fireDetect()
{
    if (flame_sensor->isDetectingFire()) event_log->addEvent(FlameSensor::generateEvent());
}

ICACHE_RAM_ATTR void sendDummyRadio()
{
    event_log->addEvent(FlameSensor::generateEvent());
}

void setup()
{
    Serial.begin(MCU_BAUD);
    Serial.print("Serial logging - Check\n\r");

    web = new WifiPortal();
    event_log = new EventLog();
    radio = new MeshNetwork::Radio(RX_PIN, TX_PIN, M0_PIN, M1_PIN, AUX_PIN);
    radio->displayParameters();
    dispatcher = new Dispatcher(radio);

    pinMode(D1, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(D1), sendDummyRadio, FALLING);
}

void loop()
{
    while (radio->hasWaiting()) {
        FireEvent received = radio->getNextMessage();
        event_log->addEvent(received);
    }

    while (event_log->hasUnprocessed()) event_log->processNext(dispatcher);

    delay(250);
}