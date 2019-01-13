//
// Created by godder on 2018/12/28.
//

#ifndef CPPTEST_TESTARRAYFIRSTINDEX_H
#define CPPTEST_TESTARRAYFIRSTINDEX_H

#include "ArrayFirstIndex.h"
#include "Employee.h"
using namespace employeessavitch;
namespace test
{
    /**
     * unit test of arrayFirstIndex method
     */
    class TestArrayFirstIndex {
    private:
        int * array1;
        double * array2;
        string * array3;
        bool setupIsRun = false;
        int length;
    public:
        void setup();
        bool testArrayFirstIndex();

        TestArrayFirstIndex();
    };

}


#endif //CPPTEST_TESTARRAYFIRSTINDEX_H
