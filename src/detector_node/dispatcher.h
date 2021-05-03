#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <SoftwareSerial.h>

#include "common.h"
#include "radio.h"
#include "wifi_portal.h"

/// Handles the dispatching of events that are new to that node - to either
/// the web portal or to the LoRa interlinks
class Dispatcher
{
    private:
        Radio* radio;
        WifiPortal* web;
    
    public:
        Dispatcher(Radio* radio, WifiPortal* web);

        void dispatch(FireIncident event);
};

#endif // DISPATCHER_H