#include <iostream>
#include <memory>
#include "EventManager.h"
int main() {

    auto a=make_unique<EventManager>();

    cout<<a->events[1]->getDate();
    return 0;
}