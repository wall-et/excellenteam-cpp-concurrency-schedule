//
// Created by alian on 12/17/18.
//

#include <iostream>
#include <stdlib.h>
#include "ITask.h"

//ITask::ITask() {}
ITask::~ITask(){}


//*******************************************


Printer::Printer(unsigned long runDelay) {
    m_timeToNextRun = runDelay;
    srand (time(NULL));
}

Printer::~Printer(){}

void Printer::printType() {
    std::cout << "Printer" << std::endl;
}

unsigned long Printer::getNextRunPeriod() {
    anotherRunLogic();
    return m_timeToNextRun;
}

void Printer::run() {
    std::cout << "Printer Task Runing" << std::endl;
}

void Printer::anotherRunLogic()  {
    m_timeToNextRun*= rand() % 5;//(m_timeToNextRun/1000)
}

//*******************************************

ConnectionTest::ConnectionTest(unsigned long runDelay) {
    m_timeToNextRun = runDelay;
    srand (time(NULL));
}

ConnectionTest::~ConnectionTest(){}

void ConnectionTest::printType()  {
    std::cout << "Connection Test" << std::endl;
}

unsigned long ConnectionTest::getNextRunPeriod() {
    anotherRunLogic();
    return m_timeToNextRun;
}

void ConnectionTest::run() {
    std::cout << "ConnectionTest Task Runing" << std::endl;
}

void ConnectionTest::anotherRunLogic()  {
    m_timeToNextRun*= rand() % 5;
}

//********************************************

AntiVirus::~AntiVirus(){}

void AntiVirus::printType()  {
    std::cout << "AntiVirus" << std::endl;
}

AntiVirus::AntiVirus(unsigned long runDelay) {
    m_timeToNextRun = runDelay;
    srand (time(NULL));
}

unsigned long AntiVirus::getNextRunPeriod() {
    anotherRunLogic();
    return m_timeToNextRun;
}

void AntiVirus::run() {
    std::cout << "AntiVirus Task Runing" << std::endl;
}

void AntiVirus::anotherRunLogic()  {
    m_timeToNextRun*= rand() % 5;
}