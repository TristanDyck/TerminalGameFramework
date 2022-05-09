#include "Room.h"
#include "Entity.h"
#include <string>
#include <iostream>

Room::Room() : Room::Room(1, 1) {}

Room::Room(int width, int height) : Room::Room(width, height, 'X') {}

Room::Room(int width, int height, char symbol) : DEFAULT_SYMBOL(symbol), width(width), height(height) {
    room = (Entity***)malloc(sizeof(Entity**) * width);

    for(int i = 0; i < width; i++) {
        room[i] = (Entity**)malloc(sizeof(Entity*) * height);
    }

    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            room[i][j] = nullptr;
        }
    }
}

Room::~Room() {
    entities.clear();
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            if(room[i][j] != nullptr) {
                delete room[i][j];
            }
        }
        free(room[i]);
    }
    free(room);
}

//will choose a random position, if the entity cannot be added there,
//will move through the 2d array until it finds a valid location to place it 
bool Room::addEntity(Entity* entity) {
    bool added = false;

    int tries = 0;
    //choose random positions
    int x = rand() % width;
    int y = rand() % height;
    while(added == false && tries < width*height) {
        added = addEntity(entity, x, y);
        x = (x+1)%width;
        if(x == 0) 
            y = (y+1)%height;
        tries++;
    } 
    return added;
}

bool Room::addEntity(Entity* entity, int x, int y) {
    bool added = false;

        if(validatePos(x, y) && room[x][y] == nullptr) {
            room[x][y] = entity;
            entity->setPos(x, y);
            entities.push_front(entity);
            added = true;
        }
    return added;
}

bool Room::spawnEntity(Entity* entity, int x, int y) {
    bool added = false;

    if(entities.size() < width*height) {
        int direction = 0; //0 is right, 1 is down, 2 is left and 3 is up
        //try to add to the original location
        added = addEntity(entity, x, y);
        //invalid location, keep trying in a spiral pattern
        int spiralSize = 1;
        while(added == false) {
            for(int i = 0; i < spiralSize && !added; i++) {
                added = addEntity(entity, x, y);
                switch (direction) {
                case 0: //right
                    x++;
                    break;
                case 1: //down
                    y++;
                    break;
                case 2: //left
                    x--;
                    break;
                case 3: //up
                    y--;
                }
            }
            direction = (direction + 1) % 4;
            if(direction % 2 == 0) //every second direction change, increase spiral size 
                spiralSize++;
        }
    }

    return added;
}

//clear the room by deleting all of the entities it contains
void Room::clearRoom() {
    entities.clear();
    for(int i = 0; i < width; i ++) {
        for(int j = 0; j < height; j++) {
            if(room[i][j] != nullptr) {
                delete room[i][j];
                room[i][j] = nullptr;
            }
        }
    }
}

bool Room::moveEntity(int entityX, int entityY, int moveX, int moveY) {
    bool moved = false;
    if(validatePos(entityX, entityY) && room[entityX][entityY] != nullptr) {
        Entity* entity = room[entityX][entityY];
        int newX = entityX + moveX;
        int newY = entityY + moveY;
        if(validatePos(newX, newY) && room[newX][newY] == nullptr) {
            room[entityX][entityY] = nullptr;
            room[newX][newY] = entity;
            entity->setPos(newX, newY);
        }
    }
    
    return moved;
}

Entity* Room::removeEntity(int x, int y) {
    Entity* entity = nullptr;
    
    if(validatePos(x, y) && room[x][y] != nullptr) {
        entity = room[x][y];
        entities.remove(entity);
        room[x][y] = nullptr;
    }

    return entity;
}

Entity* Room::getPos(int x, int y) {
    Entity* entity = nullptr;
    if(validatePos(x, y))
        entity = room[x][y];
    return entity;
}

std::string Room::toString() {
    std::string result = "";
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            Entity* current = room[i][j];
            if(current != nullptr && current->isDisabled()) {
                entities.remove(current);
                delete current;
                room[i][j] = nullptr;
                current = nullptr;
            }
            if(current != nullptr)
                result += room[i][j]->toString();
            else
                result += DEFAULT_SYMBOL;
        }
        result += "\n";
    }
    return result;
}

bool Room::validatePos(int x, int y) {
    return (0 <= x && x < width && 0 <= y && y < height);
}

std::list<Entity*> Room::getEntities() {
    return entities;
}