#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <SoftwareSerial.h>

#include "common.h"
#include "radio.h"

/// Handles the dispatching of events that are new to that node - to either
/// the web portal or to the LoRa interlinks
class Dispatcher
{
    private:
        MeshNetwork::Radio* radio;
    
    public:
        Dispatcher(MeshNetwork::Radio* radio);

        void dispatch(FireEvent event);
};

#endif // DISPATCHER_H