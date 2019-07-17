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
            saveFile.close();
        }
    }
    explicit EventManager(string path);

    void loadLines();

    int searchEvent(string e);

    void newEvent(string e, tm* d);
    void newEvent(string e, int d, int m, int y, int h, int mi);
    void newEvent(string e);

    bool editEvent(string old_e, string e);
    bool editEvent(int indice, string e);
    void editEvent(vector<Event>::iterator begin, string e);
    bool editEventDate(string old_e, int d, int m, int y, int h, int mi);
    bool editEventDate(int indice, int d, int m, int y, int h, int mi);
    bool editEventDate(string old_e, tm* d);
    bool editEventDate(int indice, tm* d);
    void editEventDate(vector<Event>::iterator itr, int d, int m, int y, int h, int mi);

    void setChecked(int i);
    void setChecked(string e);
    void setUNChecked(int i);
    void setUNChecked(string e);

    void deleteEvent(string e);
    void deleteEvent(int indice);

    void printevent(string e);
    void printevent(int indice);
    void printevent(vector<Event>::const_iterator begin, vector<Event>::const_iterator end);
    void printEvents(int d, int m );
    void printAllEvents();

    string getEventDate(string e);
    string getEventDate(int i);
    string getEventText(int i);

    ~EventManager();

private:

    fstream saveFile;
    vector<Event*> events;

};


#endif //EVENTMANAGER_EVENTMANAGER_H
