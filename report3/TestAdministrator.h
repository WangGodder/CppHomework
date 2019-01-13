//
// Created by godder on 2018/12/28.
//

#ifndef CPPTEST_TESTADMINISTRATOR_H
#define CPPTEST_TESTADMINISTRATOR_H

#include "Administrator.h"

using namespace employeessavitch;
namespace test
{
    /**
     * unit test of class Administrator
     */
    class TestAdministrator {
    private:
        Administrator administrator;
        string str;
        bool setupIsRun = false;
    public:
        const string testFile = "./test.txt";
        void setup();
        bool testOperatorOut();
        bool testOperatorIn();
        bool testPrintCheck();

        TestAdministrator();
    };
}



#endif //CPPTEST_TESTADMINISTRATOR_H
