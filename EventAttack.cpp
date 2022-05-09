#include "EventAttack.h"
#include "Entity.h"
#include "ComponentAttack.h"
#include "ComponentHealth.h"
#include "EventReload.h"
#include "EventDie.h"
#include <stdlib.h>
#include <iostream>

//attack should come very early
const int EventAttack::PRIORITY = 5; 

EventAttack::EventAttack(Entity* attacker, Entity* attacked, int time) 
    : Event(time, PRIORITY, "Attack"), attacker(attacker), attacked(attacked) {}

EventAttack::~EventAttack() { 
    attacker = nullptr; 
    attacked = nullptr;
}

void EventAttack::process() {
    ComponentAttack* attack = attacker->getComponent<ComponentAttack>();
    ComponentHealth* health = attacked->getComponent<ComponentHealth>();

    if(attack != nullptr && health != nullptr && attack->attackReady()) {
        int damage = health->dealDamage(attack->getDamage());
        execution = attacker->toString() + " dealt " + std::to_string(damage) + " damage to " 
            + attacked->toString();
        attack->reload();
        queueEvent(new EventReload(attack, getTime()));
        if(health->isDead())
            queueEvent(new EventDie(attacked, getTime()));
    } else {
        execution = "Attack failed.";
    }
}