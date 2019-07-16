#include <iostream>
#include <memory>
#include "EventManager.h"
int main() {

    auto a=make_unique<EventManager>();

    a->printAllEvents();


    return 0;
}