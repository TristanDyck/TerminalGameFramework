#include "Floor.h"
#include "Room.h"
#include <stdlib.h>

//default constructor
Floor::Floor() : Floor::Floor(1, 1, 1) {}

//numRooms, width, height
Floor::Floor(int rooms, int w, int h) : numRooms(rooms), width(w), height(h) {
    floor = (Room***)malloc(width * sizeof(Room**));
    for(int i = 0; i < width; i++) {
        floor[i] = (Room**)malloc(height * sizeof(Room*));
    }

    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            floor[i][j] = nullptr;
        }
    }
}

Floor::~Floor() {
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            if(floor[i][j] != nullptr) 
                delete floor[i][j];
        }
        free(floor[i]);
    }
    free(floor);
}  

bool Floor::addRoom(Room* room, int x, int y) {
    bool added = false;
    if(0 <= x && x < width && 0 <= y && y < height && floor[x][y] == nullptr) {
        floor[x][y] = room;
        added = true;
        if(root == nullptr) 
            root = room;
        numRooms++;
    }
    return added;
}

std::string Floor::toString() {
    std::string result = "";
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            if(floor[i][j] == nullptr) {
                result += "X";
            } else {
                result += "Y";
            }
        }
        result += "\n";
    }
    return result;
}

int Floor::getNumRooms() {
    return numRooms;
}

int Floor::getWidth() {
    return width;
}

int Floor::getHeight() {
    return height;
}