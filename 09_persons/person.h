// The "classic" way for ensuring that the header file is
// processed only once, even if it is included multiple times.
#ifndef __PERSON_H__   // not define first time
#define __PERSON_H__   // define for later

#include <ostream>
#include <string>

class Person
{
    public:
        // The abstract top-level base class *must* have a virtual
        // destructor that is called, when an object is "deleted".
        virtual ~Person();

        // A "virtual" function can be overridden in derived classes.
        // Based on the actual object type, it is decided at runtime,
        // which print function is executed.
        virtual void print(std::ostream &out) const;

        // Assigning "0" makes getPersonType() a "pure virtual" function.
        // In class Person there is no implementation for getPersonType.
        // Any derived class has to provide its own implementation.
        virtual std::string getPersonType() const = 0;

    // Declaring members as "protected" means, they can be accessed
    // from derived classes that "are a person".
    protected:
        int mId;
        std::string mName;
        std::string mBirthday;

        // We don't want the compiler to use this constructor
        // for implicitly converting any string to a person,
        // but the constructer must be explicitly called by
        // creating an object of type Person.
        explicit Person(const std::string &name);

    // Declaring members as "private" means, they can only be accessed
    // in class Person, not even in derived classes.
    private:
        // A static class member exists only once for class Person
        // and is shared by all objects.
        static int sLastId;
};

std::ostream &operator<<(std::ostream &out, const Person &p);

#endif
