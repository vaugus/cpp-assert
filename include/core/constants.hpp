#include <string>

#ifndef CORE_CONSTANTS_HPP
#define CORE_CONSTANTS_HPP

namespace CoreConstants
{
    const std::string TEST_FOLDER = "test/";

    const std::string CXX = "g++ -std=c++17";
    const std::string FIND_OBJECTS = "$(find src -type f -name \"*.o\") ";
    const std::string COMPILE_TEST = CXX + " -o test_to_run " + FIND_OBJECTS;

    const std::string RESET = "\033[0m";
    const std::string BOLDRED = "\033[1m\033[31m";
    const std::string BOLDGREEN = "\033[1m\033[32m";
    const std::string BOLDCYAN = "\033[1m\033[36m";
    const std::string BOLDWHITE = "\033[1m\033[37m";

    const std::string RUN_TESTS_FILE = "runners/run_tests.cpp";
    const std::string TEST_SUITE_BASE_FILE = "boilerplates/test_suite_base.cpp";
}

#endif