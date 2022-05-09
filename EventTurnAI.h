#pragma once
#include "Event.h"

class Room;
class BehaviourAI;
class Entity;
class EventTurnAI : public Event {
public:
    EventTurnAI(BehaviourAI* behaviourPlayer, Entity* entity, Room* room, int time);
    virtual ~EventTurnAI() override;

    virtual void process() override;
private:
    BehaviourAI* behaviour; 
    Entity* entity;
    Room* room;

    const static int PRIORITY;
};