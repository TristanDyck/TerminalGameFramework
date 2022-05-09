#pragma once
#include <string>
#include <vector>
class Team;
class Component;

class Entity {
public:
    Entity(std::string name, Team*);
    Entity(std::string name, Team*, char);
    Entity(std::string name, Team*, int x, int y, char);
    Entity(const Entity&);
    virtual Entity* copy();
    virtual ~Entity();

    std::string toString();
    void changeSymbol(char newSymbol);
    Team* getTeam();
    void changeTeam(Team*);

    template<typename T> T* getComponent() {
        T *result = nullptr;
        for (int i = 0; i < components.size() && result == nullptr; i++) {
            if (dynamic_cast<T*>(components[i]) != nullptr)
                result = (T*)components[i];
        }
        return result;
    }
    
    void addComponent(Component*);

    void setPos(int x, int y);
    void movePos(int x, int y);
    int getX();
    int getY();

    void disable(); //disables the entity - will be soon deleted
    bool isDisabled();
private:
    char symbol;
    Team* team;
    std::string name;
    static int nextID;
    int id;

    int x, y;

    bool disabled; //if set to true, will be deleted and cleaned up next frame

    std::vector<Component*> components;
};