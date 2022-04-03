#include "../src/constants.cpp"
#include "../include/assert.hpp"
#include "../include/unit_test_factory.hpp"
#include "../include/unit_test.hpp"
#include "../include/scanner.hpp"

#include <iostream>

using namespace std;

// ./cpp-assert scan && ./cpp-assert build && ./cpp-assert run

int main(int argc, char** argv)
{
    // Assert *assertion = Assert::get_instance();
    // UnitTest *test = UnitTestFactory::create("assert_test");
    // test->run(assertion);
    // assertion->show_statistics();

    string command = argv[1];
    if (command == "scan") {
        Scanner *scanner = new Scanner();
        scanner->scan_test_folder();
    }

    return 0;
}