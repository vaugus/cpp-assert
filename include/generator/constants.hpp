#include <string>

#ifndef GENERATOR_CONSTANTS_HPP
#define GENERATOR_CONSTANTS_HPP

namespace GeneratorConstants
{
    const std::string TEST_FOLDER = "test/";
    const std::string RUN_TESTS_FILE = "runners/run_tests.cpp";
    const std::string TEST_SUITE_BASE_FILE = "boilerplates/test_suite_base.cpp";

    const std::string FACTORY_FILE = "runners/unit_test_factory.cpp";
    const std::string TEST_FACTORY_BASE_FILE = "boilerplates/unit_test_factory_base.cpp";

    const std::string CONSTRUCTOR_MAP = "ConstructorMap constructor_map = {";
    const std::string CONSTRUCTOR_MAP_ENTRY = "{ name , []() -> UnitTest* { return new constructor } }";
}

#endif