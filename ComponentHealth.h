#pragma once
#include "Component.h"

class ComponentHealth : public Component {
public:
    ComponentHealth();
    ComponentHealth(int maxHealth);
    ComponentHealth(int maxHealth, int health);
    ComponentHealth(const ComponentHealth&);
    virtual ComponentHealth* copy() override;
    ~ComponentHealth();

    int getMaxHitPoints();
    int increaseMaxHitPoints(int);
    void toFullHealth();

    int getHitPoints();
    int dealDamage(int);
    //true when health is 0
    bool isDead();

    void makeImmune(bool);
    bool isImmune();
private:
    int maxHealth, health;
    bool immune;

    const static int DEFAULT_HEALTH;
    const static bool DEFAULT_IMMUNE;
};