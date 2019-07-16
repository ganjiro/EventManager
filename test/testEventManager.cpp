// Created by girol on 15/07/2019.
//

#include "gtest/gtest.h"

#include "../EventManager.h"


TEST(EventManager, Test) {

    auto c= new EventManager("C:\\Users\\girol\\Desktop\\EventManager\\Utils\\Events.txt");
    c->newEvent("MICC - Elaborato",17,7,2019,17,00);

    ASSERT_LT(-1,c->searchEvent("MICC - Elaborato") );
    //ASSERT_EQ(17,c->);
}

