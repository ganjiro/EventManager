#include <iostream>
#include <memory>
#include "ToDoList.h"

int main() {

   auto a= new ToDoList("Events");
   int s=a->eventCount();
   cout<<s<<endl;
   a->newEvent("Cena al Sushi","19/07/2019",19,20);
    s=a->eventCount();
    cout<<s<<endl;
    a->printEventsInDate("17/7/2019");
    a->setChecked("19/07/2019","Cena al Sushi");
    a->editEventDate("Cena al Sushi","19/07/2019","31/10/2020",19,20);
    a->deleteEvent("Cena al Sushi","31/10/2020");

    delete a;

    return 0;
}