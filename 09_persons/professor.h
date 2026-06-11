#pragma once

#include "employee.h"
class Professor : public Employee {
    public:
        Professor(const std::string &name, int salary);
        ~Professor() override;

        std::string getPersonType() const override;

        // Getter setter methods for thesis title
        const std::string &getThesisTitle() const {
            return mThesisTitle;
        }

        void setThesisTitle(const std::string &title) {
            mThesisTitle = title;
        }

    private:
        // IF the thesis title is not explicitly initialized in a
        // constructor, the default constructor of std::string is
        // called, resulting in an empty string.
        std::string mThesisTitle;
};
