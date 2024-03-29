//
// Created by girol on 18/07/2019.
//

#include "Date.h"
#include <chrono>
#include <ctime>
#include <iostream>
#include <time.h>

Date::Date(int aDay, int aMonth, int aYear) {
    if (aYear < 0)
        throw std::runtime_error("Year < 0");
    if (aDay < 0)
        throw std::runtime_error("Days < 0");
    if (aMonth < 0 || aMonth > 12)
        throw std::runtime_error("Error in month number");
    this->month = aMonth;
    this->year = aYear;
    if (aDay > getMaxDays(this->year))
        throw std::runtime_error("Error in number of days");
    this->day = aDay;

}


int Date::getDay() const {
    return this->day;
};


int Date::getMonth() const {
    return this->month;
};


int Date::getYear() const {
    return this->year;
};

int Date::getMaxDays(int year) {
    short unsigned int maxDay = 31;
    switch (this->month) {
        case 4: //April
        case 6: //June
        case 8: //September
        case 11: //November
            maxDay = 30;
            break;
        case 2: {

            if (year % 4 == 0) {
                if (year % 100 == 0) {
                    if (year % 400 == 0) {
                        maxDay = 29;
                    } else {
                        maxDay = 28;
                    }
                } else {
                    maxDay = 29;
                }
            } else {
                maxDay = 28;
            }
        }
    }
    return maxDay;
}

std::string Date::getMonthString(short unsigned int month) const {
    std::string monthText;
    switch (month) {
        case 1:
            monthText = "January";
            break;
        case 2:
            monthText = "February";
            break;
        case 3:
            monthText = "March";
            break;
        case 4:
            monthText = "April";
            break;
        case 5:
            monthText = "May";
            break;
        case 6:
            monthText = "June";
            break;
        case 7:
            monthText = "July";
            break;
        case 8:
            monthText = "August";
            break;
        case 9:
            monthText = "September";
            break;
        case 10:
            monthText = "October";
            break;
        case 11:
            monthText = "November";
            break;
        case 12:
            monthText = "December";
            break;
        default:
            monthText = "isNotMonth";
    }
    return monthText;
}

void Date::setDay(int day) {
    int maxDay = getMaxDays(this->year);
    if (day <= 0 || day > maxDay)
        throw std::runtime_error("Error in day");
    Date::day = day;
}

void Date::setMonth(int month) {
    Date::month = month;
    int maxDay = getMaxDays(this->year);
    if (day > maxDay)
        day = maxDay;
}

void Date::setYear(int year) {
    if (this->day > getMaxDays(year))
        throw std::runtime_error("Error in day after year modify");
    this->year = year;
}


Date Date::today() {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_c);;
    return Date(now_tm.tm_mday, now_tm.tm_mon + 1, now_tm.tm_year + 1900);
}


Date Date::fromString(std::string str) {
    std::tm t;
    strptime(str.c_str(), "%d/%m/%Y", &t);
    return Date(t.tm_mday, t.tm_mon + 1, t.tm_year + 1900);
}


std::string Date::toString() const {
    return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
}

bool Date::operator<(const Date &right) const {
    if (this->year > right.year)
        return false;
    else if (this->year == right.year) {
        if (this->month > right.month)
            return false;
        else if (this->month == right.month) {
            if (this->day >= right.day)
                return false;
        }
    }
    return true;
}


bool Date::operator==(const Date &right) const {
    return this->year == right.year && this->month == right.month && this->day == right.day;
}

Date::Date(std::string d) {

    *this = fromString(move(d));

}

