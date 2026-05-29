// First: include the header file for this source file.
#include "person.h"

#include <iostream>

Person::Person(const std::string &name):
    mName(name)
{
    std::cout << "[Person] " << mName << " constructed." << std::endl;
}

Person::~Person() {
    std::cout << "[Person] " << mName << " destructed." << std::endl;
}

void Person::print(std::ostream &out) const {
    out << getPersonType() << ": " << mName;
}

std::ostream &operator<<(std::ostream &out, const Person &p) {
    // We have a reference to a Person object, so we can
    // call the virtual function print() on it.
    // If the object is actuall a Student, the runtime ensures
    // that the proper functin Student::print() is called.
    p.print(out);
    return out;
}
