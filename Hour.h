//
// Created by girol on 18/07/2019.
//

#ifndef EVENTMANAGER_HOUR_H
#define EVENTMANAGER_HOUR_H

#include <stdexcept>

class Hour {
public:
    explicit Hour(short unsigned int h, short unsigned int m);

    int getHours() const;

    int getMinutes() const;

    std::string toString() const;

    Hour fromString(std::string str);

    void setHours(unsigned short hours);

    void setMinutes(unsigned short minutes);

    bool operator<(const Hour &right) const;

    bool operator==(const Hour &right) const;


private:
    short unsigned int hours;
    short unsigned int minutes;
};

#endif //EVENTMANAGER_HOUR_H
