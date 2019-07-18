#include <iostream>
#include <memory>
#include "ToDoList.h"

int main() {

   auto a= new ToDoList("Events");
    //auto a=make_unique<ToDoList>("Lavoro");
/*
 *
 *
    a->printAllEvents();
    int x=a->searchEvent("Esame");
    a->editEvent(,"Lezione");
    a->editEvent("Lezione", "Esercizio");
    a->editEventDate("TEST",17,7,2019,17,30);
    cout<<endl<<endl;
    a->printAllEvents();
*/
    return 0;
}