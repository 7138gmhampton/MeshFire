
#include "transceiver.h"

using namespace MeshNetwork;

Transceiver::Transceiver(uint8_t receiver_pin, uint8_t transmitter_pin, uint8_t packet_length = 32)
{
    this->receiver_pin = receiver_pin;
    this->transmitter_pin = transmitter_pin;
    this->packet_length = packet_length;

    this->radio = RH_ASK(2000, receiver_pin, transmitter_pin);
}

void Transceiver::transmitData(const char* packet) 
{ 
    radio.send((uint8_t*)packet, packet_length);
    radio.waitPacketSent();
}

char* Transceiver::readBuffer() 
{ 
    radio.recv(buffer, &packet_length);

    return (char*)buffer;
}

bool Transceiver::initialiseRadio() { return radio.init(); }