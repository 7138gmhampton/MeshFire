#ifndef COMMON_H
#define COMMON_H

#include <pins_arduino.h>

#define FLAME_SENSOR_PIN D1
#define RX_PIN D5
#define TX_PIN D6
#define M0_PIN D7
#define M1_PIN D8
#define AUX_PIN D9

typedef struct FireEvent
{
    char identifier[5];
};

#endif // COMMON_H