#pragma once
#include "Event.h"

class Entity;
class EventDie : public Event {
public:
    EventDie(Entity* entity, int time);
    virtual ~EventDie() override;

    virtual void process() override;
private:
    Entity* entity;

    const static int PRIORITY;
};