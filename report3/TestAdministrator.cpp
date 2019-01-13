//
// Created by godder on 2018/12/28.
//

#include <sstream>
#include <fstream>
#include "TestAdministrator.h"

void test::TestAdministrator::setup() {
    this->administrator = Administrator("name", "ssn", 20.1, 40.2, "title", "area", "supervisor");
    administrator.setNet_pay(0);
    this->str = "name: name ssn: ssn net_pay: 0 salary: 20.1 salary: 40.2 title: title area: area supervisor: supervisor";
}

bool test::TestAdministrator::testOperatorOut() {
    if (!setupIsRun) {
        this->setup();
        setupIsRun = true;
    }
    stringstream sstream;
    sstream<<this->administrator;

    return sstream.str() == this->str;
}

bool test::TestAdministrator::testOperatorIn() {
    if (!setupIsRun) {
        this->setup();
        setupIsRun = true;
    }
    stringstream sstream;
    // legal input
    bool legal = false;
    string input = "90.32 titleTest areaTest supervisorTest";
    try {
        sstream.str(input);
        sstream >> administrator;
        sstream.str("");
        sstream.clear();
        sstream << this->administrator;
        legal = sstream.str() == "name: name ssn: ssn net_pay: 0 salary: 20.1 salary: 90.32 title: titleTest area: areaTest supervisor: supervisorTest";
    } catch (int index) {

    }

    // illegal input
    bool illegal = false;
    input = "wrong titleTest areaTest supervisorTest";
    try {
        sstream.str(input);
        sstream >> administrator;
    } catch (int index) {
        illegal = index == 0;
    }
    this->setupIsRun = false;
    return legal & illegal;
}

bool test::TestAdministrator::testPrintCheck() {
    if (!setupIsRun) {
        this->setup();
        setupIsRun = true;
    }
    ifstream fin;
    ofstream fout;
    streambuf * backup;
    backup = std::cout.rdbuf();
    fout.open(this->testFile);
    cout.rdbuf(fout.rdbuf());
    administrator.print_check();
    cout.rdbuf(backup);
    fout.close();
    fin.open(this->testFile);
    char buffer[256];
    fin.getline(buffer, this->str.length() + 1);
    string readStr = string(buffer);
    readStr.resize(this->str.length());
    fin.close();
    return this->str == readStr;
}

test::TestAdministrator::TestAdministrator() {
    cout << "begin unit test on class Administrator ...." << endl;
    int success = 0;
    int fail = 0;

    cout << "test operator << :";
    if (this->testOperatorOut()) {
        cout << "success!" << endl;
        success++;
    } else {
        cout << "fail!"<<endl;
        fail++;
    }

    cout << "test operator >> :";
    if (this->testOperatorIn()) {
        cout << "success!" << endl;
        success++;
    } else {
        cout << "fail!"<<endl;
        fail++;
    }

    cout << "test print check: ";
    if (this->testPrintCheck()) {
        cout << "success!"<<endl;
        success++;
    } else {
        cout << "fail!" <<endl;
        fail++;
    }

    cout << "test finish: success:" << success << " fail:" << fail <<endl;

}
