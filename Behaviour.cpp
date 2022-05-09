#include "Behaviour.h"


Behaviour::Behaviour(Room* room, TeamSet* tS) : currentRoom(room), teams(tS) {}
Behaviour::~Behaviour() {}

Room* Behaviour::getRoom() {
    return currentRoom;
}

void Behaviour::setRoom(Room* newRoom) {
    currentRoom = newRoom;
}

TeamSet* Behaviour::getTeams() {
    return teams;
}