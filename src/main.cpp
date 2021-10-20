#include "../src/constants.cpp"
#include "../include/unit_test_factory.hpp"
#include "../include/unit_test.hpp"

#include <iostream>

using namespace std;

int main() {
    UnitTest *test = UnitTestFactory::create("unit_test_factory_test");
    test->run();
    return 0;
}