#include "EventDrawRoom.h"
#include "Room.h"
#include <iostream>

const int EventDrawRoom::PRIORITY = 1000;

EventDrawRoom::EventDrawRoom(Room* room, int time) : Event(time, PRIORITY, "Draw Room"), room(room) {}
EventDrawRoom::~EventDrawRoom() {}

void EventDrawRoom::process() {
    std::cout << room->toString();
    execution = "Drew room.";
}