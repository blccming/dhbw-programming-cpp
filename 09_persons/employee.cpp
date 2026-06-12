#include "employee.h"

#include <iostream>

Employee::Employee(const std::string &name, int salary):
    Person(name), mSalary(salary)
{
    std::cout << "[Employee] " << mName << " constructed." << std::endl;
}

Employee::~Employee() {
    std::cout << "[Employee] " << mName << " destructed." << std::endl;
}

void Employee::print(std::ostream &out) const
{
    // When overriding a function, it is replaced and not called automatically,
    // but can be called explicitly.
    Person::print(out);
    out << ", Salary: " << mSalary;
}
