
#ifndef BOOTSTRAP_CONSTANTS_HPP
#define BOOTSTRAP_CONSTANTS_HPP

#include <string>

namespace BootstrapConstants
{
    const std::string TEST_FOLDER = "test/";
    const std::string RUN_TESTS_FILE = "runners/run_tests.cpp";
    const std::string TEST_SUITE_BASE_FILE = "boilerplates/test_suite_base.cpp";

    const std::string FACTORY_FILE = "src/factory/unit_test_factory.cpp";
    const std::string TEST_FACTORY_BASE_FILE = "boilerplates/unit_test_factory_base.cpp";

    const std::string CONSTRUCTOR_MAP_ENTRY = "{ name , []() -> UnitTest* { return new constructor } }";

    const std::string MAKE = "make ";
}

#endif