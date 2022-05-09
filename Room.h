#pragma once
#include <list>

class Floor;
class Entity;
class Room {
public:
    Room();
    Room(int width, int height);
    virtual ~Room();

    //adds the given entity a random location, returns false if it failed
    virtual bool addEntity(Entity*);
    //adds the given entity to the given location, returns false if it failed
    virtual bool addEntity(Entity*, int x, int y);
    //similar to addEntity, but it will search in a spiral pattern for a location to place
    //the given entity until it either finds a spot, or fails and returns false.
    virtual bool spawnEntity(Entity*, int x, int y);
    virtual void clearRoom();
    //will try to move the entity at the given location by the given amount
    //return false if move fails
    virtual bool moveEntity(int entityX, int entityY, int moveX, int moveY);
    //returns the entity at the given location, returns nullptr if it fails to find one
    //or if the position does not exist
    virtual Entity* getPos(int x, int y);
    //removes the entity at the given location from the room and returns it
    virtual Entity* removeEntity(int x, int y);
    //returns a string representation of this room
    virtual std::string toString();

    std::list<Entity*> getEntities();
protected:
    //for subclasses when calling this base class that wish to change
    //the default symbol used for an empty room spot
    Room(int width, int height, char DEFAULT_SYMBOL);
private:
    const char DEFAULT_SYMBOL;
    int width, height;
    Entity*** room; //2d array of the entities in this room
    std::list<Entity*> entities;
    bool validatePos(int x, int y);
};