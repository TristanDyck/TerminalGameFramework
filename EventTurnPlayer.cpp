#include "EventTurnPlayer.h"
#include "BehaviourPlayer.h"
#include "Entity.h"
#include "EventMove.h"
const int EventTurnPlayer::PRIORITY = 50;

EventTurnPlayer::EventTurnPlayer(BehaviourPlayer* behaviourPlayer, Entity* player, std::string input, 
    Room* room, int time) 
    : Event(time, PRIORITY, "Player Turn"), behaviour(behaviourPlayer), player(player), input(input), 
    room(room) {}
EventTurnPlayer::~EventTurnPlayer() {}

void EventTurnPlayer::process() {
    behaviour->setInput(input);
    int x = player->getX(), y = player->getY();
    behaviour->getNextAction(x, y);

    if (x != 0 || y != 0)
        queueEvent(new EventMove(player, room, x, y, getTime()));
}