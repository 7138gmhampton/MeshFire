#include "dispatcher.h"

Dispatcher::Dispatcher(MeshNetwork::Radio* radio, WifiPortal* web) 
{
    this->radio = radio;
    this->web = web;
}

void Dispatcher::dispatch(FireIncident event)
{
    if (web->isActive()) web->post(event);
    else radio->transmit(event);
}