//
// Created by girol on 14/07/2019.
//

#include "EventManager.h"

void EventManager::loadLine() {

    string line;
    getline(saveFile, line);
    int a=line.find(e_space);

    auto event=new Event(line.substr(a+1));
    line=line.substr(0,a);

    a=line.find(d_space);
    event->setDay(stoi(line.substr(0,a)));
    line=line.substr(a+1);

    a=line.find(d_space);
    event->setMonth(stoi(line.substr(0,a)));
    line=line.substr(a+1);

    a=line.find(d_space);
    event->setYear(stoi(line.substr(0,a)));
    line=line.substr(a+1);

    a=line.find(h_space);
    auto c=line.substr(a,line.length());
    event->setHour(stoi(line.substr(0,a)),stoi(line.substr(a+1,line.length())));

    events.push_back(event);
}
