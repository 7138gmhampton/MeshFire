
#include "transceiver.h"

using namespace MeshNetwork;

Transceiver::Transceiver(uint8_t receiver_pin, uint8_t transmitter_pin)
{
    this->receiver_pin = receiver_pin;
    this->transmitter_pin = transmitter_pin;

    this->radio = RH_ASK(2000, receiver_pin, transmitter_pin);
}