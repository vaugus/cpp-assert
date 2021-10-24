#include <dirent.h>
#include "../include/assert_equals.hpp"
#include "../include/test_suite_writer.hpp"
#include "../include/unit_test.hpp"
#include "../include/unit_test_factory.hpp"

int main() {
    TestSuiteWriter *writer = new TestSuiteWriter();
    AssertEquals *equals = AssertEquals::get_instance();

    for (auto unit_test_header : writer->get_unit_test_source_files("test")) {
        const std::string header = writer->parse_header(unit_test_header);
        UnitTest *unit_test = UnitTestFactory::create(header);
        unit_test->run(equals);
        equals->stats();
    }

    return 0;
}