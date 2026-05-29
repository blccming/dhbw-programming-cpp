#include "student.h"

#include <iostream>
#include <ostream>


Student::Student(const std::string &name):
    Student(name, "") // call the more specific constructor with "unknown" course name
{
}

Student::Student(const std::string &name, const std::string &course):
    // Call the protected constructor of superclass Person
    Person(name), mCourse(course)
{
    std::cout << "[Student] " << mName << " constructed." << std::endl;
}

Student::~Student() {
    std::cout << "[Student] " << mName << " denstructed." << std::endl;
}

std::string Student::getPersonType() const {
    return "Student";
}

void Student::print(std::ostream &out) const {
    Person::print(out); // Call print in superclass Person
    out << ", Course: " << mCourse;
}
