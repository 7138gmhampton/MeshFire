#include "event_log.h"

IncidentLog::IncidentLog() { }

bool IncidentLog::isInLog(FireIncident event)
{
    for (auto it = recent_events.cbegin(); it != recent_events.cend(); ++it) 
        if (event == *it) return true;

    return false;
}

void IncidentLog::addEvent(FireIncident event)
{
    if (!isInLog(event)) unprocessed_events.push_back(event);
}

bool IncidentLog::hasUnprocessed() { return unprocessed_events.size() > 0; }

void IncidentLog::processNext(Dispatcher* dispatcher)
{
    FireIncident next_event = unprocessed_events.front();

    dispatcher->dispatch(next_event);

    unprocessed_events.pop_front();
    recent_events.push_back(next_event);
}