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
            uint8_t* buffer;
            RH_ASK radio;
            uint8_t packet_length;
        public:
            Transceiver(uint8_t receiver_pin, uint8_t transmitter_pin, uint8_t packet_length = 32);
            void transmitData(const char* packet);
            char* readBuffer();
    };
}

#endif // TRANSCEIVER_H