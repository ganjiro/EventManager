//
// Created by girol on 14/07/2019.
//

#include "Event.h"

auto now = time(nullptr);

tm *a = gmtime(&now);


void Event::setEvent(string e) {

    eventText = move(e);

}


string Event::getEvent() const {
    return eventText;
}

Event::Event(string e) : eventText(move(e)), ora(Hour(a->tm_hour, a->tm_min)) {}

bool Event::operator==(const Event &e) {
    return eventText == e.eventText;
}


bool Event::isDone() const {
    return done;
}

void Event::setDone(bool done) {
    Event::done = done;
}

void Event::setHour(int h) {

    ora.setHours(h);

}

void Event::setMinute(int m) {

    ora.setMinutes(m);

}

string Event::getHour() const {

    return to_string(ora.getHours());
}

string Event::getMinute() const {
    return to_string(ora.getMinutes());
}

string Event::getOutputHour() const {
    return to_string(ora.getHours()) + ':' + to_string(ora.getMinutes());
}


