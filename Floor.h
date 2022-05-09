#pragma once
#include <iostream>

class Room;
class Floor {
public:
    Floor();
    Floor(int numRooms, int width, int height);
    virtual ~Floor();

    //returns false if it failed to add the room to that location
    virtual bool addRoom(Room*, int x, int y);
    int getWidth();
    int getHeight();
    int getNumRooms();
    //returns a string representation of this floor
    virtual std::string toString();
private:
    Room* root;
    int numRooms;
    Room*** floor; //2d array of pointers to this floor's rooms
    int width, height;
};