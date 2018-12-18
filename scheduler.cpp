//
// Created by alian on 12/17/18.
//

#include<algorithm>
#include<iostream>
#include "scheduler.h"
#include <unistd.h>


Scheduler::Scheduler(ITask *tasks, unsigned int tasksCount)
//Scheduler::Scheduler()
{
    while(tasksCount--)
    {
        m_tasksHeap.push_back(std::make_pair(shared_ptr<ITask>(tasks),Time(tasks->getNextRunPeriod())));
        ++tasks;
    }
    std::make_heap(m_tasksHeap.begin(), m_tasksHeap.end());
}

void Scheduler::run() {
    shared_ptr<ITask>* nextTask = getNextTask();
    long delta = (*nextTask)->getNextRunPeriod();
    if(delta <= 0)
        (*nextTask)->run();
    else
        usleep(delta*1000);
}

shared_ptr<ITask>* Scheduler::getNextTask() {
    shared_ptr<ITask>* temp = new shared_ptr<ITask>(m_tasksHeap.front().first);
    pop_heap(m_tasksHeap.begin(),m_tasksHeap.end());
    return temp;
}

void Scheduler::appendTask(ITask* task){
    m_tasksHeap.push_back(std::make_pair(shared_ptr<ITask>(task),Time(task->getNextRunPeriod())));
    push_heap(m_tasksHeap.begin(), m_tasksHeap.end());
}

bool operator < (STask p1, STask p2){
    return !(p1.second < p2.second);
}

