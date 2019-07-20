//
// Created by girol on 14/07/2019.
//

#include "ToDoList.h"

int linecount=0;


void ToDoList::loadLines(fstream& saveFile) {
    try {
        linecount=0;
        string line,data,ora,evento,check;
        int a;
        while (getline(saveFile, line)) {
            linecount++;

            a = line.find(csv_space);
            data=line.substr(0, a);
            line = line.substr(a + 1);
            a = line.find(csv_space);
            ora=line.substr(0, a);
            line = line.substr(a + 1);
            a = line.find(csv_space);
            evento = line.substr(0, a);
            check = line.substr(a + 1);

            auto event = Event(evento);

            a = ora.find(h_space);
            auto c = ora.substr(a, ora.length());
            event.setHour(stoi(ora.substr(0, a)));
            event.setMinute(stoi(ora.substr(a + 1, ora.length())));

            event.setDone(stoi(check));

            events.insert(make_pair(Date(data),event));
        }

    }
    catch (exception& e){
        cerr<<"Corrupted line "<<linecount<<endl;
    }
}


ToDoList::~ToDoList() {
    string line;
    fstream saveFile;
    saveFile.open("./_SaveFiles/"+name+".txt",ios::out | ios::trunc);
    if (saveFile) {
        for(const auto& itr: events) {
            line = "";
            line = itr.first.toString()+ csv_space +itr.second.getOutputHour()+ csv_space + itr.second.getEvent() +  csv_space + (itr.second.isDone()?'1':'0')+'\n';
            saveFile << line;
        }
        saveFile.close();
    }
}


string ToDoList::searchEventDate(string e) {
    string tmp;
    for(const auto itr : events){

        if (itr.second.getEvent()==e){

             tmp=itr.first.toString();
            break;
        }

    }
    return tmp;
}



void ToDoList::newEvent(string e, int d, int m, int y, int h, int mi) {

    auto tmpE = Event(move(e),h,mi);
    auto tmpD = Date(d,m,y);

    events.insert(make_pair(tmpD,tmpE));

}



void ToDoList::editEventName(string old_e, string e,string d) {

    auto itr = events.find(Date(d));
    if(itr!=events.end()) {
        while(itr->first.toString()==d) {
            if (itr->second.getEvent() == e) {
                bool done = itr->second.isDone();
                int h = stoi(itr->second.getHour());
                int m = stoi(itr->second.getMinute());
                events.erase(itr);
                auto tmp1 = Date(d);
                auto tmp2 = Event(move(e), h, m);
                tmp2.setDone(done);
                break;

            } else {
                itr++;
            }
        }

    }
}

 void ToDoList::editEventDate(string e, string old_d, int d, int m, int y, int h, int mi) {


     auto itr = events.find(Date(old_d));
     if(itr!=events.end()) {
            bool done=itr->second.isDone();
            events.erase(itr);
            auto tmp1= Date(d,m,y);
            auto tmp2= Event(move(e),h,mi);
            tmp2.setDone(done);
            events.insert(make_pair(tmp1,tmp2));
        }
    }




void ToDoList::deleteEvent(string e,string d) {


    auto itr = events.find(Date(d));
    while(itr->first.toString()==d) {
    if(itr!=events.end()) {
        if(itr->second.getEvent()==e) {
            events.erase(itr);
            break;
        }
        else {
            itr++;
        }
        }
    }
}






void ToDoList::printevent(string e) {

    for(auto itr : events) {

        if (itr.second.getEvent() == e) {

            cout << itr.first.toString() << ' ' << itr.second.getOutputHour() << ' ' << itr.second.getEvent() << " - "
                 << (itr.second.isDone() ? "Fatto" : "Da Fare") << endl;
            break;
        }
    }

}



void ToDoList::printAllEvents() {

    for (auto itr: events){
        cout<<itr.first.toString()<<' '<<itr.second.getOutputHour()<<' '<<itr.second.getEvent()<<" - "<<(itr.second.isDone()?"Fatto":"Da Fare")<<endl;
    }


}



void ToDoList::setChecked(string d,string e) {

    auto itr = events.find(Date(d));
    if(itr!=events.end()) {
        while(itr->first.toString()==d) {
            if (itr->second.getEvent() == e) {
                auto tmp1 = itr->first;
                auto tmp2 = itr->second;
                events.erase(itr);
                tmp2.setDone(true);
                events.insert(make_pair(tmp1, tmp2));
                break;

            } else {
                itr++;
            }
        }

    }
}




string ToDoList::getEventDate(string e) {
    string ris;
    for (auto itr : events) {
        if (itr.second.getEvent() == e) {
            ris=itr.first.toString();
            break;
        }
    }
        return ris;
}

void ToDoList::newEvent(string e, string d, int h, int m) {

    auto tmpE = Event(move(e));
    auto tmpD = Date(d);

    events.insert(make_pair(tmpD,tmpE));

}



    void ToDoList::setUNChecked(string d, string e) {

            auto itr = events.find(Date(d));
            if(itr!=events.end()) {
                while (itr->first.toString() == d) {
                    if (itr->second.getEvent() == e) {
                        auto tmp1 = itr->first;
                        auto tmp2 = itr->second;
                        events.erase(itr);
                        tmp2.setDone(false);
                        events.insert(make_pair(tmp1, tmp2));
                        break;

                    } else {
                        itr++;
                    }
                }


            }
}

void ToDoList::editEventHour(string d, string e, int h, int m) {

    auto itr = events.find(Date(d));
    if(itr!=events.end()) {
        while(itr->first.toString()==d) {
            if (itr->second.getEvent() == e) {
                auto tmp1 = itr->first;
                auto tmp2 = itr->second;
                events.erase(itr);
                tmp2.setHour(h);
                tmp2.setMinute(m);
                events.insert(make_pair(tmp1, tmp2));
                break;

            } else {
                itr++;
            }
        }

    }
}


void ToDoList::printEventsInDate(string d) {

    for (const auto& itr : events) {
        if (itr.first.toString() == d) {

            cout<<itr.first.toString()<<' '<<itr.second.getOutputHour()<<' '<<itr.second.getEvent()<<" - "<<(itr.second.isDone()?"Fatto":"Da Fare")<<endl;

        }
    }
}

int ToDoList::eventCount() {

    return events.size();
}

int ToDoList::dayEventCount(string d) {
    int ris=0;
    for (const auto& itr : events) {
        if (itr.first.toString() == d) {

            ris++;
        }
    }
    return ris;
}

void ToDoList::editEventDate(string e, string old_d, string d, int h, int m) {

    auto itr = events.find(Date(old_d));
    if(itr!=events.end()) {
        while(itr->first.toString()==d) {
            if (itr->second.getEvent() == e) {
                bool done = itr->second.isDone();
                events.erase(itr);
                auto tmp1 = Date(d);
                auto tmp2 = Event(move(e), h, m);
                tmp2.setDone(done);
                events.insert(make_pair(tmp1, tmp2));
                break;
            } else {
                itr++;
            }
        }

    }
}

void ToDoList::printUndoneEvents() {

    for(const auto& itr : events) {

        if (itr.second.isDone() == false) {

            cout << itr.first.toString() << ' ' << itr.second.getOutputHour() << ' ' << itr.second.getEvent() << " - "
                 << (itr.second.isDone() ? "Fatto" : "Da Fare") << endl;
            break;
        }
    }


}

void ToDoList::printDoneEvents() {

    for(const auto& itr : events) {

        if (itr.second.isDone() == true) {

            cout << itr.first.toString() << ' ' << itr.second.getOutputHour() << ' ' << itr.second.getEvent() << " - "
                 << (itr.second.isDone() ? "Fatto" : "Da Fare") << endl;
            break;
        }
    }

}

string ToDoList::getEventHour(string d, string e) {

    string ris;
    auto itr = events.find(Date(d));
    if(itr!=events.end()) {
        while(itr->first.toString()==d) {
            if (itr->second.getEvent() == e) {
                ris=itr->second.getHour();
                break;
            } else {
                itr++;
            }
        }

    }

    return ris;
}

string ToDoList::getEventMinute(string d, string e) {
    string ris;
    auto itr = events.find(Date(d));
    if(itr!=events.end()) {
        while(itr->first.toString()==d) {
            if (itr->second.getEvent() == e) {
                ris=itr->second.getMinute();
                break;
            } else {
                itr++;
            }
        }

    }

    return ris;
}

bool ToDoList::isDone(string d, string e) {

    bool ris= false;
    auto itr = events.find(Date(d));
    if(itr!=events.end()) {
        while(itr->first.toString()==d) {
            if (itr->second.getEvent() == e) {
                ris=itr->second.isDone();
                break;
            } else {
                itr++;
            }
        }

    }

    return ris;
}

