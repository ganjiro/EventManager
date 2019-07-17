//
// Created by girol on 14/07/2019.
//

#include "EventManager.h"
int linecount=0;

void EventManager::loadLines() {
    try {
        linecount=0;
        string line,data,ora,evento,check;
        int a;
        while (getline(saveFile, line)) {
            linecount++;



            a = line.find(csv_space);
            data=line.substr(0, a);
            line = line.substr(a + 1);
            a = line.find(csv_space);
            ora=line.substr(0, a);
            line = line.substr(a + 1);
            a = line.find(csv_space);
            evento = line.substr(0, a);
            check = line.substr(a + 1);

            Event* event = new Event(evento);


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

            event->setDone(stoi(check));

            events.emplace_back(event);

        }

    }
    catch (exception& e){
        cerr<<"Corrupted line "<<linecount<<endl;
    }
}

EventManager::~EventManager() {
    string line;
    saveFile.open(R"(C:\Users\girol\Desktop\EventManager\Utils\Events.txt)",ios::out | ios::trunc);
    if (saveFile) {
        for(const auto itr: events) {
            line = "";
            line = (*itr).getOutputDate() + csv_space + (*itr).getEvent() +  csv_space + ((*itr).isDone()?'1':'0')+'\n';
            saveFile << line;
        }
        saveFile.close();
    }
}

int EventManager::searchEvent(string e) {
    int i=-1;
    for(const auto itr : events){
        i++;
        if (itr->getEvent()==e){

            return i;
        }

    }
    i=-1;
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

    events.emplace_back(tmp);

}

void EventManager::newEvent(string e) {

    events.push_back(new Event(move(e)));

}

bool EventManager::editEvent(string old_e, string e) {
    auto ris=false;
    auto itr=events.begin();
    for(;itr!=events.end();itr++){

        if((*itr)->getEvent()==e){
            break;
        }
    }

    if (itr != events.end()){
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
    auto itr=events.begin();
    for(;itr!=events.end();itr++){

        if((*itr)->getEvent()==old_e){
            break;
        }
    }

    if (itr != events.end()){
        ris = true;
        (*itr)->setMonth(m);
        (*itr)->setHour(h,mi);
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
    auto itr=events.begin();
    for(;itr!=events.end();itr++){

        if((*itr)->getEvent()==old_e){
            break;
        }
    }

    if (itr != events.end()){
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

    auto itr=events.begin();
    for(;itr!=events.end();itr++){

        if((*itr)->getEvent()==e){
            break;
        }
    }

    if (itr != events.end()){
        events.erase(itr);
    }
}

void EventManager::deleteEvent(int indice) {

    if (events[indice]!= nullptr) {
        auto itr = events.begin();
        for (; itr != events.end(); itr++) {

            if ((*itr)->getEvent() == events[indice]->getEvent()) {
                break;
            }
        }

        if (itr != events.end()) {
            events.erase(itr);
        }
    }
}

void EventManager::printevent(string e) {

    auto itr=events.begin();
    for(;itr!=events.end();itr++){

        if((*itr)->getEvent()==e){
            break;
        }
    }

    if (itr != events.end()){
        cout<<(*itr)->getDate()<<' '<<(*itr)->getEvent()<<" - "<<((*itr)->isDone()?"Fatto":"Da Fare")<<endl;
    }


}

void EventManager::printevent(int indice) {

    if (events[indice]!= nullptr){
        cout<<events[indice]->getDate()<<' '<<events[indice]->getEvent()<<" - "<<(events[indice]->isDone()?"Fatto":"Da Fare")<<endl;
    }

}

void EventManager::printAllEvents() {

    for (auto itr: events){
        cout<<(*itr).getDate()<<' '<<(*itr).getEvent()<<" - "<<((*itr).isDone()?"Fatto":"Da Fare")<<endl;
    }


}



EventManager::EventManager(string path) {
        saveFile.open(path);
        if (saveFile) {
            loadLines();
            saveFile.close();
        }

}

void EventManager::editEvent(vector<Event>::iterator begin, string e) {

    (*begin).setEvent(e);

}

void EventManager::editEventDate(vector<Event>::iterator itr, int d, int m, int y, int h, int mi) {

    (*itr).setHour(h,mi);
    (*itr).setMonth(m);
    (*itr).setYear(y);
    (*itr).setDay(d);

}

void EventManager::setChecked(int i) {

    events[i]->setDone(true);

}

void EventManager::setChecked(string e) {

    auto itr=events.begin();
    for(;itr!=events.end();itr++){

        if((*itr)->getEvent()==e){
            break;
        }
    }

    if (itr != events.end()){

        (*itr)->setDone(true);

    }

}

void EventManager::setUNChecked(int i) {

    events[i]->setDone(false);

}

void EventManager::setUNChecked(string e) {

    auto itr=events.begin();
    for(;itr!=events.end();itr++){

        if((*itr)->getEvent()==e){
            break;
        }
    }

    if (itr != events.end()){

        (*itr)->setDone(false);

    }

}

void EventManager::printevent(vector<Event>::const_iterator begin, vector<Event>::const_iterator end) {

    for(auto itr=begin;itr!=end; itr++ ){

        cout<<(*itr).getDate()<<' '<<(*itr).getEvent()<<' '<<((*itr).isDone()?"Fatto":"Da Fare")<<endl;

    }
}

string EventManager::getEventDate(string e) {
    string ris;
    auto itr=events.begin();
    for(;itr!=events.end();itr++){

        if((*itr)->getEvent()==e){
            break;
        }
    }

    if (itr != events.end()){

        ris=(*itr)->getDate();

    }
        return ris;
}

string EventManager::getEventDate(int i) {
    string ris;

    ris=events[i]->getDate();

    return ris;
}


string EventManager::getEventText(int i) {
    string ris;

    ris=events[i]->getEvent();

    return ris;
}



