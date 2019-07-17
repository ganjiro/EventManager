// Created by girol on 15/07/2019.
//

#include "gtest/gtest.h"

#include "../EventManager.h"


TEST(EventManager, ManagerTest1) {

    auto a= new EventManager(R"(C:\Users\girol\Desktop\EventManager\Utils\Events.txt)");
    a->newEvent("MICC - Elaborato",17,7,2019,17,00);
    ASSERT_LT(-1,a->searchEvent("MICC - Elaborato") );
    delete a;

    auto b= new EventManager(R"(C:\Users\girol\Desktop\EventManager\Utils\Events.txt)");
    ASSERT_LT(-1,b->searchEvent("MICC - Elaborato") );
    b->editEventDate("MICC - Elaborato",17,7,2019,17,30);
    ASSERT_EQ("17/7/2019 17:30", b->getEventDate("MICC - Elaborato"));
    delete b;

    auto c= new EventManager(R"(C:\Users\girol\Desktop\EventManager\Utils\Events.txt)");
    ASSERT_EQ("17/7/2019 17:30", c->getEventDate("MICC - Elaborato"));
    delete c;
}
