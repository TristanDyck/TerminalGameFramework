#pragma once
#include <string>
#include "Behaviour.h"

class Room;
class BehaviourPlayer : Behaviour {
public:
    BehaviourPlayer(Room*, std::string input);
    virtual ~BehaviourPlayer();

    //parameters: x and y values which should initially hold the
    //x/y location of the entity whose move is to be calculated.
    //They will be modified so that they are the value the entity
    //is to move by.  For example, if it is determined that the entity
    //should move up one, then they will be 0, -1
    //If there is a string to go along with the determined action, it will
    //be returned.
    virtual std::string getNextAction(int& x, int& y);
    void setInput(std::string newInput);
private:
    std::string input;
};