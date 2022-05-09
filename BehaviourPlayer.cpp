#include "BehaviourPlayer.h"
#include <iostream>

BehaviourPlayer::BehaviourPlayer(Room* room, std::string input) : Behaviour(room, nullptr), input(input) {}
BehaviourPlayer::~BehaviourPlayer() {} 

std::string BehaviourPlayer::getNextAction(int& x, int& y) {
    y = 0;
    x = 0;
    if (input == "s")
        y = 1;
    else if (input == "w")
        y = -1;
    else if (input == "d")
        x = 1;
    else if (input == "a")
        x = -1;
    
    return input;
}

void BehaviourPlayer::setInput(std::string newInput) {
    input = newInput;
}