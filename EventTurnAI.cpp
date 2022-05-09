#include "EventTurnAI.h"
#include "BehaviourAI.h"
#include "Entity.h"
#include "EventMove.h"
const int EventTurnAI::PRIORITY = 55; //after player turn

EventTurnAI::EventTurnAI(BehaviourAI *behaviourAI, Entity *entity, Room *room, int time) 
    : Event(time, PRIORITY, "Turn AI"), behaviour(behaviourAI), entity(entity), room(room) {}
EventTurnAI::~EventTurnAI() {}

void EventTurnAI::process() {

    int entityX = entity->getX();
    int entityY = entity->getY();
    behaviour->getNextAction(entityX, entityY);
    if (entityX != 0 || entityY != 0)
        queueEvent(new EventMove(entity, room, entityX, entityY, getTime()));
}
