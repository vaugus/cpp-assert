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
        std::string parse_header(std::string const& unit_test_header);
        void write_test_suite(std::string const& directory);
};

#endif