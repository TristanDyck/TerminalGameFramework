#pragma once
#include "Event.h"

class Room;
class Entity;
class EventMove : public Event {
public:
    EventMove(Entity*, Room*, int x, int y, int time);
    virtual ~EventMove() override;

    virtual void process() override;
private:
    Entity* entity;
    Room* entityRoom;
    int x, y; 

    const static int PRIORITY;
};