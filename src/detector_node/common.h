#ifndef COMMON_H
#define COMMON_H

#include <Arduino.h>
#include <pins_arduino.h>

#define FLAME_SENSOR_PIN D1
#define RX_PIN D5
#define TX_PIN D6
#define M0_PIN D7
#define M1_PIN D8
#define AUX_PIN D9

#define RADIO_BAUD 9600
#define MCU_BAUD 115200

typedef struct FireEvent
{
    char identifier[5];

    bool operator==(const FireEvent& other) const { return strcmp(identifier, other.identifier) == 0; }
};

#endif // COMMON_H