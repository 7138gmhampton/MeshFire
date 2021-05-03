#include <Arduino.h>

#include "flame_sensor.h"
#include "radio.h"
#include "incident_log.h"
#include "wifi_portal.h"

FlameSensor* flame_sensor;
Radio* radio; 
IncidentLog* incident_log;
Dispatcher* dispatcher;
WifiPortal* web;

unsigned long blanking_start;

ICACHE_RAM_ATTR void fireDetect()
{
    if ((millis() - blanking_start > BLANKING_PERIOD_MS) && flame_sensor->isDetectingFire()) {
        incident_log->addEvent(FlameSensor::generateEvent());
        blanking_start = millis();
    }
}

void setup()
{
    Serial.begin(BAUD_RATE);

    web = new WifiPortal();
    incident_log = new IncidentLog();
    radio = new Radio(RX_PIN, TX_PIN, M0_PIN, M1_PIN, AUX_PIN);
    dispatcher = new Dispatcher(radio, web);
    flame_sensor =  new FlameSensor(FLAME_SENSOR_PIN);

    attachInterrupt(digitalPinToInterrupt(FLAME_SENSOR_PIN), fireDetect, FALLING);
    blanking_start = millis() - BLANKING_PERIOD_MS;
}

void loop()
{
    while (radio->hasWaiting()) {
        FireIncident received = radio->getNextMessage();
        incident_log->addEvent(received);
    }

    while (incident_log->hasUnprocessed()) incident_log->processNext(dispatcher);

    delay(250);
}