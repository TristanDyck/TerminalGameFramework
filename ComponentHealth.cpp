#include "ComponentHealth.h"
#include <stdlib.h>

const int ComponentHealth::DEFAULT_HEALTH = 5;
const bool ComponentHealth::DEFAULT_IMMUNE = false;

ComponentHealth::ComponentHealth() : ComponentHealth(DEFAULT_HEALTH) {}
ComponentHealth::ComponentHealth(int maxHealth) : ComponentHealth(maxHealth, maxHealth) {}
ComponentHealth::ComponentHealth(int maxHealth, int health) 
    : Component(2), maxHealth(maxHealth), health(health), immune(DEFAULT_IMMUNE) {}
ComponentHealth::ComponentHealth(const ComponentHealth& original) 
    : ComponentHealth(original.maxHealth, original.health) {}
ComponentHealth::~ComponentHealth() {}

ComponentHealth* ComponentHealth::copy() {
    return new ComponentHealth(*this);
}

int ComponentHealth::getMaxHitPoints() {
    return maxHealth;
}
int ComponentHealth::increaseMaxHitPoints(int amount) {
    maxHealth += amount;
    return maxHealth;
}
void ComponentHealth::toFullHealth() {
    health = maxHealth;
}

int ComponentHealth::getHitPoints() {
    return health;
}
int ComponentHealth::dealDamage(int amount) {
    int origHealth = health;
    health -= amount;
    health = __max(0, health);
    health = __min(maxHealth, health);
    return origHealth - health;
}
// true when health is 0 and not immune
bool ComponentHealth::isDead() {
    return (health == 0 && !immune);
}

void ComponentHealth::makeImmune(bool immune) {
    this->immune = immune;
}
bool ComponentHealth::isImmune() {
    return immune;
}