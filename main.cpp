//
// Created by alian on 12/17/18.
//
#include "scheduler.h"

int main(){

    ITask tasks [4];

    Printer p1(500);
    Printer p2(500);
    AntiVirus a1(2000);
    ConnectionTest c1(50);

    tasks[0] = &p1;
    tasks[1] = &p2;
    tasks[2] = &a1;
    tasks[3] = &c1;

    Scheduler s1(tasks,4);

    return 0;
}