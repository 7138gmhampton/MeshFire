#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

#include <deque>

#include "common.h"
#include "dispatcher.h"

using std::deque;

/// This log maintains two queues - the first with new entries from the sensors
/// or received from the radio interlinks; the second has a list of the last 50 
/// that were handled by this unit
class IncidentLog
{
    private:
        deque<FireIncident> unprocessed_events;
        deque<FireIncident> recent_events;

        bool isInLog(FireIncident notification);
        void pruneOldestFromLog();

    public:
        IncidentLog();

        bool hasUnprocessed() { return unprocessed_events.size() > 0; };
        void addEvent(FireIncident event);
        void processNext(Dispatcher* dispatcher);
};

#endif // NOTIFICATIONS_H