#ifndef COMMON_H
#define COMMON_H

#include <Arduino.h>
#include <pins_arduino.h>

#define FLAME_SENSOR_PIN D1
#define RX_PIN D7
#define TX_PIN D8
#define M0_PIN D5
#define M1_PIN D6
#define AUX_PIN D9
#define CLEAR_WIFI_PIN D2

#define BAUD_RATE 9600
#define BLANKING_PERIOD_S 30000

typedef struct FireEvent
{
    char identifier[8];
    char source_mac_address[18];

    bool operator==(const FireEvent& other) const { return strcmp(identifier, other.identifier) == 0; }
};

#endif // COMMON_H