#pragma once
#include "Event.h"

class Room;
class EventDrawRoom : public Event {
public:
    EventDrawRoom(Room*, int time);
    virtual ~EventDrawRoom() override;

    virtual void process() override;
private:
    Room* room; 

    const static int PRIORITY;
};