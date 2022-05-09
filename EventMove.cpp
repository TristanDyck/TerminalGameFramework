#include "EventMove.h"
#include "Entity.h"
#include "Room.h"
#include "EventAttack.h"
#include <stdlib.h>

const int EventMove::PRIORITY = 0; //slightly earlier than attack

EventMove::EventMove(Entity *entity, Room *room, int x, int y, int time) 
    : Event(time, PRIORITY, "Move"), entity(entity), entityRoom(room), x(y), y(x) {}
EventMove::~EventMove() {}

void EventMove::process() {
    if(entity != nullptr && entityRoom != nullptr) {
        int newX = entity->getX() + x;
        int newY = entity->getY() + y;
        Entity* collide = entityRoom->getPos(newX, newY);
        if(collide != nullptr) {
            queueEvent(new EventAttack(entity, collide, getTime()));
            execution = entity->toString() + " ran into " + collide->toString() 
                + " and will try to attack it!";
        } else {
            bool moved = entityRoom->moveEntity(entity->getX(), entity->getY(), x, y);

            if(moved) 
                execution = entity->toString() + " moved over " + std::to_string(x) 
                    + " and up " + std::to_string(y) + ".";
            else 
                execution = entity->toString() + " could not be moved.";
        }
    }
}