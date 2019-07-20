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

    void editEventName(string old_e, string e, string d);
    void editEventDate(string e,string old_d, int d, int m, int y, int h, int mi);
    void editEventDate(string e, string old_d, string d, int h, int m);
    void editEventHour(string e, string d, int h, int m);

    void setChecked(string d,string e);
    void setUNChecked(string d, string e);

    void deleteEvent(string e,string d);

    void printevent(string e);
    void printAllEvents();
    void printEventsInDate(string d);
    void printUndoneEvents();
    void printDoneEvents();

    string getEventDate(string e);
    string getEventHour(string d,string e);;
    string getEventMinute(string d,string e);;
    bool isDone(string d,string e);

    int eventCount();
    int dayEventCount(string d);

    ~ToDoList();

private:

    multimap<Date,Event> events;
    string name;
};


#endif
