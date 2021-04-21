#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

#include <queue>

#include "common.h"

using std::queue;

class Notifications
{
    private:
        queue<FireEvent> unprocessed_events;
        queue<FireEvent> recent_events;

    public:
        Notifications();

        void addEvent(FireEvent event);
        /// If log exceeds 100 entries, this function will remove them until
        /// only 50 remain - beginning with the oldest
        void pruneLog();
        bool hasUnprocessed();
        void processNext();
};

#endif // NOTIFICATIONS_H