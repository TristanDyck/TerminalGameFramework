#pragma once
#include "Component.h"

class ComponentMove : public Component {
public:
    ComponentMove();
    ComponentMove(int moveSpeed);
    ComponentMove(int moveSpeed, bool frozen);
    ComponentMove(const ComponentMove&);
    virtual ComponentMove* copy() override;
    ~ComponentMove();

    int getMoveSpeed();
    int increaseMoveSpeed(int);
    void freeze(bool);
private:
    int moveSpeed;
    bool frozen;

    const static int DEFAULT_SPEED;
    const static bool DEFAULT_FROZEN;
};