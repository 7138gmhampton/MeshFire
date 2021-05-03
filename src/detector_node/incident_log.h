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

    public:
        IncidentLog();

        void addEvent(FireIncident event);
        /// If log exceeds 100 entries, this function will remove them until
        /// only 50 remain - beginning with the oldest
        void pruneLog();
        bool hasUnprocessed();
        void processNext(Dispatcher* dispatcher);
};

#endif // NOTIFICATIONS_H