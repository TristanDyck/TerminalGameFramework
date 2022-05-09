#include "EventReload.h"
#include "ComponentAttack.h"
#include <stdlib.h>

const int EventReload::PRIORITY = 100; //very low priority (should happen at the end of the turn)

EventReload::EventReload(ComponentAttack *attack, int time) 
    : Event(time, PRIORITY, "Reload"), attack(attack) {}
EventReload::~EventReload() {}

void EventReload::process() {
    if(attack != nullptr) {
        attack->advanceDelay();
        if(attack->getDelay() > 0) {
            queueEvent(new EventReload(attack, getTime() + 1));
            execution = "Advanced reload of " + std::to_string(attack->getID()) + ".  Scheduled new "
                + "reload event.";
        } else {
            execution = "Completed reload of " + std::to_string(attack->getID()) + ".";
        }
    } else {
        execution = "Could not reload a nullptr attack.";
    }
}

ComponentAttack *attack;
