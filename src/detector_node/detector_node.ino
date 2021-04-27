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

volatile bool sensor_blanked = false;
unsigned long blanking_start;

// ICACHE_RAM_ATTR void fireDetect();

// ICACHE_RAM_ATTR void reinitialiseSensor()
// {
//     // attachInterrupt(FLAME_SENSOR_PIN, fireDetect, FALLING);
//     sensor_blanked = false;
// }

ICACHE_RAM_ATTR void fireDetect()
{
    if ((millis() - blanking_start > 30000) && flame_sensor->isDetectingFire()) {
        event_log->addEvent(FlameSensor::generateEvent());
        // detachInterrupt(FLAME_SENSOR_PIN);
        // sensor_blanked = true;
        // timer1_attachInterrupt(reinitialiseSensor);
        // timer1_enable(TIM_DIV16, TIM_EDGE, TIM_SINGLE);
        // timer1_write(6000000);
        blanking_start = millis();
    }
}

ICACHE_RAM_ATTR void sendDummyRadio()
{
    event_log->addEvent(FlameSensor::generateEvent());
}

void setup()
{
    Serial.begin(BAUD_RATE);
    Serial.print("Serial logging - Check\n\r");

    web = new WifiPortal();
    event_log = new EventLog();
    radio = new MeshNetwork::Radio(RX_PIN, TX_PIN, M0_PIN, M1_PIN, AUX_PIN);
    radio->displayParameters();
    dispatcher = new Dispatcher(radio, web);
    flame_sensor =  new FlameSensor(FLAME_SENSOR_PIN);

    // pinMode(D1, INPUT_PULLUP);
    // attachInterrupt(digitalPinToInterrupt(D1), sendDummyRadio, FALLING);
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