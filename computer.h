#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include <memory>
#include "Processor.h"
using namespace std;

class Computer
{
    IProcessor* processor;

public:
    Computer(IProcessor* p): processor(p) {}
    // конструктор инициализирует процессор

    string getProcessor()
    {
       return processor->getProcessor();
    }
};

#endif // COMPUTER_H
