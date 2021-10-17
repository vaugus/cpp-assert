#include "../include/unit_test_factory.hpp"
#include "../include/unit_test.hpp"

int main() {
    UnitTest *test = UnitTestFactory::create("unit_test_factory_test");
    test->run();
    return 0;
}