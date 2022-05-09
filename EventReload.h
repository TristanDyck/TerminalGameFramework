#pragma once
#include "Event.h"

class ComponentAttack;
class EventReload : public Event {
public:
    EventReload(ComponentAttack*, int time);
    virtual ~EventReload() override;

    virtual void process() override;
private:
    ComponentAttack* attack;
    
    const static int PRIORITY;
};