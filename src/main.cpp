#include "../src/constants.cpp"
#include "../include/assert_equals.hpp"
#include "../include/unit_test_factory.hpp"
#include "../include/unit_test.hpp"

#include <iostream>

using namespace std;

int main() {
    AssertEquals *equals = AssertEquals::get_instance();
    UnitTest *test = UnitTestFactory::create("assert_equals_test");
    test->run(equals);
    equals->stats();
    return 0;
}