//
// Created by girol on 14/07/2019.
//

#ifndef EVENTMANAGER_EVENTMANAGER_H
#define EVENTMANAGER_EVENTMANAGER_H
#include "Event.h"
#include <fstream>
#include <vector>

class EventManager {
public:
    EventManager(){
        saveFile.open("..\\Utils\\Events.txt");
    }


    void loadLine();


private:

    ifstream saveFile;
    vector<Event*> events;

};


#endif //EVENTMANAGER_EVENTMANAGER_H
