//
// Created by alian on 12/17/18.
//

#ifndef EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_WALL_ET_SCHEDULER_H
#define EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_WALL_ET_SCHEDULER_H

#include <vector>
#include "ITask.h"
#include "shared_ptr.h"
#include "task_time.h"

typedef std::pair<shared_ptr<ITask>, Time> STask;

class Scheduler{
public:
    Scheduler();
    Scheduler(ITask *task);

    void appendTask(ITask* task);
    void run();
private:
    STask * getNextTask();
    void handleNextRun(STask*);
    std::vector<STask> m_tasksHeap;
};

bool operator < (STask p1, STask p2);

#endif //EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_WALL_ET_SCHEDULER_H
