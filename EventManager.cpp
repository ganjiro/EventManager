//
// Created by girol on 14/07/2019.
//

#include "EventManager.h"
int linecount=0;

void EventManager::loadLines() {
    try {
        linecount=0;
        string line,data,ora,evento;
        int a;
        while (getline(saveFile, line)) {
            linecount++;
            a = line.find(csv_space);


            data=line.substr(0, a);
            line = line.substr(a + 1);
            a = line.find(csv_space);
            ora=line.substr(0, a);
            evento = line.substr(a + 1);
            auto event = new Event(evento);


            a = data.find(d_space);
            event->setDay(stoi(data.substr(0, a)));
            data = data.substr(a + 1);

            a = data.find(d_space);
            event->setMonth(stoi(data.substr(0, a)));
            data = data.substr(a + 1);

            a = data.find(d_space);
            event->setYear(stoi(data.substr(0, a)));
            data = data.substr(a + 1);

            a = ora.find(h_space);
            auto c = ora.substr(a, ora.length());
            event->setHour(stoi(ora.substr(0, a)), stoi(ora.substr(a + 1, ora.length())));

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
        line=(*itr).getDate()+csv_space+(*itr).getEvent()+'\n';
        saveFile << line;
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

void EventManager::printEvents(int d, int m) {


    for(const auto itr : events) {

        if (itr->getDay() == d && itr->getMonth() == m) {
            cout << itr->getDate() << "  " << itr->getEvent() << endl;
        }
    }

}

void EventManager::newEvent(string e, tm *d) {

    events.push_back(new Event(move(e),d));

}

void EventManager::newEvent(string e, int d, int m, int y, int h, int mi) {

    auto tmp = new Event(move(e));
    tmp->setDay(d);
    tmp->setMonth(m);
    tmp->setYear(y);
    tmp->setHour(h,mi);

    events.push_back(tmp);

}

void EventManager::newEvent(string e) {

    events.push_back(new Event(move(e)));

}

bool EventManager::editEvent(string old_e, string e) {
    auto ris=false;
    auto itr=find(events.begin(),events.end(), new Event(move(old_e)));

    if (*itr != nullptr){
        ris=true;
        (*itr)->setEvent(move(e));

    }

    return ris;
}

bool EventManager::editEvent(int indice, string e) {
    auto ris=false;
    if (events[indice]!= nullptr){
        ris=true;
        events[indice]->setEvent(move(e));
    }

    return ris;
}

bool EventManager::editEventDate(string old_e, int d, int m, int y, int h, int mi) {
    auto ris=false;
    auto itr=find(events.begin(),events.end(), new Event(move(old_e)));

    if (*itr != nullptr) {
        ris = true;
        (*itr)->setHour(h,mi);
        (*itr)->setMonth(m);
        (*itr)->setYear(y);
        (*itr)->setDay(d);
    }
    return ris;
}

bool EventManager::editEventDate(int indice, int d, int m, int y, int h, int mi) {

    auto ris=false;
    if (events[indice]!= nullptr){
        ris=true;
        events[indice]->setHour(h,mi);
        events[indice]->setMonth(m);
        events[indice]->setYear(y);
        events[indice]->setDay(d);
    }

    return ris;
}

bool EventManager::editEventDate(string old_e, tm *d) {
    auto ris=false;
    auto itr=find(events.begin(),events.end(), new Event(move(old_e)));

    if (*itr != nullptr) {
        ris = true;
        (*itr)->setdate(d);
    }

    return ris;
}

bool EventManager::editEventDate(int indice, tm *d) {
    auto ris=false;
    if (events[indice]!= nullptr){
        ris=true;
        events[indice]->setdate(d);

    }
    return ris;
}

void EventManager::deleteEvent(string e) {

    auto itr = find(events.begin(),events.end(),new Event(move(e)));
    if(*itr!= nullptr) {
        events.erase(itr);
    }
}

void EventManager::deleteEvent(int indice) {

    if (events[indice]!= nullptr){
        events.erase(find(events.begin(),events.end(),events[indice]));
    }

}

void EventManager::printevent(string e) {

    auto itr = find(events.begin(),events.end(),new Event(move(e)));
    if(*itr!= nullptr) {
        cout<<(*itr)->getDate()<<' '<<(*itr)->getEvent()<<endl;
    }


}

void EventManager::printevent(int indice) {

    if (events[indice]!= nullptr){
        cout<<events[indice]->getDate()<<' '<<events[indice]->getEvent()<<endl;
    }

}

void EventManager::printAllEvents() {

    for (auto itr: events){
        cout<<(*itr).getDate()<<' '<<(*itr).getEvent()<<endl;
    }

}



