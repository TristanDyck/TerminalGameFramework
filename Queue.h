//custom queue made for eventQueue
//not exactly a queue, but the events are sorted by time/priority
//so it is "first to happen, first out"
#pragma once
#include <string>
#include <list>

class Node;
class Event;
class Queue {
public:
    Queue();
    ~Queue();

    Event* getNext();
    Event* getNext(int time);
    void insert(Event*);
    void insert(std::list<Event*>);

    bool empty();
    int size();
    bool topTime(int time);

    std::string toString();
private:
    Node* top;
    int numElements;
};