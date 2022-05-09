#include "Event.h"

int Event::nextID = 0;

Event::Event(int time, int priority) : Event(time, priority, "Unnamed") {}
Event::Event(int time, int priority, std::string name) : execution("Unexecuted"), time(time), NAME(name), id(nextID++) {}
Event::~Event() {}

std::string Event::toString() {
    return ("Event: " + NAME + ", ID: " + std::to_string(id) + ", Effect: " + execution);
}

std::list<Event *> Event::getNextEvents() {
    return nextEvents;
}

int Event::getTime() {
    return time;
}

bool Event::operator<(const Event* event) {
    return (compareTo(event) <= 0);
}

// compare < 0: given event is lower priority than this one (earlier)
// compare = 0: given event is same priority as this one
// compare > 0: given event is higher priority than this one
int Event::compareTo(const Event* event) {
    int compare = time - event->time; 
    if(compare == 0)
        compare = priority - event->priority;
    return compare;
}

void Event::queueEvent(Event* event) {
    nextEvents.push_back(event);
}
