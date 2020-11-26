#ifndef TRANSCEIVER_H
#define TRANSCEIVER_H

// #include <stdint.h>
#include <Arduino.h>
#include <RH_ASK.h>
#include <SPI.h>

namespace MeshNetwork
{
    /// Represents the RF interlink that the nodes use to communicate over the mesh network directly
    class Transceiver
    {
        private:
            uint8_t receiver_pin;
            uint8_t transmitter_pin;
            uint8_t* buffer;
            RH_ASK radio;
            uint8_t packet_length;
        public:
            Transceiver(uint8_t receiver_pin, uint8_t transmitter_pin, uint8_t packet_length);
            void transmitData(const char* packet);
            bool receiveData(uint8_t* packet);
            bool initialiseRadio();
    };
}

#endif // TRANSCEIVER_H