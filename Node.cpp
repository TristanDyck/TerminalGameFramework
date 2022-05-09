#include "Node.h"
#include "Event.h"

Node::Node(Event *event) : next(nullptr), value(event) {}
Node::~Node() {}

Node* Node::getNext() {
    return next;
}
void Node::setNext(Node *next) {
    this->next = next;
}
Event* Node::getData() {
    return value;
}