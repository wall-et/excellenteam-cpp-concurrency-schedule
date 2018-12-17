//
// Created by alian on 12/17/18.
//

#ifndef EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_WALL_ET_ITASK_H
#define EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_WALL_ET_ITASK_H


class ITask
{
public:
    virtual ~ITask();
    virtual void run() = 0;
    virtual unsigned long getNextRunPeriod() = 0; // in milliseconds
private:
    unsigned long m_timeToNextRun;
};

class Printer : public ITask
{
public:
    Printer(unsigned long);
    ~Printer();
    void run();
    unsigned long getNextRunPeriod(); // in milliseconds
private:
    unsigned long m_timeToNextRun;
};

class AntiVirus : public ITask
{
public:
    AntiVirus(unsigned long);
    ~AntiVirus();
    void run();
    unsigned long getNextRunPeriod(); // in milliseconds
private:
    unsigned long m_timeToNextRun;
};

class ConnectionTest :public ITask
{
public:
    ConnectionTest(unsigned long);
    ~ConnectionTest();
    void run();
    unsigned long getNextRunPeriod(); // in milliseconds
private:
    unsigned long m_timeToNextRun;
};

#endif //EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_WALL_ET_ITASK_H
