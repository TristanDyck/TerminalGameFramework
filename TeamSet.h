#pragma once
#include <string>

class Team;
class TeamSet {
public:
    TeamSet();
    TeamSet(int);
    ~TeamSet();

    Team* addTeam(std::string teamName, bool constantRelations);
    //foces two teams to the given relation, regardless of if the team has constant
    //relations - useful to initialize the relations between two teams
    void setRelations(Team* team1, Team* team2, int relation);
    //give a negative amount to decrease
    void increaseRelations(Team*, Team*, int amount);
    int getRelations(Team*, Team*);
    bool containsTeam(Team*);
    bool containsTeam(std::string name);
private:
    int fixRelation(int relation);
    bool updateTable(Team*, Team*, int newValue);
    //stores the relations between each team in this 2d array
    //the relations between teams a & b will be at [a.id][b.id] and [b.id][a.id]
    int** relations;
    Team** teams;
    const int MAX_TEAMS;
    int numTeams;

    const int MAX_RELATION;
};