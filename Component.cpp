#include "Component.h"

Component::Component(int COMPONENT_ID) : COMPONENT_ID(COMPONENT_ID) {}
Component::Component(const Component& original) : Component(original.COMPONENT_ID) {}

Component::~Component() {}

int Component::getID() {
    return COMPONENT_ID;
}
