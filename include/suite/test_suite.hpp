#ifndef TEST_SUITE_HPP
#define TEST_SUITE_HPP

#include <dirent.h>
#include <fstream>
#include <sstream>
#include <string>
#include "../types.hpp"

class TestSuite
{
private:
    std::ofstream suite_runner;
    std::ifstream base_file;
    void append_header(String header);
public:
    TestSuite();
    ~TestSuite();

    void generate(Vector<String> const &headers);
};

#endif