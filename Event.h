#pragma once
#include <string>
#include <list>

class Event {
public:
    Event(int time, int priority);
    Event(int time, int priority, std::string name);
    virtual ~Event() = 0;

    virtual void process() = 0;
    std::list<Event*> getNextEvents();

    int getTime();

    bool operator<(const Event*);
    int compareTo(const Event*);

    std::string toString();
protected:
    void queueEvent(Event*);
    std::string execution;
private:
    int time; //time when the event will be executed
    int priority; //smaller value -> executed sooner
    const std::string NAME;
    static int nextID;
    int id;
    std::list<Event*> nextEvents;
};