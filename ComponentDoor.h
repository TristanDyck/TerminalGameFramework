#pragma once
#include "Component.h"

class Entity;
class ComponentDoor : public Component {
public:
    ComponentDoor(Entity* link);
    ComponentDoor(Entity* link, bool locked);
    ComponentDoor(const ComponentDoor&);
    virtual ComponentDoor* copy() override;
    ~ComponentDoor();

    void setLink(Entity* link);
    Entity* getLink();

    bool isLocked();
    bool lock(bool);
    bool lock();
private:
    Entity* link; //the entity this door leads to
    bool locked;

    const static bool DEFAULT_LOCKED;
};