#include "../test/assert_equals_test.cpp"
#include "../test/unit_test_factory_test.cpp"
#include "../test/test_suite_writer_test.cpp"
#include <dirent.h>
#include <string>
#include "../include/test_suite_writer.hpp"
#include "../include/unit_test.hpp"
#include "../include/unit_test_factory.hpp"

#include <iostream>

using namespace std;

std::string parse_header(const std::string unit_test_header) {
    const std::string base = unit_test_header.substr(8);
    const int extension_position = base.find(".");

    return base.substr(0, extension_position);
}

int main() {
    TestSuiteWriter *writer = new TestSuiteWriter();

    for (const std::string unit_test_header : writer->get_unit_test_source_files("test")) {
        const std::string header = parse_header(unit_test_header);
        UnitTest *unit_test = UnitTestFactory::create(header);
        unit_test->run();
    }

    return 0;
}
