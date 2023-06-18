#include "Computer.h"
#include "IOCContainer.h"
#include "AMDProcessor.h"
#include "IntelProcessor.h"
#include "Processor.h"
#include <iostream>
using namespace std;

IOCContainer injector;

// инициализируем ненулевым числом
int IOCContainer::s_nextTypeId = 115094801;

int main()
{
    //------Example #1----------------

    IOCContainer injector; // создаем объект контейнер

    // Регистрируем IProcessor с классом IntelProcessor,
    // т.о. каждый раз запрашивая IProcessor получаем объект IntelProcessor

    injector.RegisterInstance<IProcessor, IntelProcessor>();
    auto intel = injector.GetObject<IProcessor>();  // получили процессор через иок контейнер
    intel->setProcessor("intel i3 3470", x64, 3.6); // установили в него параметры

    Computer computerWithIntel(intel); // создали объект компьютер и установили в него процессор интел
    cout << computerWithIntel.getProcessor() << endl; // вывели информацию о процессоре


    //------Example #2----------------

    injector.RegisterInstance<IProcessor, AMDProcessor>();
    auto amd = injector.GetObject<IProcessor>();
    amd->setProcessor("ryzen 5 2600", x86, 3.9);

    Computer computerWithAMD(amd);
    cout << computerWithAMD.getProcessor() << endl;

    return 0;
}
