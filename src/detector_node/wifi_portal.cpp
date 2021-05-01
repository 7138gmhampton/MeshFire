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

void WifiPortal::post(FireEvent event)
{
    HTTPClient http;
    http.begin("http://139.59.173.54/mesh-fire/scripts/server/append-incident.php");
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    String event_code = String(event.identifier);
    String payload = "incident=" + event_code + "&mac_address=" + event.source_mac_address;

    int response = http.POST(payload);
    Serial.print("POST - ");
    Serial.println(response);
    http.end();
}