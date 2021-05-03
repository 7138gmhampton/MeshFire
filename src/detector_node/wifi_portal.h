#ifndef WIFI_PORTAL_H
#define WIFI_PORTAL_H

#include <Arduino.h>
#include <WiFiManager.h>
#include <ESP8266HTTPClient.h>

#include "common.h"

/// Represents the connection to the internet and the server via the on-board
/// WiFi chip
class WifiPortal
{
    private:
        bool active;
        WiFiManager manager;

    public:
        WifiPortal();

        bool isActive() const { return active; }
        
        void post(FireIncident event);
};

#endif // WIFI_PORTAL_H