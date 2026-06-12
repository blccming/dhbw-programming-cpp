#pragma once

#include <list>
#include <string>
#include <vector>

// Forward declaration of class Employee.
// It must be defined somewhere else.
class Employee;
class Student;


class Lecture
{
    public:
        // Define a new type StudentList
        typedef std::list<Student*> StudentList;
        // typedef std::vector<Student*> StudentList;

        explicit Lecture(const std::string &title);
        ~Lecture();

        // For non-const pointers to Lecture, return a pointer
        // that allows to modify the lecturer.
        Employee *getLecturer() {
            return mLecturer;
        }
        // For const pointers to Lecture, return a const pointer
        // that does *not* allow to modify the lecturer.
        const Employee *getLecturer() const {
            return mLecturer;
        }
        // Set the lecturor non-const for later modification
        void setLecturer(Employee *lecturer) {
            mLecturer = lecturer;
        }

        StudentList getStudents() {
            return mStudents;
        }
        void addStudent(Student *student) {
            // mStudents is a list, we have include <list>, so we can call push_back
            // Student is used as a pointer only, so the forward declaration is sufficient.
            // Note that we cannot call any methods on Student without including "student.h"
            mStudents.push_back(student);
        }

    private:
        // For an object we need to include the class definition above.
        std::string mTitle;
        // For a pointer a forward declaration is sufficent.
        Employee *mLecturer = 0;
        StudentList mStudents;
};
