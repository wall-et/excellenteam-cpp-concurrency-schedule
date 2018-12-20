//
// Created by alian on 12/17/18.
//
#include <iostream>
#include "task_time.h"

Time::Time(unsigned long deltaTime) {
//    std::cout << "Time::Time()"<< std::endl;
    clockid_t clk_id = CLOCK_REALTIME;
    clock_gettime(clk_id, &m_time);

    unsigned long temp = deltaTime * 1000000 + m_time.tv_nsec;

    m_time.tv_sec += temp / 1000000000;
    m_time.tv_nsec = temp % 1000000000;
}

Time &Time::operator+(unsigned long deltaTime) {

    unsigned long temp = deltaTime * 1000000 + m_time.tv_nsec;

    m_time.tv_sec += temp / 1000000000;
    m_time.tv_nsec = temp % 1000000000;

    return *this;
}

bool Time::operator<(Time &other) const {

    if (m_time.tv_sec == other.m_time.tv_sec)
        return m_time.tv_nsec < other.m_time.tv_nsec;

    return m_time.tv_sec < other.m_time.tv_sec;
}

void Time::sleep() const {
//    std::cout << "Time::sleep()"<< std::endl;
    timespec delta;
    clockid_t clk_id = CLOCK_REALTIME;
    clock_gettime(clk_id, &delta);

    if (m_time.tv_sec < delta.tv_sec || (m_time.tv_sec == delta.tv_sec && m_time.tv_nsec < delta.tv_nsec)){
        std::cout << "Too late. not going to sleep" <<std::endl;
        return;
    }
    delta.tv_sec = m_time.tv_sec - delta.tv_sec - 1;

    unsigned long temp = 1000000000 + m_time.tv_nsec - delta.tv_nsec;
    delta.tv_sec += temp / 1000000000;
    delta.tv_nsec = temp % 1000000000;

    std::cout << "going to sleep for "<< delta.tv_sec << "." << delta.tv_nsec << std::endl;
    nanosleep(&delta,NULL);
}

Time & Time::operator=(unsigned long deltaTime){

    clockid_t clk_id = CLOCK_REALTIME;
    clock_gettime(clk_id, &m_time);

    unsigned long temp = deltaTime * 1000000 + m_time.tv_nsec;

    m_time.tv_nsec = temp % 1000000000;
    m_time.tv_sec += temp / 1000000000;

    return *this;
}

//bool Time::operator==(Time &other) const {
//    if (m_time.tv_sec == other.m_time.tv_sec && m_time.tv_nsec == other.m_time.tv_nsec)
//        return true;
//    return false;
//}

//long Time::operator-(Time &other) const {
//    long delta = (m_time.tv_sec - other.m_time.tv_sec) / 1000;
//    delta = (m_time.tv_nsec - other.m_time.tv_nsec) * 1000000;
//    return delta;
//}
