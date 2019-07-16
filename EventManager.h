//
// Created by girol on 14/07/2019.
//

#ifndef EVENTMANAGER_EVENTMANAGER_H
#define EVENTMANAGER_EVENTMANAGER_H
#include "Event.h"
#include <fstream>
#include <vector>
#include <exception>

class EventManager {
public:
    EventManager(){
        saveFile.open("..\\Utils\\Events.txt");
        if (saveFile) {
            loadLines();
        }
    }


    void loadLines();

    int searchEvent(string e);


    void newEvent(string e, tm* d);
    void newEvent(string e, int d, int m, int y, int h, int mi);
    void newEvent(string e);

    bool editEvent(string old_e, string e);
    bool editEvent(int indice, string e);
    bool editEventDate(string old_e, int d, int m, int y, int h, int mi);
    bool editEventDate(int indice, int d, int m, int y, int h, int mi);
    bool editEventDate(string old_e, tm* d);
    bool editEventDate(int indice, tm* d);

    void deleteEvent(string e);
    void deleteEvent(int indice);

    void printevent(string e);
    void printevent(int indice);
    void printEvents(int d, int m );
    void printAllEvents();





    virtual ~EventManager();

private:

    fstream saveFile;
    vector<Event*> events;

};


#endif //EVENTMANAGER_EVENTMANAGER_H
