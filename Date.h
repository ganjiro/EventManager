//
// Created by girol on 18/07/2019.
//

#ifndef EVENTMANAGER_DATE_H
#define EVENTMANAGER_DATE_H


#include <ostream>
#include "time.h"
#include <stdio.h>
#include <ostream>

class Date {
public:
    explicit Date(int aDay, int aMonth, int aYear);

    explicit Date(std::string d);

    int getDay() const;

    int getMonth() const;

    int getYear() const;

    void setDay(int day);

    void setMonth(int month);

    void setYear(int year);

    static Date today();

    static Date fromString(std::string str);

    std::string toString() const;

    bool operator<(const Date &right) const;

    bool operator==(const Date &right) const;


private:
    short unsigned int day;
    short unsigned int month;
    short unsigned int year;

    int getMaxDays(int year);

    std::string getMonthString(short unsigned int month) const;
};


#endif //EVENTMANAGER_DATE_H
