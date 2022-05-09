#include "EventDie.h"
#include "Entity.h"
#include <iostream>

const int EventDie::PRIORITY = -5; //if an entity dies, it should die before it attacks

EventDie::EventDie(Entity *entity, int time) : Event(time, PRIORITY, "Die"), entity(entity) {}
EventDie::~EventDie() {}

void EventDie::process() {
    entity->disable();
}
