#include "ComponentDoor.h"
#include "Entity.h"

const bool ComponentDoor::DEFAULT_LOCKED = false;

ComponentDoor::ComponentDoor(Entity* link) : ComponentDoor(link, DEFAULT_LOCKED) {}
ComponentDoor::ComponentDoor(Entity* link, bool locked) : Component(4), link(link), locked(locked) {}
ComponentDoor::ComponentDoor(const ComponentDoor& original) : ComponentDoor(original.link, original.locked) {}

ComponentDoor* ComponentDoor::copy() {
    return new ComponentDoor(*this);
}

ComponentDoor::~ComponentDoor() {}

void ComponentDoor::setLink(Entity* link) {
    this->link = link;
}
Entity* ComponentDoor::getLink() {
    return link;
}

bool ComponentDoor::isLocked() {
    return locked;
}
bool ComponentDoor::lock(bool locked) {
    this->locked = locked;
    return this->locked;
}
bool ComponentDoor::lock() {
    locked = !locked;
    return locked;
}