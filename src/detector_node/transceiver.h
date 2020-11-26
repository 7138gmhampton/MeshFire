#ifndef TRANSCEIVER_H
#define TRANSCEIVER_H

// #include <stdint.h>
#include <Arduino.h>
#include <RH_ASK.h>
#include <SPI.h>

namespace MeshNetwork
{
    class Transceiver
    {
        private:
            uint8_t receiver_pin;
            uint8_t transmitter_pin;
            char* buffer;
            RH_ASK radio;
        public:
            Transceiver(uint8_t receiver_pin, uint8_t transmitter_pin);
            void transmitData(const char* packet);
            char* readBuffer();
    };
}

#endif // TRANSCEIVER_H