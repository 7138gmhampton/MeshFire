#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

#include <queue>
#include <deque>

#include "common.h"

using std::queue;
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
        void processNext(MeshNetwork::Radio* dispatcher);
};

#endif // NOTIFICATIONS_H