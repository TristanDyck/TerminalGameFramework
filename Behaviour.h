#pragma once
#include <string>

class Room;
class TeamSet;
class Behaviour {
public:
    Behaviour(Room*, TeamSet*);
    virtual ~Behaviour() = 0;

    //parameters: x and y values which should initially hold the
    //x/y location of the entity whose move is to be calculated.
    //They will be modified so that they are the value the entity
    //is to move by.  For example, if it is determined that the entity
    //should move up one, then they will be 0, -1
    //If there is a string to go along with the determined action, it will
    //be returned.
    virtual std::string getNextAction(int& x, int& y) = 0;

    Room* getRoom();
    void setRoom(Room*);

    TeamSet* getTeams();
private:

    Room* currentRoom;
    TeamSet* teams;

};