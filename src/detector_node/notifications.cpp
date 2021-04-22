#include <SoftwareSerial.h>

#include "radio.h"
#include "notifications.h"

Notifications::Notifications() { }

bool Notifications::isInLog(FireEvent notification)
{
    for (auto it = recent_events.cbegin(); it != recent_events.cend(); ++it) 
        if (notification == *it) return true;

    return false;
}

void Notifications::addEvent(FireEvent event)
{
    if (!isInLog(event)) unprocessed_events.push_back(event);
}

bool Notifications::hasUnprocessed() { return unprocessed_events.size() > 0; }

void Notifications::processNext(Dispatcher* dispatcher)
{
    FireEvent next_event = unprocessed_events.front();

    dispatcher->dispatch(next_event);
    Serial.println(next_event.identifier);

    unprocessed_events.pop_front();
    recent_events.push_back(next_event);
}