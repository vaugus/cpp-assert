#include <dirent.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#ifndef TEST_SUITE_WRITER_HPP
#define TEST_SUITE_WRITER_HPP

/**
 * Header file with a class for a simple assertion API.
 *
 * @author Victor Augusto
 * @version 1.0
 */

class TestSuiteWriter {
    public:
        std::vector<std::string> get_unit_test_source_files(std::string const& directory);
        void write_test_suite(std::string const& directory);

};

#endif