#include "Computer.h"
#include "IOCContainer.h"
#include "AMDProcessor.h"
#include "IntelProcessor.h"
#include "Processor.h"
#include <iostream>
using namespace std;

// инициализируем ненулевым числом
int IOCContainer::s_nextTypeId = 115094801;

int main()
{
    //------Example #1----------------

    IOCContainer injector; // создаем объект контейнер

    // регистрируем IProcessor с классом IntelProcessor,
    // т.е. каждый раз, запрашивая IProcessor, получаем объект IntelProcessor

    injector.RegisterInstance<IProcessor, IntelProcessor>();
    auto intel = injector.GetObject<IProcessor>();  // получили процессор через иок контейнер
    intel->setProcessor("intel", x64, 3); // установили в него параметры

    Computer computerIntel(intel.get()); // создали объект компьютер и установили в него процессор интел
    cout << computerIntel.getProcessor() << endl; // вывели информацию о процессоре


    //------Example #2----------------

    injector.RegisterInstance<IProcessor, AMDProcessor>();
    auto amd = injector.GetObject<IProcessor>();
    amd->setProcessor("AMD", x86, 4);

    Computer computerAMD(amd.get());
    cout << computerAMD.getProcessor() << endl;

    return 0;
}
