#include "ComponentAttack.h"
#include <stdlib.h>

const int ComponentAttack::DEFAULT_DAMAGE = 1;
const int ComponentAttack::DEFAULT_DELAY = 1;
const bool ComponentAttack::DEFAULT_CAN_ATTACK = true;

ComponentAttack::ComponentAttack() : ComponentAttack(DEFAULT_DAMAGE) {}
ComponentAttack::ComponentAttack(int damage) : ComponentAttack(damage, DEFAULT_DELAY) {}
ComponentAttack::ComponentAttack(int damage, int reloadDelay)
    : ComponentAttack(damage, reloadDelay, DEFAULT_CAN_ATTACK) {}
ComponentAttack::ComponentAttack(int damage, bool canAttack)
    : ComponentAttack(damage, DEFAULT_DELAY, canAttack) {}
ComponentAttack::ComponentAttack(int damage, int reloadDelay, bool canAttack)
    : Component(0), damage(damage), reloadDelay(reloadDelay), delayLeft(0), canAttack(canAttack) {}
ComponentAttack::ComponentAttack(const ComponentAttack& original) 
    : ComponentAttack(original.damage, original.reloadDelay, original.canAttack) {}
ComponentAttack::~ComponentAttack() {}

ComponentAttack* ComponentAttack::copy() {
    return new ComponentAttack(*this);
}

//can use -'ve damage for healing
int ComponentAttack::getDamage() {
    return damage;
}
void ComponentAttack::setDamage(int damage) {
    this->damage = damage;
}
int ComponentAttack::increaseDamage(int amount) {
    this->damage += amount;
    return this->damage;
}


void ComponentAttack::setReloadDelay(int delay) {
    delay = __max(delay, 0); //delay can't be negative
    this->reloadDelay = delay;
}
int ComponentAttack::getReloadDelay() {
    return reloadDelay;
}
//sets delayLeft to reloadDelay
int ComponentAttack::reload() {
    delayLeft = reloadDelay;
    return delayLeft;
}
// sets delayLeft to 0
void ComponentAttack::cancelDelay() {
    delayLeft = 0;
}
// returns delayLeft
int ComponentAttack::getDelay() {
    return delayLeft;
}
int ComponentAttack::advanceDelay() {
    return delayLeft > 0 ? --delayLeft : delayLeft;
}

bool ComponentAttack::attackReady() {
    return (canAttack && delayLeft <= 0);
}
void ComponentAttack::setCanAttack(bool canAttack) {
    this->canAttack = canAttack;
}