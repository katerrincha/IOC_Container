#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include <memory>
#include "Processor.h"
using namespace std;

class Computer
{
    std::shared_ptr<IProcessor> processor;

public:
    Computer(std::shared_ptr<IProcessor> p): processor(p)
    {} // конструктор инициализирует процессор

    string getProcessor()
    {
       return processor->getProcessorInfo();
    }

};

#endif // COMPUTER_H
