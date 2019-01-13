//
// Created by godder on 2018/12/28.
//

#include "TestArrayFirstIndex.h"

void test::TestArrayFirstIndex::setup() {
    array1 = new int[9] {1, 2, 2, 3, 3, 4, 4, 5, 5};
    array2 = new double[9] {1.0, 2.0, 2.0, 3.0, 3.0, 4.0, 4.0, 5.0, 5.0};
    array3 = new string[9] {"1", "2", "2", "3", "3", "4", "4", "5", "5"};
//    array4 = new Employee[9] {Employee("name", "snn")};
    this->length = 9;
}

bool test::TestArrayFirstIndex::testArrayFirstIndex() {
    if (!this->setupIsRun) {
        setup();
        setupIsRun = true;
    }
    int value1 = 2;
    int value2 = 0;
    bool test1;
    test1 = (1 == arrayFirstIndex<int>(this->array1, this->length, value1)) & (-1 == arrayFirstIndex<int>(this->array1, this->length, value2));

    double value3 = 3;
    double value4 = 0;
    bool test2;
    test2 = (3 == arrayFirstIndex<double>(this->array2, this->length, value3)) & (-1 == arrayFirstIndex<double>(this->array2, this->length, value4));

    string value5 = "4";
    string value6 = "7";
    bool test3;
    test3 = (5 == arrayFirstIndex<string>(this->array3, this->length, value5)) & (-1 == arrayFirstIndex<string>(this->array3, this->length, value6));

    return test1 & test2 & test3;
}

test::TestArrayFirstIndex::TestArrayFirstIndex() {
    cout<<"begin test array first index ..." << endl;
    cout << "test arrayFirstIndex: ";
    if (testArrayFirstIndex()) {
        cout << "success!"<<endl;
    } else {
        cout << "fail!" << endl;
    }
    cout << "test finish." << endl;
}
