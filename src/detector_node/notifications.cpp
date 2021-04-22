#include "notifications.h"

Notifications::Notifications() { }

bool Notifications::isInLog(FireEvent notification)
{
    for (auto it = recent_events.cbegin(); it != recent_events.cend(); ++it) 
        if (notification == *it) return true;

    return false;
}