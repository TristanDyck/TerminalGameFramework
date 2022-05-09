#include "TeamSet.h"
#include "Team.h"

TeamSet::TeamSet() : TeamSet(10) {}

TeamSet::TeamSet(int maxTeams) : MAX_TEAMS(maxTeams), numTeams(0), MAX_RELATION(120) {
    teams = (Team**)(malloc(sizeof(Team*) * MAX_TEAMS));

    relations = (int**)(malloc(sizeof(int*) * MAX_TEAMS));
    for(int i = 0; i < MAX_TEAMS; i++) {
        relations[i] = (int*)(malloc(sizeof(int) * MAX_TEAMS));
    }

    for(int i = 0; i < MAX_TEAMS; i++) {
        for(int j = 0; j < MAX_TEAMS; j++) {
            relations[i][j] = 0;
        }
    }
}

Team* TeamSet::addTeam(std::string name, bool constRelations) {
    Team* newTeam = nullptr;
    if(numTeams < MAX_TEAMS && !containsTeam(name)) {
        newTeam = new Team(name, numTeams, constRelations);
        teams[numTeams++] = newTeam;
    }
    return newTeam;
}

void TeamSet::setRelations(Team* team, Team* team2, int value) {
    value = fixRelation(value);
    updateTable(team, team2, value);
}

void TeamSet::increaseRelations(Team* team, Team* team2, int value) {
    if(containsTeam(team) && containsTeam(team2)) {
        value += relations[team->getID()][team2->getID()];
        updateTable(team, team2, fixRelation(value));
    }
}

int TeamSet::getRelations(Team* team, Team* team2) {
    int result = 0;
    if(containsTeam(team) && containsTeam(team2)) {
        result = relations[team->getID()][team2->getID()];
    }
    return result;
}

bool TeamSet::containsTeam(Team* team) {
    return (team->getID() < MAX_TEAMS  && teams[team->getID()] != nullptr);
}

bool TeamSet::containsTeam(std::string name) {
    bool contains = false;
    for(int i = 0; i < numTeams && !contains; i++) {
        if(name.compare(teams[i]->getName()) == 0) 
            contains = true;
    }
    return contains;
}

bool TeamSet::updateTable(Team* team, Team* team2, int newValue) {
    bool updated = false;
    if(containsTeam(team) && containsTeam(team2)) {
        relations[team->getID()][team2->getID()] = newValue;
        relations[team2->getID()][team->getID()] = newValue;
        updated = true;
    }
    return updated;
}

int TeamSet::fixRelation(int value) {
    value = __max(-MAX_RELATION, value);
    value = __min(MAX_RELATION, value);
    return value;
}