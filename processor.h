#ifndef PROCESSOR_H
#define PROCESSOR_H
#include <iostream>

enum ProcessorType
{
    x86=86,
    x64=64
};

class IProcessor
{
public:
     IProcessor() = default;
     virtual std::string getProcessorInfo() = 0;    // возращает строку с перечислением всех характеристик процессора.
     virtual void setProcessor(std::string version, ProcessorType type, double speed) = 0; // устанавливает характеристики
     virtual ~IProcessor() = default;
 };

#endif // PROCESSOR_H
