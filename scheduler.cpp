//
// Created by alian on 12/17/18.
//

#include<algorithm>
#include<iostream>
#include "scheduler.h"
#include <unistd.h>

Scheduler::Scheduler(){
    std::make_heap(m_tasksHeap.begin(), m_tasksHeap.end());
}

Scheduler::Scheduler(ITask *task)
{
    m_tasksHeap.push_back(std::make_pair(shared_ptr<ITask>(task),Time(task->getNextRunPeriod())));
    std::make_heap(m_tasksHeap.begin(), m_tasksHeap.end());
}

void Scheduler::run() {
    STask* nextTask;
    while(!m_tasksHeap.empty()){
        nextTask = getNextTask();

        (*nextTask).second.sleep();
        (*(*nextTask).first).run();
        handleNextRun(nextTask);
    }
    std::cout << "All done!" << std::endl;
}


STask* Scheduler::getNextTask() {
    pop_heap(m_tasksHeap.begin(),m_tasksHeap.end());
    STask* temp = &(m_tasksHeap.back());
    return temp;
}

void Scheduler::appendTask(ITask* task){
    m_tasksHeap.push_back(std::make_pair(shared_ptr<ITask>(task),Time(task->getNextRunPeriod())));
    push_heap(m_tasksHeap.begin(), m_tasksHeap.end());
}

void Scheduler::handleNextRun(STask *task) {
    unsigned long deltaTime =  (*((*task).first)).getNextRunPeriod();
    if(deltaTime != 0){
        ((*task).second) = deltaTime;
        make_heap(m_tasksHeap.begin(), m_tasksHeap.end());
    }else{
        m_tasksHeap.pop_back();
    }
}

bool operator < (STask p1, STask p2){
    return !(p1.second < p2.second);
}

