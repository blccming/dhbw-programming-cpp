// First: include the header file for this source file.
#include "person.h"

#include <iostream>

// Definition and initialization of static class member
int Person::sLastId = 0;

Person::Person(const std::string &name):
    mId(++sLastId), mName(name)
{
    std::cout << "[Person] " << mName << " constructed." << std::endl;
}

Person::~Person()
{
    std::cout << "[Person] " << mName << " destructed." << std::endl;
}

void Person::print(std::ostream &out) const
{
    out << getPersonType() << '[' << mId << "]: " << mName;
}

std::ostream &operator<<(std::ostream &out, const Person &p) {
    // We have a reference to a Person object, so we can
    // call the vitual function print() on it.
    // If the object is actually a Student, the runtime ensures
    // that the proper function Student::print() is called.
    p.print(out);
    return out;
}
