//
// Created by girol on 14/07/2019.
//

#include "Event.h"

void Event::setDay(int d) {

    this->date->tm_mday=d;

}

void Event::setMonth(int m) {

    date->tm_mon=m;

}

void Event::setYear(int y) {

    date->tm_year=y;

}

void Event::setHour(int h, int m) {

    date->tm_hour=h;
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

    tm* a=gmtime(&now);

    a->tm_hour+=4;
    a->tm_year+=1900;
    a->tm_mon+=1;

    date= new tm;
    date->tm_hour=a->tm_hour;
    date->tm_min=a->tm_min;
    date->tm_year=a->tm_year;
    date->tm_mon=a->tm_mon;
    date->tm_mday=a->tm_mday;

}

bool Event::operator==(const Event &e) {

    return eventText==e.eventText;
}

int Event::getDay() const {

    return date->tm_mday;
}

void Event::setdate(tm *d) {

    delete [] date;
    date=d;

}

int Event::getMonth() const {
    return date->tm_mon;
}

int Event::getYear() const {
    return date->tm_year;
}

string Event::getOutputDate() const {
    string ris;

    ris=to_string(date->tm_mday)+"/";
    ris+=to_string(date->tm_mon)+"/";
    ris+=to_string(date->tm_year)+';';
    ris+=to_string(date->tm_hour)+":";
    ris+=to_string(date->tm_min);
    return ris;
}


