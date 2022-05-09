#pragma once
#include "Event.h"

class Room;
class BehaviourPlayer;
class Entity;
class EventTurnPlayer : public Event {
public:
    EventTurnPlayer(BehaviourPlayer* behaviourPlayer, Entity* player, std::string input, Room* room, int time);
    virtual ~EventTurnPlayer() override;

    virtual void process() override;
private:
    BehaviourPlayer* behaviour; 
    Entity* player;
    std::string input;
    Room* room;

    const static int PRIORITY;
};