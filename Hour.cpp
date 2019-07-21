//
// Created by girol on 18/07/2019.
//

#include "Hour.h"
#include <ctime>


Hour::Hour(short unsigned int h, short unsigned int m) {
    if (h < 0 || h > 24) {
        throw std::runtime_error("Error in hours number");
    }
    if (m < 0 || m > 60) {
        throw std::runtime_error("Error in minutes number");
    }
    this->hours = h;
    this->minutes = m;

}


Hour Hour::fromString(std::string str) {
    std::tm t;
    strptime(str.c_str(), "%H:%M:%S", &t);
    return Hour(t.tm_hour, t.tm_min);
}

std::string Hour::toString() const {
    return std::to_string(hours) + ":" + std::to_string(minutes);
}

bool Hour::operator<(const Hour &right) const {
    if (this->hours > right.hours)
        return false;
    else if (this->hours == right.hours) {
        if (this->minutes > right.minutes)
            return false;
    }
    return true;
}


bool Hour::operator==(const Hour &right) const {
    return this->hours == right.hours && this->minutes == right.minutes;

}


int Hour::getHours() const {
    return hours;
}

int Hour::getMinutes() const {
    return minutes;
}

void Hour::setHours(unsigned short hours) {
    Hour::hours = hours;
}

void Hour::setMinutes(unsigned short minutes) {
    Hour::minutes = minutes;
}


