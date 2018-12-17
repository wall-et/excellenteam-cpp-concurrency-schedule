//
// Created by alian on 12/17/18.
//

#include "task_time.h"

Time::Time(unsigned long deltaTime) {

    clockid_t clk_id = CLOCK_REALTIME;
    clock_gettime(clk_id, &m_time);

    unsigned long temp = deltaTime*1000000 + m_time.tv_nsec;

    m_time.tv_sec += temp / 1000000000;
    m_time.tv_nsec = temp % 1000000000;
}

Time& Time::operator+(unsigned long deltaTime) {

    unsigned long temp = deltaTime*1000000 + m_time.tv_nsec;

    m_time.tv_sec += temp / 1000000000;
    m_time.tv_nsec = temp % 1000000000;

    return *this;
}

bool Time::operator<(Time & other) const {

    if(m_time.tv_sec == other.m_time.tv_sec)
        return m_time.tv_nsec < other.m_time.tv_nsec;

    return m_time.tv_sec < other.m_time.tv_sec;
}

bool Time::operator==(Time & other) const {
    if(m_time.tv_sec == other.m_time.tv_sec && m_time.tv_nsec == other.m_time.tv_nsec)
        return true;
    return false;
}
