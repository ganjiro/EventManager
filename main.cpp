#include <iostream>
#include <memory>
#include "EventManager.h"

int main() {





 auto a=make_unique<EventManager>();

    a->printAllEvents();
    int x=a->searchEvent("Esame");
    a->editEvent(x,"Lezione");
    a->editEvent("Lezione", "Esercizio");
    a->editEventDate("TEST",17,7,2019,17,30);

    return 0;
}