//
// Created by girol on 14/07/2019.
//

#include "EventManager.h"
int linecount=0;

void EventManager::loadLines() {
    try {
        linecount=0;
        string line;
        int a;
        while (getline(saveFile, line)) {
            linecount++;
            a = line.find(e_space);

            auto event = new Event(line.substr(a + 1));
            line = line.substr(0, a);

            a = line.find(d_space);
            event->setDay(stoi(line.substr(0, a)));
            line = line.substr(a + 1);

            a = line.find(d_space);
            event->setMonth(stoi(line.substr(0, a)));
            line = line.substr(a + 1);

            a = line.find(d_space);
            event->setYear(stoi(line.substr(0, a)));
            line = line.substr(a + 1);

            a = line.find(h_space);
            auto c = line.substr(a, line.length());
            event->setHour(stoi(line.substr(0, a)), stoi(line.substr(a + 1, line.length())));

            events.push_back(event);
        }
    }
    catch (exception& e){
        cerr<<"Corrupted line "<<linecount<<endl;
    }
}

EventManager::~EventManager() {
    string line;
    saveFile.clear();
    for(const auto itr: events) {
        line="";
        line=(*itr).getDate()+" / ";
        line+=(*itr).getEvent();
        saveFile << (*itr).getDate();
    }
}

int EventManager::searchEvent(string e) {
    int i=-1;
    for(const auto itr : events){
        i++;
        if (itr->getEvent()==e){
            break;

        }

    }
    return i;
}

void EventManager::searchEvents(int d, int m) {


    for(const auto itr : events) {

        if (itr->getDay() == d && itr->getMonth() == m) {
            cout << itr->getDate() << "  " << itr->getEvent() << endl;
        }
    }

}

void EventManager::newEvent(string e, tm *d) {

    events.push_back(new Event(e,d));

}

void EventManager::newEvent(string e, int d, int m, int y, int h, int mi) {

    auto tmp = new Event(e);
    tmp->setDay(d);
    tmp->setMonth(m);
    tmp->setYear(y);
    tmp->setHour(h,mi);

    events.push_back(tmp);

}

void EventManager::newEvent(string e) {

}

bool EventManager::editEvent(string old_e, string e) {
    return false;
}

bool EventManager::editEvent(int indice, string e) {
    return false;
}

bool EventManager::editEventDate(string old_e, int d, int m, int y, int h, int mi) {
    return false;
}

bool EventManager::editEventDate(int indice, int d, int m, int y, int h, int mi) {
    return false;
}

bool EventManager::editEventDate(string old_e, tm *d) {
    return false;
}

bool EventManager::editEventDate(int indice, tm *d) {
    return false;
}

void EventManager::deleteEvent(string e) {

}

void EventManager::deleteEvent(int indice) {

}

bool EventManager::editEventDate(int d, int m, int y, int h, int mi) {
    return false;
}

bool EventManager::editEventDate(tm *d) {
    return false;
}
