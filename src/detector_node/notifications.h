#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

#include <deque>

#include "common.h"
#include "dispatcher.h"

using std::deque;

class Notifications
{
    private:
        deque<FireEvent> unprocessed_events;
        deque<FireEvent> recent_events;

        bool isInLog(FireEvent notification);

    public:
        Notifications();

        void addEvent(FireEvent event);
        /// If log exceeds 100 entries, this function will remove them until
        /// only 50 remain - beginning with the oldest
        void pruneLog();
        bool hasUnprocessed();
        void processNext(Dispatcher* dispatcher);
};

#endif // NOTIFICATIONS_H