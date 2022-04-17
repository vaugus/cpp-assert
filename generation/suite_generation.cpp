#include <iostream>
#include "../include/generator/suite_generator.hpp"

// Include all source files
// Dynamically write runner.cpp
// Compile run_tests.cpp
// Run run_tests.cpp

int main(int argc, char **argv)
{
    int removal_status = std::remove("runners/run_tests.cpp");

    if (removal_status == 0) {
        std::cout << "Previous runner removed." << std::endl;
    } else {
        std::cout << "Previous runner not removed." << std::endl;
    }

    SuiteGenerator *suite = new SuiteGenerator();

    const std::vector<std::string> headers = {
        "assert_test",
        "another_test"
    };

    suite->generate(headers);

    delete suite;

    return 0;
}