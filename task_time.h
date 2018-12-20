//
// Created by alian on 12/17/18.
//

#ifndef EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_WALL_ET_TIME_H
#define EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_WALL_ET_TIME_H

#include <time.h>

typedef struct timespec timespec;

class Time{
public:
    Time(unsigned long);

    Time& operator +(unsigned long);
    bool operator <(Time&) const;
    Time & operator=(unsigned long);
//    bool operator ==(Time&) const;
//    long operator -(Time&) const;

    void sleep() const;

private:

    timespec m_time;

};



#endif //EXCELLENTEAM_ELLA_CONCURRENCY_SCHEDULER_WALL_ET_TIME_H
