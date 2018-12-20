//
// Created by alian on 12/17/18.
//
#include <iostream>
#include "task_time.h"
#include "scheduler.h"

void testTimeSleep(){
    Time t1(2000);
    t1.sleep();
    std::cout << "I'm awake. ok." << std::endl;
}
void testTimeSmallOperator(){
    Time t1(2000);
    Time t2(1000);
    if(t2 < t1)
        std::cout << "< operator. ok" << std::endl;
    else
        std::cout << "< operator. fail" << std::endl;
}

int main(){

//    testTimeSleep();
//    testTimeSmallOperator();

    AntiVirus* a1 = new AntiVirus(2000);
    Printer* p1 = new Printer(500);
    Printer* p2 = new Printer(5000);
    ConnectionTest* c1 = new ConnectionTest(1000);

    Scheduler s1;
    s1.appendTask(p1);
    s1.appendTask(p2);
    s1.appendTask(c1);
    s1.appendTask(a1);

    s1.run();

    return 0;
}