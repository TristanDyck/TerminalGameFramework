#include "ComponentMove.h"
#include <stdlib.h>

const int ComponentMove::DEFAULT_SPEED = 1;
const bool ComponentMove::DEFAULT_FROZEN = false;

ComponentMove::ComponentMove() : ComponentMove(DEFAULT_SPEED) {}
ComponentMove::ComponentMove(int moveSpeed) : ComponentMove(DEFAULT_SPEED, DEFAULT_FROZEN) {}
ComponentMove::ComponentMove(int moveSpeed, bool frozen) : Component(3), moveSpeed(moveSpeed), frozen(frozen) {}
ComponentMove::ComponentMove(const ComponentMove& original) 
    : ComponentMove(original.moveSpeed, original.frozen) {}
ComponentMove::~ComponentMove() {}

ComponentMove* ComponentMove::copy() {
    return new ComponentMove(*this);
}

int ComponentMove::getMoveSpeed() {
    return frozen ? 0 : moveSpeed;
}
int ComponentMove::increaseMoveSpeed(int amount) {
    moveSpeed += amount;
    moveSpeed = __max(0, moveSpeed);
    return moveSpeed;
}

void ComponentMove::freeze(bool frozen) {
    this->frozen = frozen;
}
