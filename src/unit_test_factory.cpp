#include "../include/unit_test.hpp"
#include "../include/unit_test_factory.hpp"
#include "core_test.cpp"

template <typename T>
T UnitTestFactory::getUnitTest(std::string const& unit_test) {
    T test_object;

    switch (unit_test) {
        case "core_test":
            test_object = new CoreTest();
            break;
        default:
            // TODO throw exception
            test_object = nullptr;
            break;
    }

    return test_object;
}