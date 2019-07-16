#include <iostream>
#include <memory>
#include "EventManager.h"

int main() {
    auto a=new EventManager();

    a->printAllEvents();


    int x=a->searchEvent("ciao");
    delete a;

    return x;
}