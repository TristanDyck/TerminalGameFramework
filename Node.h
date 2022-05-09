#pragma once

class Event;
class Node {
public:
    Node(Event*);
    ~Node();

    Node* getNext();
    void setNext(Node*);
    Event* getData();
private:
    Node* next;
    Event* value;
};