#include <Arduino.h>

#include "flame_sensor.h"
#include "radio.h"
#include "event_log.h"
#include "wifi_portal.h"

FlameSensor* flame_sensor;
MeshNetwork::Radio* radio; 
EventLog* event_log;
Dispatcher* dispatcher;
WifiPortal* web;

unsigned long blanking_start;

ICACHE_RAM_ATTR void fireDetect()
{
    if ((millis() - blanking_start > BLANKING_PERIOD_MS) && flame_sensor->isDetectingFire()) {
        event_log->addEvent(FlameSensor::generateEvent());
        blanking_start = millis();
    }
}

void setup()
{
    Serial.begin(BAUD_RATE);

    web = new WifiPortal();
    event_log = new EventLog();
    radio = new MeshNetwork::Radio(RX_PIN, TX_PIN, M0_PIN, M1_PIN, AUX_PIN);
    radio->displayParameters();
    dispatcher = new Dispatcher(radio, web);
    flame_sensor =  new FlameSensor(FLAME_SENSOR_PIN);

    attachInterrupt(digitalPinToInterrupt(FLAME_SENSOR_PIN), fireDetect, FALLING);
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