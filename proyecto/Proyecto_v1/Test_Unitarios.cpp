#include "include/TestFramework.h"

int main()
{
    TestFramework::getInstance().runAllTests();

    return 0;
}

//  make clean; make tests_unitarios; ./tests_unitarios 