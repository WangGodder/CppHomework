//
// Created by godder on 2018/12/28.
//

#ifndef CPPTEST_ADMINISTRATOR_H
#define CPPTEST_ADMINISTRATOR_H

#include <ostream>
#include "SalariedEmployee.h"

namespace employeessavitch
{
    class Administrator : public SalariedEmployee{
    public:
        Administrator();

        Administrator(const string &name, const string &ssn, double salary, double salary1, const string &title,
                      const string &area, const string &supervisor);

        Administrator(double salary, const string &title, const string &area, const string &supervisor);

        Administrator(double salary, double salary1, const string &title, const string &area, const string &supervisor);

        double getSalary() const override;

        void setSalary(double salary) override;

        const string &getTitle() const;

        void setTitle(const string &title);

        const string &getArea() const;

        void setArea(const string &area);

        const string &getSupervisor() const;

        void setSupervisor(const string &supervisor);

        friend ostream &operator<<(ostream &os, const Administrator &administrator);

        friend istream &operator>>(istream &is, Administrator &administrator);

        void print_check() const override;

    protected:
        double salary;  // annual salary
    private:
        string title;
        string area;
        string supervisor;
    };

}


#endif //CPPTEST_ADMINISTRATOR_H
