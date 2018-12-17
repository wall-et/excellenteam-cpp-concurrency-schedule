//
// Created by alian on 12/17/18.
//

#include<algorithm>
#include<iostream>
#include "scheduler.h"


Scheduler::Scheduler(ITask *tasks, unsigned int tasksCount)
{
    while(tasksCount--)
    {
        m_tasksHeap.push_back(std::make_pair(shared_ptr<ITask>(tasks),Time(tasks->getNextRunPeriod())));
        ++tasks;
    }
    std::make_heap(m_tasksHeap.begin(), m_tasksHeap.end());
}

void Scheduler::run() {
    (*getNextTask())->run();
}

shared_ptr<ITask>* Scheduler::getNextTask() {
    shared_ptr<ITask>* temp = new shared_ptr<ITask>(m_tasksHeap.front().first);
    pop_heap(m_tasksHeap.begin(),m_tasksHeap.end());
    return temp;
}

bool operator < (STask p1, STask p2){
    return !(p1.second < p2.second);
}

