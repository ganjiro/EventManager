//
// Created by girol on 14/07/2019.
//

#ifndef EVENTMANAGER_EVENTMANAGER_H
#define EVENTMANAGER_EVENTMANAGER_H

#include "Event.h"
#include <fstream>
#include <exception>
#include <map>
#include "Date.h"

class ToDoList {
public:
    explicit ToDoList(string n): name(n){
        fstream saveFile;
        saveFile.open("./_SaveFiles/"+n+".txt");


        if (saveFile) {
            loadLines(saveFile);
            saveFile.close();
            cout<<"ciao";
        }
        else{
            FILE* tmp;
            string a="./_SaveFiles/"+n+".txt";
            tmp=fopen(a.c_str(),"w");
            fclose(tmp);
        }
    }

    void loadLines(fstream& saveFile);

    string searchEventDate(string e);

    void newEvent(string e, int d, int m, int y, int h, int mi);
    void newEvent(string e, string d,int h, int m=0);

    void editEventName(string old_e, string e);
    void editEventDate(string old_e, int d, int m, int y, int h, int mi);
    void editEventHour(string d, string e, int h, int m);

    void setChecked(string e);
    void setUNChecked(string e);

    void deleteEvent(string e);

    void printevent(string e);
    void printAllEvents();
    void printEventsInDate(string d);

    string getEventDate(string e);

    int eventCount();
    int dayEventCount(string d);


    ~ToDoList();
private:

    multimap<Date,Event> events;
    string name;
};


#endif
