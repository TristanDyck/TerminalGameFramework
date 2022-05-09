#include "Floor.h"
#include "Room.h"
#include "Entity.h"
#include "TeamSet.h"
#include "Team.h"
#include "EventMove.h"
#include "EventReload.h"
#include "EventDrawRoom.h"
#include "EventTurnPlayer.h"
#include "EventTurnAI.h"
#include "ComponentAttack.h"
#include "ComponentMove.h"
#include "ComponentHealth.h"
#include "ComponentConfidence.h"
#include "BehaviourAI.h"
#include "BehaviourPlayer.h"
#include <iostream>
#include <cctype>
#include "Queue.h"

std::string tolower(std::string);

int main() {
    srand(102);
    int x = 10;
    int y = 10;
    Floor* test = new Floor(10, 5, 5);
    Room* testRoom = new Room(x, y);
    test->addRoom(testRoom, test->getWidth()/2, test->getHeight()/2);
    TeamSet* teamSet = new TeamSet(30);
    Team* team1 = teamSet->addTeam("TeamPlayer", false);
    Team* team2 = teamSet->addTeam("TeamAI", false);
    Team* team3 = teamSet->addTeam("TeamAI2", false);

    Entity *player = new Entity("Player", team1, '@');
    Entity *enemy = new Entity("Enemy", team2, '*');

    teamSet->setRelations(team3, team2, -40);

    enemy->addComponent(new ComponentHealth(10, 3));
    enemy->addComponent(new ComponentMove);
    enemy->addComponent(new ComponentAttack(20, 1, true));
    enemy->addComponent(new ComponentConfidence);
    player->addComponent(new ComponentAttack(5, 2, true));
    player->addComponent(new ComponentMove);
    player->addComponent(new ComponentHealth(100));

    Entity *rivalEnemy = enemy->copy();
    rivalEnemy->changeTeam(team3);
    rivalEnemy->changeSymbol('!');

    Queue eventQueue;
    int currentTime = 0;

    testRoom->spawnEntity(player, x/2, y/2);

    std::string input = "";
    BehaviourPlayer* behaviourPlayer = new BehaviourPlayer(testRoom, input);
    BehaviourAI* behaviourAI = new BehaviourAI(testRoom, teamSet);

    std::cout << testRoom->toString();
    std::cout << "Commands: WASD: up/left/down/right, F: spawn team1 AI, "
    << "G: spawn team2 AI, EXIT: quit, Another key: next turn" << std::endl;
    std::cout << "Symbols: @: Player, *: team1 AI, !: team2 AI" << std::endl;
    while(input.compare("exit") != 0) {
        std::cin >> input;
        input = tolower(input);


        eventQueue.insert(new EventDrawRoom(testRoom, currentTime));

        eventQueue.insert(new EventTurnPlayer(behaviourPlayer, player, input, testRoom, currentTime));

        std::list<Entity*> entities = testRoom->getEntities();
        for(std::list<Entity*>::iterator current = entities.begin(); current != entities.end(); current++) {
            if((*current) == player)
                continue;
            eventQueue.insert(new EventTurnAI(behaviourAI, *current, testRoom, currentTime));
        }

        if(input.compare("f") == 0)
            testRoom->addEntity(enemy->copy());
        else if(input.compare("g") == 0)
            testRoom->addEntity(rivalEnemy->copy());
        else if(input.compare("events") == 0)
            std::cout << eventQueue.toString();

        
        while(eventQueue.topTime(currentTime)) {
            Event* next = eventQueue.getNext();
            next->process();
            eventQueue.insert(next->getNextEvents());
        }
        
        //std::cin >> input;
        currentTime++;
    }
    return 0;
}

std::string tolower(std::string string) {
    std::string result = "";

    for(int i = 0; i < string.length(); i++) {
        result += std::tolower(string[i]);
    }

    return result;
}