// Created by girol on 15/07/2019.
//

#include "gtest/gtest.h"

#include "../ToDoList.h"


TEST(EventManager, SaveTest) {

    auto a= new ToDoList("Pag");
    a->newEvent("Saldo",18,7,2019,17,00);
    EXPECT_EQ("18/7/2019",a->searchEventDate("Saldo") );
    delete a;
    auto b= new ToDoList("Pag");
    ASSERT_EQ("18/7/2019",a->searchEventDate("Saldo") );
    a->setChecked("18/07/2019","Saldo");
    ASSERT_TRUE(a->isDone("18/07/2019","Saldo"));
    delete b;

}

class TodoTester : public ::testing::Test {

protected:
    virtual void SetUp() {
        c.newEvent("Test1","10/10/2019",3,30);
        c.newEvent("Test2","11/10/2019",4,30);
        c.newEvent("Test4","12/10/2019",5,30);
    }

    ToDoList c=ToDoList("Test");
};


TEST_F (TodoTester, SaveTest) {

    EXPECT_EQ(3,c.eventCount());
    c.deleteEvent("Test1","10/10/2019");
    ASSERT_GT(3,c.eventCount());
    c.newEvent("Test4","12/10/2019",5,50);
    ASSERT_LT(1,c.dayEventCount("12/10/2019"));

}