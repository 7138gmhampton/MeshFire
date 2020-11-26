
#include "transceiver.h"

using namespace MeshNetwork;

Transceiver::Transceiver(uint8_t receiver_pin, uint8_t transmitter_pin, uint8_t packet_length)
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

bool Transceiver::receiveData(uint8_t* packet) 
{ 
    bool attempt = radio.recv(buffer, &packet_length);

    if (attempt) {
        // strcpy(packet, (const char*) buffer);
        // *packet = *buffer;
        memcpy(buffer, packet, packet_length);
        return true;
    }
    // return (char*)buffer;
    else return false;
}

bool Transceiver::initialiseRadio() { return radio.init(); }