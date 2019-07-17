//
// Created by girol on 17/07/2019.
//


#include "gtest/gtest.h"

#include "../Event.h"

TEST(Event, TestEvent) {

    auto a= new Event("Test1");
    a->setDone(true);
    a->setYear(2023);
    ASSERT_EQ(true,a->isDone());
    ASSERT_EQ("Test1",a->getEvent());
    ASSERT_EQ(2023,a->getYear());

}