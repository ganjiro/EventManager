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


void ToDoList::editEventName(string old_e, string e) {

    for(auto itr : events){

        if (itr.second.getEvent()==old_e){

            itr.second.setEvent(move(e));
            break;
        }
    }
}

 void ToDoList::editEventDate(string e, int d, int m, int y, int h, int mi) {


    for(auto itr=events.begin();itr!=events.end();++itr){
        if (itr->second.getEvent()==e){

            events.erase(itr);
            auto tmp1= Date(d,m,y);
            auto tmp2= Event(move(e),h,mi);
            events.insert(make_pair(tmp1,tmp2));
            break;
        }
    }
}




void ToDoList::deleteEvent(string e) {

    for (auto itr = events.begin(); itr != events.end(); ++itr) {
        if (itr->second.getEvent() == e) {

            events.erase(itr);
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



void ToDoList::setChecked(string e) {

    for (auto itr : events) {
        if (itr.second.getEvent() == e) {
            itr.second.setDone(true);
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



    void ToDoList::setUNChecked(string e) {

        for (auto itr : events) {
            if (itr.second.getEvent() == e) {
                itr.second.setDone(false);
            }

        }
    }







