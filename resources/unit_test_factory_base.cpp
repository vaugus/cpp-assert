#include "../include/unit_test.hpp"
#include "../include/unit_test_factory.hpp"

UnitTest *UnitTestFactory::create(std::string const &type)
{


    if (type == "assert_test")
    {
        return new AssertEqualsTest();
    }

    if (type == "unit_test_factory_test")
    {
        return new UnitTestFactoryTest();
    }

    if (type == "test_suite_writer_test")
    {
        return new TestSuiteWriterTest();
    }

    return nullptr;
}