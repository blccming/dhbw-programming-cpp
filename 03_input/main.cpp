#include <iostream>
// #include <limits>
#include <string>

int main () {
    // Create variable of type "std::string"
    // The class "string" is defined in include file <string>
    std::string lastname, givenname;
    int age;

    std::cout << std::endl;
    std::cout << "Please enter your last name: ";
    std::cin >> lastname; // Read from console and store into variable
    // The input operator >> reads one token terminated by whitespace

    // Skip anything still stored in our stream, e.g. the trailing "\n"
    std::cin.ignore(1000, '\n');
    // purest form:     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Please enter your given name(s): ";
    // Read one full line
    std::getline(std::cin, givenname);

    std::cout << "Please enter your age: ";
    std::cin >> age;

    std::cout << std::endl;
    std::cout << "Your name is: " << givenname << ' ' << lastname << std::endl;
    std::cout << "Your age is: " << age << std::endl;

    return 0;
}
