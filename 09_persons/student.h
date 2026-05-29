#pragma once

#include "person.h"

class Student : public Person
{
    public:
        explicit Student(const std::string &name);

        // Overloaded constructor, setting name and course
        Student(const std::string &name, const std::string &course);

        // Override virtual destructor from Person
        ~Student() override;

        std::string getPersonType() const override;
        void print(std::ostream &out) const override;

    private:
        std::string mCourse;
        int mGrade;
};
