#ifndef TEST_FACTORY_BOOTSTRAP_HPP
#define TEST_FACTORY_BOOTSTRAP_HPP

#include <dirent.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <regex>
#include <cstdio>
#include <functional>
#include <map>
#include "constants.hpp"
#include "../core/unit_test.hpp"
#include "../types.hpp"
#include "../util.hpp"

class FactoryBootstrap
{
private:
    std::ifstream base_file;
    std::ofstream output_file;
    void write_constructor_entries(vector<string> const &headers);
    void close_resources();
public:
    FactoryBootstrap();
    ~FactoryBootstrap();

    void generate(vector<string> const &headers);
};

#endif