#include "Team.h"

Team::Team() : Team("Unnamed", 0, false) {}

Team::Team(std::string name, int id, bool constantRelation) : name(name), id(id), constantRelations(constantRelation) {}

bool Team::sameTeam(Team* otherTeam) {
    return (otherTeam->id == id);
}

int Team::getID() {
    return id;
}

std::string Team::getName() {
    return name;
}

bool Team::equals(Team* team) {
    return (id == team->id && name.compare(team->name) == 0);
}