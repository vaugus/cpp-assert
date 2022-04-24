#ifndef TEST_FACTORY_GENERATOR_HPP
#define TEST_FACTORY_GENERATOR_HPP

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

using ConstructorMap = std::map<std::string, std::function<UnitTest*()>>;

class FactoryGenerator
{
private:
    std::ifstream base_file;
    std::ofstream runner;
    ConstructorMap create_constructor_map(Vector<String> const &headers);
public:
    FactoryGenerator();
    ~FactoryGenerator();

    void generate(Vector<String> const &headers);
};

#endif