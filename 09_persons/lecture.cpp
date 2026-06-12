#include "lecture.h"

#include "employee.h"
#include "student.h"


Lecture::Lecture(const std::string &title):
    mTitle(title)  // all other member variables have reasonable defaults
{
}

Lecture::~Lecture()
{
    // We own the lecturer object
    if (mLecturer) delete mLecturer;
    // We also own the student objects
    for (auto *s: mStudents)
        delete s;
    mStudents.clear();
}
