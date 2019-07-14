//
// Created by girol on 14/07/2019.
//

#ifndef EVENTMANAGER_EVENT_H
#define EVENTMANAGER_EVENT_H

#include <time.h>
#include <iostream>
using namespace std;

const char d_space='/';
const char h_space=':';
const char e_space='-';



class Event {
public:

    Event(){ date=new tm; };
    explicit Event(string e, tm* d): eventText(move(e)), date(d){};
    explicit Event(string e);

    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);
    void setHour(int h, int m=0);
    void setEvent(string e);


    string getDate()const;
    string getEvent()const;


private:
    tm* date;
    string eventText;
};


#endif //EVENTMANAGER_EVENT_H
