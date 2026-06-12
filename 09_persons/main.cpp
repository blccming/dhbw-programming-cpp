#include <iostream>
#include <list>

#include "lecture.h"
#include "person.h"
#include "professor.h"
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

    for (int i=0; i<3; i++) {
        std::cout << std::endl;
        // Create object of type Professor on the stack
        Professor p1("Martin", 85000);
        p1.setThesisTitle("On Complex Computations");
        std::cout << p1 << std::endl;
        // At the end of each iteration the stack object
        // goes out of scope and is destructed. This means
        // the destructor is called and the stack memory
        // is reused for the next iteration.
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
    persons.push_back(new Student("Kuno", "TINF25B3"));

    // Print all persons on the list
    for (auto *p: persons) {
        std::cout << *p;
        // For professors, print thesis title
        // We cannot call getThesisTitle() on pointer p,
        // as this method is not defined in class Person, but
        // in class Professor.
        // Dynamic cast checks the object type at runtime and
        // either returns a valid pointer to the desired subclass
        // or the invalid null-pointer.
        Professor *prof = dynamic_cast<Professor*>(p);
        if (prof)
            std::cout << ", Thesis: " << prof->getThesisTitle();
        std::cout << std::endl;
    }

    // Delete all persons on the list
    for (auto *p: persons)
        delete p;
    persons.clear();
}


void testLectures() {

    std::cout << std::endl << "LECTURES" << std::endl;

    Lecture l1("Programming in C++");

    // When passing the pointer to the professor to
    // object l1, we are passing the ownership of
    // the Professor object.
    // That means the object l1 is now responsible
    // for deleting the professor object, when it is
    // no longer needed.
    l1.setLecturer(new Professor("Kurt", 75000));

    // Note that getLecturer() returns a pointer that needs to
    // be dereferenced for using the output operator.
    std::cout << "Lecturer: " << *l1.getLecturer() << std::endl;

    // Add some students, that will also be owned by the lecture object
    l1.addStudent(new Student("John"));
    l1.addStudent(new Student("Mike"));
    l1.addStudent(new Student("Jack"));
    l1.addStudent(new Student("Jenny"));

    // List 1: Using explicit types
    // Use type StudentList from class Lecture, but don't use std::list,
    // so this loop still works, if StudentList is changed to another
    // implementation like std::vector.
    Lecture::StudentList studentList1 = l1.getStudents();
    for (Student *s: studentList1)
        std::cout << *s << std::endl;

    // List 2: using "auto" type
    auto studentList2 = l1.getStudents();
    for (auto *s: studentList2)
        std::cout << *s << std::endl;

    // No List 3
    for (auto *s: l1.getStudents())
        std::cout << *s << std::endl;

    // For fun: printing list1 without using the new for loop
    Lecture::StudentList::iterator it;
    for (it=studentList1.begin(); it!=studentList1.end(); ++it)
        std::cout << **it << std::endl;

    // Test destructor of Lecture null lecturer and empty student list
    Lecture l2("Database Basics");

    // When the function exits, the destructors for l1 and l2 are called.
}


int main() {
    std::cout << "Persons in C++" << std::endl;

    testStudents();
    testProfessors();
    testPersons();
    testLectures();

    return 0;
}
