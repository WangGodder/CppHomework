//
// Created by godder on 2018/12/28.
//

#include "Employee.h"
#include <iostream>

employeessavitch::Employee::Employee() {}

employeessavitch::Employee::Employee(const string &name, const string &ssn) : name(name), ssn(ssn) {}

const string &employeessavitch::Employee::getName() const {
    return name;
}

void employeessavitch::Employee::setName(const string &name) {
    Employee::name = name;
}

const string &employeessavitch::Employee::getSsn() const {
    return ssn;
}

void employeessavitch::Employee::setSsn(const string &ssn) {
    Employee::ssn = ssn;
}

double employeessavitch::Employee::getNet_pay() const {
    return net_pay;
}

void employeessavitch::Employee::setNet_pay(double net_pay) {
    Employee::net_pay = net_pay;
}

ostream &employeessavitch::operator<<(ostream &os, const employeessavitch::Employee &employee) {
    os << "name: " << employee.name << " ssn: " << employee.ssn << " net_pay: " << employee.net_pay;
    return os;
}

void employeessavitch::Employee::print_check() const {
    using namespace std;
    std::cout << *this <<endl;
}

istream &employeessavitch::operator>>(std::istream &is, employeessavitch::Employee &employee) {
    is >> employee.name;
    if (!is) {
        std::cerr<<"wrong input at index of 0"<<endl;
        throw 0;
    }
    is >> employee.ssn;
    if (!is) {
        std::cerr << "wrong input at index of 1" << endl;
        throw 1;
    }

    return is;
}

