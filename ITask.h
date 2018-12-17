//
// Created by alian on 12/17/18.
//

#ifndef EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_WALL_ET_ITASK_H
#define EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_WALL_ET_ITASK_H

class ITask
{
public:
    virtual void run() = 0;
    virtual unsigned long getNextRunPeriod() = 0; // in milliseconds
private:
    unsigned long m_timeToNextRun;
};

#endif //EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_WALL_ET_ITASK_H
