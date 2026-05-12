#include <iostream>
#include <vector>

int main() {
    std::vector<double> values;

    std::cout << "Please enter a list of positive values, "
        << "end with a negative value" << std::endl;

    double input;
    // Run the input operator while the stream is "true"
    // stream == "true" means there waas no error like EOF (end of file)
    // Also break the loop, if a negative value is entered
    while ((std::cin >> input) && (input >= 0)) {
        // Add last "input" to the back of vector "values"
        values.push_back(input);
    }

    // Compute average of all values in array "values"
    double sum = 0;
    for (int i = 0; i < values.size(); i++) {
        sum += values[i];
    }
    double average = sum / values.size();
    std::cout << "The average value is: " << average << std::endl;

    // Comput the variance of the values
    double variance = 0;
    // Iterate over all values in vector "values"
    // The keyword "auto" is replaced by the compiler with the
    // element type of the vector, in our case "double"
    // For each execution of the loop body, the variable "v"
    // is assigned one value from the vector
    for (auto v : values) {
        double diff = average - v;
        variance += diff * diff;
    }
    variance /= values.size();
    std::cout << "The variance is: " << variance << std::endl;

    return 0;
}
