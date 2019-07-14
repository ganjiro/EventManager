//
// Created by girol on 14/07/2019.
//

#include "Event.h"

void Event::setDay(int d) {

    date->tm_mday=d;

}

void Event::setMonth(int m) {

    date->tm_mon=m+1;

}

void Event::setYear(int y) {

    date->tm_year=y;

}

void Event::setHour(int h, int m) {

    date->tm_hour=h+4;
    date->tm_min=m;

}

void Event::setEvent(string e) {

    eventText=move(e);

}

string Event::getDate() const{

    string ris;

    ris=to_string(date->tm_mday)+"/";
    ris+=to_string(date->tm_mon)+"/";
    ris+=to_string(date->tm_year)+" ";
    ris+=to_string(date->tm_hour)+":";
    ris+=to_string(date->tm_min);

    return ris;
}

string Event::getEvent() const{
    return eventText;
}

Event::Event(string e): eventText(move(e)) {
    auto now=time(nullptr);
    date=gmtime(&now);

    date->tm_hour+=4;
    date->tm_year+=1900;
    date->tm_mon+=1;

}

