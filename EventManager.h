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
        saveFile.open("..\\Utils\\Events.txt", ios_base::app);
        loadLines();
    }


    void loadLines();

    int searchEvent(string e);
    void searchEvents(int d, int m );

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
    bool editEventDate( int d, int m, int y, int h, int mi);
    bool editEventDate(tm* d);


    vector<Event*> events;

    virtual ~EventManager();

private:

    fstream saveFile;


};


#endif //EVENTMANAGER_EVENTMANAGER_H
