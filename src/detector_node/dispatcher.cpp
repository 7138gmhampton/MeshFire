#include "dispatcher.h"

Dispatcher::Dispatcher(MeshNetwork::Radio* radio) 
{
    this->radio = radio;
}

void Dispatcher::dispatch(FireEvent event)
{
    radio->transmit(event);
}