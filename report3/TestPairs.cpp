//
// Created by godder on 2018/12/28.
//

#include <sstream>
#include "TestPairs.h"

void test::TestPairs::setup() {
    this->pairs = Pairs<int>(20, 30);
}

bool test::TestPairs::testOperatorOut() {
    if (!setupIsRun) {
        this->setup();
        setupIsRun = true;
    }
    stringstream sstream;
    sstream << this->pairs;
    if (sstream.str() == "20 30") {
        return true;
    }
    return false;
}

bool test::TestPairs::testOperatorIn() {
    if (!setupIsRun) {
        this->setup();
        setupIsRun = true;
    }
    // normal input test
    bool normal = false;
    try {
        stringstream sstream;
        sstream.str("40 50");
        sstream>>pairs;
        sstream.str("");
        sstream.clear();
        sstream << pairs;
        if (sstream.str() == "40 50") {
            normal = true;
        }
    } catch (int e) {
        return false;
    }

    // exception input test
    bool exception = false;
    try {
        stringstream sstream;
        sstream.str("a 50");
        sstream>>pairs;
    } catch (int e) {
        if (e == 0) {
            exception = true;
        }
    }
    setupIsRun = false;
    return normal & exception;
}

bool test::TestPairs::testOperatorEq() {
    if (!setupIsRun) {
        this->setup();
        setupIsRun = true;
    }
    Pairs<int> other = Pairs<int>(20, 30);
    return pairs == other;
}

bool test::TestPairs::testOperatorRe() {
    if (!setupIsRun) {
        this->setup();
        setupIsRun = true;
    }
    Pairs<int> other = Pairs<int>(40, 30);
    return pairs < other;
}

test::TestPairs::TestPairs() {
    std::cout<<"begin unit test Pairs ......" << endl;
    int success = 0;
    int fail = 0;

    std::cout<<"test operator <<: ";
    if (this->testOperatorOut()) {
        std::cout<<"success!"<<endl;
        success++;
    } else {
        std::cout<<"fail!"<<endl;
        fail++;
    }
    std::cout<<"test operator >>: ";
    if (this->testOperatorIn()) {
        std::cout<<"success!"<<endl;
        success++;
    } else {
        std::cout<<"fail!"<<endl;
        fail++;
    }
    std::cout<<"test operator ==: ";
    if (this->testOperatorEq()) {
        std::cout<<"success!"<<endl;
        success++;
    } else {
        std::cout<<"fail!"<<endl;
        fail++;
    }
    std::cout<<"test operator <: ";
    if (this->testOperatorRe()) {
        std::cout<<"success!"<<endl;
        success++;
    } else {
        std::cout<<"fail!"<<endl;
        fail++;
    }
    std::cout<<"test finish. success: " << success << " fail: " << fail << endl;
}
