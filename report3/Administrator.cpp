//
// Created by godder on 2018/12/28.
//

#include "Administrator.h"

employeessavitch::Administrator::Administrator() {}

employeessavitch::Administrator::Administrator(const string &name, const string &ssn, double salary, double salary1,
                                               const string &title, const string &area, const string &supervisor)
        : SalariedEmployee(name, ssn, salary), salary(salary1), title(title), area(area), supervisor(supervisor) {}

employeessavitch::Administrator::Administrator(double salary, const string &title, const string &area,
                                               const string &supervisor) {

}

employeessavitch::Administrator::Administrator(double salary, double salary1, const string &title, const string &area,
                                               const string &supervisor) : SalariedEmployee(salary), salary(salary1),
                                                                           title(title), area(area),
                                                                           supervisor(supervisor) {}

double employeessavitch::Administrator::getSalary() const {
    return salary;
}

void employeessavitch::Administrator::setSalary(double salary) {
    Administrator::salary = salary;
}

const string &employeessavitch::Administrator::getTitle() const {
    return title;
}

void employeessavitch::Administrator::setTitle(const string &title) {
    Administrator::title = title;
}

const string &employeessavitch::Administrator::getArea() const {
    return area;
}

void employeessavitch::Administrator::setArea(const string &area) {
    Administrator::area = area;
}

const string &employeessavitch::Administrator::getSupervisor() const {
    return supervisor;
}

void employeessavitch::Administrator::setSupervisor(const string &supervisor) {
    Administrator::supervisor = supervisor;
}

ostream &employeessavitch::operator<<(ostream &os, const employeessavitch::Administrator &administrator) {
    os << static_cast<const SalariedEmployee &>(administrator) << " salary: " << administrator.salary << " title: "
       << administrator.title << " area: " << administrator.area << " supervisor: " << administrator.supervisor;
    return os;
}

istream &employeessavitch::operator>>(istream &is, employeessavitch::Administrator &administrator) {
    is >> administrator.salary;
    if (!is) {
        std::cerr << "wrong input at index of 0" << endl;
        throw 0;
    }
    is >> administrator.title;
    if (!is) {
        std::cerr << "wrong input at index of 1" << endl;
        throw 1;
    }
    is >> administrator.area;
    if (!is) {
        std::cerr << "wrong input at index of 2" << endl;
        throw 2;
    }
    is >> administrator.supervisor;
    if (!is) {
        std::cerr << "wrong input at index of 3" << endl;
        throw 3;
    }
    return is;
}

void employeessavitch::Administrator::print_check() const {
    using namespace std;
    cout << *this << endl;
}




