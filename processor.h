#ifndef PROCESSOR_H
#define PROCESSOR_H
#include <iostream>
#include <string>
using namespace std;

enum ProcessorType
{
    x86=86,
    x64=64
};

class IProcessor
{
public:
     virtual string getProcessor() = 0;
     virtual void setProcessor(string version, ProcessorType type, double speed) = 0;
 };

class IntelProcessor: public IProcessor
{
     string Version;
     ProcessorType Type;
     double Speed;

public:

     IntelProcessor() {}
     void setProcessor(string version, ProcessorType type, double speed)
     {
         Version = version;
         Type = type;
         Speed = speed;
     }
     string getProcessor()
     {
         return "processor Intel, version: " + Version + ", type: " + to_string(Type) + ", speed: " + to_string(Speed);
     }

     ~IntelProcessor() {}
 };

class AMDProcessor: public IProcessor
{
     string Version;
     ProcessorType Type;
     double Speed;

public:
     AMDProcessor() {}
     void setProcessor(string version, ProcessorType type, double speed)
     {
         Version = version;
         Type = type;
         Speed = speed;
     }

    string getProcessor()
    {
        return "processor AMD, version: " + Version + ", type: " + to_string(Type) + ", speed: " + to_string(Speed);
    }

    ~AMDProcessor() {}
 };

#endif // PROCESSOR_H
