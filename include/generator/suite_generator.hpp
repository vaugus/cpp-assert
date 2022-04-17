#ifndef TEST_SUITE_GENERATOR_HPP
#define TEST_SUITE_GENERATOR_HPP

#include <dirent.h>
#include <fstream>
#include <sstream>
#include <string>
#include "constants.hpp"
#include "../types.hpp"
#include "../util.hpp"

class SuiteGenerator
{
private:
    std::ofstream suite_runner;
    std::ifstream base_file;
public:
    SuiteGenerator();
    ~SuiteGenerator();

    void generate(Vector<String> const &base_headers);
};

#endif