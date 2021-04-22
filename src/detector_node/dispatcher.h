#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <SoftwareSerial.h>

#include "common.h"
#include "radio.h"

class Dispatcher
{
    private:
        MeshNetwork::Radio* radio;
    
    public:
        Dispatcher(MeshNetwork::Radio* radio);

        void dispatch(FireEvent event);
};

#endif // DISPATCHER_H