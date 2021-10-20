#include <dirent.h>
#include <string>
#include <vector>
#include <cstdio>
#include "../include/test_suite_writer.hpp"
#include "../include/unit_test.hpp"

int main() {
    TestSuiteWriter *writer = new TestSuiteWriter();

    for (auto file : writer->get_unit_test_source_files("test")) {
        // UnitTest *unit_test = new UnitTest();
        // file.run();
    }

    return 0;
}