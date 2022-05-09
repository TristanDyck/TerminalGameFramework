#include "Queue.h"
#include "Node.h"
#include "Event.h"

Queue::Queue() : top(nullptr), numElements(0) {}
Queue::~Queue() {
    Node* current = top;
    Node* next;
    while(current != nullptr) {
        next = current->getNext();
        delete current;
        current = next;
    }
    top = nullptr;
}

Event* Queue::getNext() {
    Event* data = nullptr;
    if(top != nullptr) {
        data = getNext(top->getData()->getTime());
    }
    return data;
}
Event* Queue::getNext(int time) {
    Event* data = nullptr;
    if(top != nullptr && top->getData()->getTime() == time) {
        data = top->getData();
        Node* oldTop = top;
        top = top->getNext();
        delete oldTop;
        numElements--;
    }
    return data;
}

void Queue::insert(Event *event) {
    Node* current = top;
    Node* prev = nullptr;

    Node* newNode = new Node(event);
    bool inserted = false;

    if(top == nullptr) { //insert in empty list
        top = newNode;
        inserted = true;
    }

    while(current != nullptr && !inserted) {
        if(event->compareTo(current->getData()) <= 0) {
            newNode->setNext(current);
            if(prev != nullptr) //insert in middle
                prev->setNext(newNode);
            else //insert at beginning
                top = newNode;
            inserted = true;
        } else {
            prev = current;
            current = current->getNext();
        }
    }

    if(!inserted) //insert at end
        prev->setNext(newNode);

    numElements++;
}

void Queue::insert(std::list<Event*> events) {
    std::list<Event*>::iterator current = events.begin();
    for(int i = 0; i < events.size(); i++) {
        insert(*current);
        current++;
    }
}

bool Queue::empty() {
    return (top == nullptr);
}

int Queue::size() {
    return numElements;
}

bool Queue::topTime(int time) {
    return (top != nullptr && top->getData()->getTime() == time);
}

std::string Queue::toString() {
    Node* current = top;
    std::string result = "";
    for(int i = 0; i < numElements; i++) {
        result += current->getData()->toString() + "\n";
        current = current->getNext();
    }
    return result;
}