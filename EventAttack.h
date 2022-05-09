#pragma once
#include "Event.h"

class Entity;
class EventAttack : public Event {
public:
    EventAttack(Entity* attacker, Entity* attacked, int time);
    virtual ~EventAttack() override;

    virtual void process() override;
private:
    Entity* attacker; 
    Entity* attacked;

    const static int PRIORITY;
};