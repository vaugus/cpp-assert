#ifndef TEST_SUITE_WRITER_HPP
#define TEST_SUITE_WRITER_HPP

#include <dirent.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class TestSuiteWriter {
    public:
        std::vector<std::string> get_unit_test_source_files(std::string const& directory);
        void write_test_suite(std::string const& directory);
};

#endif