#include <iostream>
#include "../include/test_suite.hpp"

// Include all source files
// Dynamically write runner.cpp
// Compile run_tests.cpp
// Run run_tests.cpp

int main(int argc, char **argv)
{
    TestSuite *suite = new TestSuite();

    const std::vector<std::string> headers = {
        "assert_test",
        "test_suite_writer_test",
        "unit_test_factory_test"};

    suite->generate(headers);

    delete suite;

    // int status = std::remove("build/run_tests.cpp");
    // std::cout << status << std::endl;

    return 0;
}