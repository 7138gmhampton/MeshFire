#ifndef TRANSCEIVER_H
#define TRANSCEIVER_H

#include <Arduino.h>
#include <RadioHead.h>
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
            /// Returns true if transmission was received properly and copies it to the out parameter
            bool receiveData(uint8_t* packet);
            /// Returns true/false based on success of initialisation
            bool initialiseRadio();
    };
}

#endif // TRANSCEIVER_H