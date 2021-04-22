#ifndef WIFI_PORTAL_H
#define WIFI_PORTAL_H

#include <Arduino.h>
#include <WiFiManager.h>

#include "common.h"

class WifiPortal
{
    private:
        bool active;
        WiFiManager manager;

    public:
        WifiPortal();

        // Accessors/Mutators

        bool isActive() const { return active; }
        
        // Other Methods

        void post(FireEvent event);
};

#endif // WIFI_PORTAL_H