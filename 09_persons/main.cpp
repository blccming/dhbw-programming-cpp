#include <iostream>
#include <list>

#include "professor.h"
#include "person.h"
#include "student.h"


void testStudents() {
    // ERROR: The constructor "Person" is protected making the
    // class "abstract". We cannot create objects directly.
    // Person p1("Nobody");

    std::cout << std::endl << "STUDENTS" << std::endl;

    Student s1("Hans Klein");
    Student s2("Hugo Gross", "TINF25B3");
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;

    // When the function returns, the variables s1 and s2
    // go out of scope and are destroyed.
    // The destructor is called.
}

void testProfessors() {
    std::cout << std::endl << "PROFESSORS" << std::endl;

    for (int i = 0; i < 3; i++) {
        std::cout << std::endl;
        // Create object of type Professor on the stack
        Professor p1("Martin", 85000);
        p1.setThesisTitle("On Complex Computations");
        std::cout << p1 << std::endl;
        // At the end of each iteration the stack object
        // goes out of scope and is destructed. This means
        // the destructor is called and the stack memory
        // is reused for the next iteratin.
    }
}

void testPersons() {
    std::cout << std::endl << "PERSONS" << std::endl;

    std::list<Person*> persons;

    // Polymorphism: the list of Person* can hold all
    // kinds of persons: Students, Professors, etc.
    Professor *prof = new Professor("Wolfgang", 80000);
    prof->setThesisTitle("Abstract Syntax Tree Analysis");
    persons.push_back(prof);

    persons.push_back(new Student("Herbert", "TINF25B3"));
    persons.push_back(new Student("Kumo", "TINF25B2"));

    // Print all persons on the list
    for (auto *p: persons) {
        std::cout << *p;

        // For professors print thesis title
        // Dynamic cast checks the object type at runtime
        // either returns a valid ponter to the desired subclass
        // or the invalid null-pointer
        Professor *prof = dynamic_cast<Professor*>(p);
        if (prof) {
            std::cout << ", Thesis: " << prof->getThesisTitle();
        }

        std::cout << std::endl;
    }

    // Delete all persons on the list
    for (auto *p: persons) {
        delete p;
    }
    persons.clear();
}

int main() {
    std::cout << "Persons in C++" << std::endl;

    testStudents();
    testProfessors();
    testPersons();

    return 0;
}
