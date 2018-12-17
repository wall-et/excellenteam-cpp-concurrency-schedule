//
// Created by alian on 12/17/18.
//

#include <iostream>
#include "ITask.h"

//ITask::ITask() {}
ITask::~ITask(){}

Printer::Printer(unsigned long runDelay) {
    m_timeToNextRun = runDelay;
}

Printer::~Printer(){}

unsigned long Printer::getNextRunPeriod() {
    return m_timeToNextRun;
}

void Printer::run() {
    std::cout << "Printer Task Runing" << std::endl;
}

ConnectionTest::ConnectionTest(unsigned long runDelay) {
    m_timeToNextRun = runDelay;
}

ConnectionTest::~ConnectionTest(){}


unsigned long ConnectionTest::getNextRunPeriod() {
    return m_timeToNextRun;
}

void ConnectionTest::run() {
    std::cout << "ConnectionTest Task Runing" << std::endl;
}

AntiVirus::~AntiVirus(){}

AntiVirus::AntiVirus(unsigned long runDelay) {
    m_timeToNextRun = runDelay;
}

unsigned long AntiVirus::getNextRunPeriod() {
    return m_timeToNextRun;
}

void AntiVirus::run() {
    std::cout << "AntiVirus Task Runing" << std::endl;
}