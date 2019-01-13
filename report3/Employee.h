//DISPLAY 10.1 Interface for the Base Class Employee
//This is the header file employee.h.
//This is the interface for the class Employee.
//This is primarily intended to be used as a base class to derive
//classes for different kinds of employees.
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

using namespace std;

namespace employeessavitch
{

    class Employee
    {
    public:
//        Employee( );
//        Employee(string the_name, string the_ssn);
//        string get_name( ) const;
//        string get_ssn( ) const;
//        double get_net_pay( ) const;
//        void set_name(string new_name);
//        void set_ssn(string new_ssn);
//        void set_net_pay(double new_net_pay);
//        void print_check( ) const;
        Employee();

        Employee(const string &name, const string &ssn);

        const string &getName() const;

        void setName(const string &name);

        const string &getSsn() const;

        void setSsn(const string &ssn);

        double getNet_pay() const;

        void setNet_pay(double net_pay);

        virtual void print_check() const;

        friend ostream &operator<<(ostream &os, const Employee &employee);

        friend istream &operator>>(std::istream &is, Employee &employee);

    private:
        string name;
        string ssn;
        double net_pay;
    };

}//employeessavitch

#endif //EMPLOYEE_H

