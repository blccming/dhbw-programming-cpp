#include "professor.h"
#include <iostream>

Professor::Professor(const std::string &name, int salary):
    Employee(name, salary) {
        std::cout << "[Professor] " << mName << " constructed." << std::endl;
    }

Professor::~Professor() {
    std::cout << "[Professor] " << mName << " constructed." << std::endl;

}

std::string Professor::getPersonType() const {
    return "Professor";
}
