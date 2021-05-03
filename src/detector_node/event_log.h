#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

#include <deque>

#include "common.h"
#include "dispatcher.h"

using std::deque;

class EventLog
{
    private:
        deque<FireIncident> unprocessed_events;
        deque<FireIncident> recent_events;

        bool isInLog(FireIncident notification);

    public:
        EventLog();

        void addEvent(FireIncident event);
        /// If log exceeds 100 entries, this function will remove them until
        /// only 50 remain - beginning with the oldest
        void pruneLog();
        bool hasUnprocessed();
        void processNext(Dispatcher* dispatcher);
};

#endif // NOTIFICATIONS_H