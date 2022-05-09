#include "Entity.h"
#include "Team.h"
#include "Component.h"
#include <string>
#include <iostream>
int Entity::nextID = 0; 

Entity::Entity(std::string name, Team* team) : Entity(name, team, 'E') {}
Entity::Entity(std::string name, Team* team, char symbol) 
    : Entity(name, team, 0, 0, symbol) {}
Entity::Entity(std::string name, Team* team, int x, int y, char symbol) 
    : symbol(symbol), team(team), name(name), id(nextID++), x(x), y(y), disabled(false) {}
Entity::Entity(const Entity& original) : Entity(original.name, original.team, original.symbol) {
    for(int i = 0; i < original.components.size(); i++) {
        components.push_back(original.components[i]->copy());
    }
}

Entity* Entity::copy() {
    return new Entity(*this);
}

Entity::~Entity() {
    for(int i = 0; i < components.size(); i++) 
        delete components[i];
}



std::string Entity::toString() {
    std::string result = "";
    return result + symbol;
}

void Entity::changeSymbol(char newSymbol) {
    symbol = newSymbol;
}

Team* Entity::getTeam() {
    return team;
}

void Entity::changeTeam(Team* team) {
    if(team != nullptr) {
        this->team = team;
    }
}

void Entity::addComponent(Component* component) {
    components.push_back(component);
}

void Entity::setPos(int x, int y) {
    this->x = x;
    this->y = y;
}
void Entity::movePos(int x, int y) {
    this->x += x;
    this->y += y;
}

int Entity::getX() {
    return x;
}
int Entity::getY() {
    return y;
}

 //disables the entity - will be soon deleted (when drawing the room)
void Entity::disable() {
    disabled = true;
}
bool Entity::isDisabled() {
    return disabled;
}