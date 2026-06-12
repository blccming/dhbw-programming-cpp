#pragma once

#include "person.h"

class Employee : public Person
{
    public:
        // Override virtual destructor of superclass.
        ~Employee() override;

        // For convenience we define this getter function
        // in the header file.
        int getSalary() const {
            return mSalary;
        }

        // The pure virtual function getPersonType() is not overridden,
        // so the class Employee is abstract. We cannot create objects
        // of type Employee directly.

        void print(std::ostream &out) const override;

    protected:
        // Employee is abstract, so we define the constructor protected.
        Employee(const std::string &name, int salary);

    private:
        // This private member variable can only be accessed in
        // class Employee, but *not* in derived classes.
        int mSalary;
};
