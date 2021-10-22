#include "../test/unit_test_factory_test.cpp"
#include "../test/test_suite_writer_test.cpp"
#include "../test/assert_equals_test.cpp"
#include <dirent.h>
#include "../include/test_suite_writer.hpp"
#include "../include/unit_test.hpp"
#include "../include/unit_test_factory.hpp"

int main() {
    TestSuiteWriter *writer = new TestSuiteWriter();

    for (auto unit_test_header : writer->get_unit_test_source_files("test")) {
        UnitTest *unit_test = UnitTestFactory::create(unit_test_header);
        unit_test->run();
    }

    return 0;
}
