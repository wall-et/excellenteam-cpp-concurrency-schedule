//
// Created by alian on 12/17/18.
//

#ifndef EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_WALL_ET_ITASK_H
#define EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_WALL_ET_ITASK_H

#include <>

class ITask
{
public:
    ITask(unsigned long);
    virtual void run() = 0;
    virtual unsigned long getNextRunPeriod() = 0; // in milliseconds
private:
    unsigned long m_timeToNextRun;
};

class Printer : public ITask
{
public:
    Printer(unsigned long);
    void run();
    unsigned long getNextRunPeriod(); // in milliseconds
private:
    unsigned long m_timeToNextRun;
};

class AntiVirus : public ITask
{
public:
    AntiVirus(unsigned long);
    void run();
    unsigned long getNextRunPeriod(); // in milliseconds
private:
    unsigned long m_timeToNextRun;
};

class ConnectionTest : public ITask
{
public:
    Printer(unsigned long);
    void run();
    unsigned long getNextRunPeriod(); // in milliseconds
private:
    unsigned long m_timeToNextRun;
};

#endif //EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_WALL_ET_ITASK_H
