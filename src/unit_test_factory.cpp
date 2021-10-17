#include "../include/unit_test.hpp"
#include "../include/unit_test_factory.hpp"
#include "../test/core_test.cpp"

UnitTest* UnitTestFactory::create(std::string const& type) {
    if (type == "core_test") {
        return new CoreTest();
    }
    
    // TODO throw exception
    return nullptr;
}