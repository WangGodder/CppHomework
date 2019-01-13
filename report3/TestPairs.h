//
// Created by godder on 2018/12/28.
//

#ifndef CPPTEST_TESTPAIRS_H
#define CPPTEST_TESTPAIRS_H

#include <iostream>
#include "Pairs.h"
using namespace std;

namespace test {
    /**
     * the unit test class of class Pairs
     */
    class TestPairs {
    private:
        bool setupIsRun = false;
        Pairs<int> pairs;
    public:
        void setup();
        bool testOperatorOut();
        bool testOperatorIn();
        bool testOperatorEq();
        bool testOperatorRe();

        TestPairs();
    };
}



#endif //CPPTEST_TESTPAIRS_H
