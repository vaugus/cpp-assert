#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>
#include <vector>

namespace constants
{
    extern const std::vector<std::string> unit_tests;

    const std::string TEST_FOLDER = "test/";

    const std::string RESET = "\033[0m";
    const std::string BOLDRED = "\033[1m\033[31m";
    const std::string BOLDGREEN = "\033[1m\033[32m";
    const std::string BOLDCYAN = "\033[1m\033[36m";
    const std::string BOLDWHITE = "\033[1m\033[37m";
}

#endif