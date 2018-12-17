//
// Created by alian on 12/17/18.
//

#ifndef EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_WALL_ET_SCHEDULER_H
#define EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_WALL_ET_SCHEDULER_H

#include <vector>
#include "ITask.h"
#include "shared_ptr.h"
#include "time.h"

typedef std::pair<shared_ptr<ITask>, Time> STask;

class Scheduler{
public:
    Scheduler(ITask *tasks);
    void run();
private:
    ITask & getNextTask();
    std::vector<STask> m_tasksHeap;
};

#endif //EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_WALL_ET_SCHEDULER_H
