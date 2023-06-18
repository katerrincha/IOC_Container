#ifndef AMDPROCESSOR_H
#define AMDPROCESSOR_H
#include "iostream"
#include "Processor.h"

class AMDProcessor: public IProcessor
{
     std::string Version;
     ProcessorType Type;
     double Speed;

public:
     void setProcessor(std::string new_version, ProcessorType new_type, double new_speed) override
     {
         Version = new_version;
         Type = new_type;
         Speed = new_speed;
     }

    AMDProcessor() = default;
    ~AMDProcessor() override
    {
        std::cout<<"destructor amd"<< std::endl;
    }

    std::string getProcessorInfo() override
    {
        return "Processor AMD version: " + Version + ", type:  x" + std::to_string(Type) + ", speed: " + std::to_string(Speed);
    }

 };

#endif // AMDPROCESSOR_H
