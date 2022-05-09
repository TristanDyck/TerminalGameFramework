#pragma once
#include <string>

class Team {
public:
    Team();
    Team(std::string, int, bool);
    ~Team();

    bool equals(Team*);

    bool sameTeam(Team*);
    int getID();
    std::string getName();
private:
    std::string name;
    int id;
    bool constantRelations; //set to true if relations cannot be altered
};