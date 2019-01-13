//DISPLAY 10.4 Interface for the Derived Class SalariedEmployee
//This is the header file salariedemployee.h.
//This is the interface for the class SalariedEmployee.
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <string>
#include <ostream>
#include "Employee.h"

using namespace std;

namespace employeessavitch
{

    class SalariedEmployee : public Employee
    {
    public:
//        SalariedEmployee( );
//        SalariedEmployee (string the_name, string the_ssn, double the_weekly_salary);
//        double get_salary( ) const;
//        void set_salary(double new_salary);
//        void print_check( );
        SalariedEmployee();

        SalariedEmployee(const string &name, const string &ssn, double salary);

        SalariedEmployee(double salary);

        virtual double getSalary() const;

        virtual void setSalary(double salary);

        friend ostream &operator<<(ostream &os, const SalariedEmployee &employee);

        void print_check() const override;

    private:
        double salary;//weekly
    };

}//employeessavitch

#endif //SALARIEDEMPLOYEE_H

