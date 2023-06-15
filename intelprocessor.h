#ifndef INTELPROCESSOR_H
#define INTELPROCESSOR_H
#include"iostream"
//#include"Processor.h"

class IntelProcessor: public IProcessor
{
     std::string Version;
     ProcessorType Type;
     double Speed;

public:
     void setProcessor(std::string new_version, ProcessorType new_type, double new_speed) override{
         Version = new_version;
         Type = new_type;
         Speed = new_speed;
     }

     IntelProcessor() = default;
     /*~IntelProcessor() override
     {
         std::cout<<"destructor intel"<< std::endl;
     };*/

    std::string getProcessorInfo() override
    {
        return "Processor Intel version: " + Version + ", type:  x" + std::to_string(Type) + ", speed: " + std::to_string(Speed);
    }

 };
#endif // INTELPROCESSOR_H
