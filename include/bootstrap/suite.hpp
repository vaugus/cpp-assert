#ifndef TEST_SUITE_BOOTSTRAP_HPP
#define TEST_SUITE_BOOTSTRAP_HPP

#include <dirent.h>
#include <fstream>
#include <sstream>
#include <string>
#include "constants.hpp"
#include "../types.hpp"
#include "../util.hpp"

class SuiteBootstrap
{
private:
    std::ifstream base_file;
    std::ofstream output_file;
public:
    SuiteBootstrap();
    ~SuiteBootstrap();

    void generate(Vector<String> const &base_headers);
};

#endif