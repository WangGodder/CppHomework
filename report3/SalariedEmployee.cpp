//
// Created by godder on 2018/12/28.
//

#include "SalariedEmployee.h"
#include <iostream>
#include <stdio.h>
#include <sstream>

employeessavitch::SalariedEmployee::SalariedEmployee() {}

employeessavitch::SalariedEmployee::SalariedEmployee(const string &name, const string &ssn, double salary) : Employee(
        name, ssn), salary(salary) {}

employeessavitch::SalariedEmployee::SalariedEmployee(double salary) : salary(salary) {}

double employeessavitch::SalariedEmployee::getSalary() const {
    return salary;
}

void employeessavitch::SalariedEmployee::setSalary(double salary) {
    SalariedEmployee::salary = salary;
}

ostream &employeessavitch::operator<<(ostream &os, const employeessavitch::SalariedEmployee &employee) {
    os << static_cast<const Employee &>(employee) << " salary: " << employee.salary;
    return os;
}

void employeessavitch::SalariedEmployee::print_check() const {
    using namespace std;
    std::cout<<this<<endl;
}


