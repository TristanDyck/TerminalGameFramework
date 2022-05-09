#pragma once
#include <string>
#include "Behaviour.h"

class Room;
class Entity;
class BehaviourAI: Behaviour {
public:
    BehaviourAI(Room*, TeamSet*);
    virtual ~BehaviourAI();

    //parameters: x and y values which should initially hold the
    //x/y location of the entity whose move is to be calculated.
    //They will be modified so that they are the value the entity
    //is to move by.  For example, if it is determined that the entity
    //should move up one, then they will be 0, -1
    //If there is a string to go along with the determined action, it will
    //be returned.
    virtual std::string getNextAction(int& x, int& y);
protected:
    //will use a pathfinding algorithm to find the next move position based on the
    //current room, the entity at x/y, and the desired position newX/newY.
    //the result will be stored in the modified newX, newY, which will be relative
    //to the current position.
    void findNextPath(int x, int y, int& newX, int& newY, Entity* target);
};