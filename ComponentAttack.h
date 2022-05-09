#pragma once
#include "Component.h"

class ComponentAttack : public Component {
public:
    ComponentAttack();
    ComponentAttack(int damage);
    ComponentAttack(int damage, int reloadDelay);
    ComponentAttack(int damage, bool canAttack);
    ComponentAttack(int damage, int reloadDelay, bool canAttack);
    ComponentAttack(const ComponentAttack&);
    virtual ComponentAttack* copy() override;
    ~ComponentAttack();

    int getDamage();
    void setDamage(int);
    int increaseDamage(int);

    void setReloadDelay(int);
    int getReloadDelay();
    int reload();
    //sets delayLeft to 0
    void cancelDelay();
    //returns delayLeft
    int getDelay();
    //decrements delayLeft
    int advanceDelay();

    bool attackReady();
    void setCanAttack(bool);
private:
    int damage;

    //rounds between attacks
    int reloadDelay;
    int delayLeft; //decrement with operator--
    bool canAttack;

    const static int DEFAULT_DAMAGE;
    const static int DEFAULT_DELAY;
    const static bool DEFAULT_CAN_ATTACK;
};