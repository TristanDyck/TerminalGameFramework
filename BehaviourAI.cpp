#include "BehaviourAI.h"
#include "Room.h"
#include "TeamSet.h"
#include "Team.h"
#include "ComponentConfidence.h"
#include "Entity.h"
#include <list>
#include <stdlib.h>
#include <iostream>

BehaviourAI::BehaviourAI(Room* room, TeamSet* teams) : Behaviour(room, teams) {}
BehaviourAI::~BehaviourAI() {} 

std::string BehaviourAI::getNextAction(int& x, int& y) {
    std::string action = "No move";
    Entity* entity = getRoom()->getPos(x, y);
    ComponentConfidence* confidence = nullptr;

    int currentX = 0, currentY = 0;

    if(entity != nullptr) 
        confidence = entity->getComponent<ComponentConfidence>();

    if(entity != nullptr && entity->getTeam() != nullptr && confidence != nullptr 
        && confidence->getBehaviour() > 0 ) {
        Team* team = entity->getTeam();
        std::list<Entity*> entities = getRoom()->getEntities();
        Entity* target = nullptr;
        int closest = INT16_MAX; //TODO: replace with a sight range, will work as is to find an entity anywhere


        //will find the closest enemy entity
        for(std::list<Entity*>::iterator current = entities.begin(); 
            current != entities.end(); current++) {
            //if the current entity is closer than the closest entity and an enemy, it is
            //the new closest enemy entity
            int distance = abs(x - (*current)->getX()) + abs(y - (*current)->getY());
            if(distance < closest && (*current)->getTeam() != nullptr
                && getTeams()->getRelations(team, (*current)->getTeam()) < 0) {
                closest = distance;
                target = *current;
            }
        }

        if(target != nullptr) {
            currentX = target->getX();
            currentY = target->getY();
            findNextPath(x, y, currentX, currentY, target);
            action = "Moved";
        }
    }

    x = currentX;
    y = currentY;

    return action;
}

//newX + newY will never be greater than 1 or less than -1 (that is, 
//it will never try to move more than one space at a time)
void BehaviourAI::findNextPath(int x, int y, int& newX, int& newY, Entity* target) {
    int moveX = newX - x;
    moveX = __min(moveX, 1);
    moveX = __max(moveX, -1);

    Entity* collide = getRoom()->getPos(x + moveX, y);
    if(moveX != 0 && collide != target && collide != nullptr) {
        moveX = 0;
    }

    int moveY = 0;
    if (moveX == 0) {
        moveY = newY - y;
        moveY = __min(moveY, 1);
        moveY = __max(moveY, -1);
    }

    collide = getRoom()->getPos(x, y + moveY);
    if(moveY != 0 && collide != target && collide != nullptr) { 
        moveY = 0;
    }

    newY = moveX;
    newX = moveY;
}
