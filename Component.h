#pragma once

class Component {
public:
    Component(int COMPONENT_ID);
    Component(const Component&);
    virtual Component* copy() = 0;
    virtual ~Component() = 0;

    int getID();
private:
    const int COMPONENT_ID;
};