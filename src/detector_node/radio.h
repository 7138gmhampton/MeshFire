#ifndef RADIO_H
#define RADIO_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "EBYTE.h"

#include "common.h"

/// Represents the LoRa transceivers that the nodes use to communicate
/// node-to-node
class Radio
{
    private:
        SoftwareSerial* transceiver_serial;
        EBYTE* transceiver;
    
    public:
        Radio(uint8_t rx_pin, uint8_t tx_pin, uint8_t m0_pin, uint8_t m1_pin, uint8_t aux_pin);

        void transmit(FireIncident event);
        bool hasWaiting();
        FireIncident getNextMessage();
        void displayParameters();
};

#endif // RADIO_H