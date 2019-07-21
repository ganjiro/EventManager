//
// Created by girol on 14/07/2019.
//

#ifndef EVENTMANAGER_EVENT_H
#define EVENTMANAGER_EVENT_H

#include <time.h>
#include <iostream>
#include <algorithm>
#include "Hour.h"

using namespace std;

const char h_space = ':';
const char csv_space = ';';


class Event {
public:

    explicit Event(string e, int h, int m) : eventText(move(e)), ora(Hour(h, m)) {};

    explicit Event(string e);

    void setHour(int h);

    void setEvent(string e);

    void setMinute(int m);


    string getHour() const;

    string getMinute() const;

    string getEvent() const;

    bool isDone() const;

    void setDone(bool done);

    string getOutputHour() const;

    bool operator==(const Event &e);

private:
    Hour ora;
    string eventText;
    bool done = false;
};


#endif //EVENTMANAGER_EVENT_H
