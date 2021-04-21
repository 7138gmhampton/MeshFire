#include "radio.h"

using namespace MeshNetwork;

Radio::Radio(uint8_t rx_pin, uint8_t tx_pin, uint8_t m0_pin, uint8_t m1_pin, uint8_t aux_pin)
{
    // this->transceiver_serial = SoftwareSerial(rx_pin, tx_pin);
    this->transceiver_serial = new SoftwareSerial(rx_pin, tx_pin);
    this->transceiver = new EBYTE(transceiver_serial, m0_pin, m1_pin, aux_pin);

    transceiver_serial->begin(9600);
    transceiver->init();
}

Radio::Radio(SoftwareSerial serial, EBYTE transceiver)
{
    this->transceiver_serial = &serial;
    this->transceiver = &transceiver;

    transceiver_serial->begin(9600);
    this->transceiver->init();
}

void Radio::displayParameters()
{
    transceiver->PrintParameters();
}

void Radio::transmitNotification(FireEvent notification)
{
    transceiver->SendStruct(&notification, sizeof(notification));
}