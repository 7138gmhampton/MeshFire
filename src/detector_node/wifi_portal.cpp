#include "wifi_portal.h"

WifiPortal::WifiPortal()
{
    pinMode(CLEAR_WIFI_PIN, INPUT_PULLUP);

    if (digitalRead(CLEAR_WIFI_PIN) == LOW) {
        manager.resetSettings();
        active = false;
    }
    else {
        manager.setConfigPortalTimeout(180);
        active = manager.autoConnect();
    }
}