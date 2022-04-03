#include "../test/assert_test.cpp"
#include "../test/unit_test_factory_test.cpp"
#include "../test/test_suite_writer_test.cpp"
#include <dirent.h>
#include "../include/assert.hpp"
#include "../include/test_suite_writer.hpp"
#include "../include/unit_test.hpp"
#include "../include/unit_test_factory.hpp"

int main()
{
    TestSuiteWriter *writer = new TestSuiteWriter();
    Assert *assertion = Assert::get_instance();

    for (auto unit_test_header : writer->get_unit_test_source_files("test"))
    {
        const std::string header = writer->parse_header(unit_test_header);
        UnitTest *unit_test = UnitTestFactory::create(header);
        unit_test->run(assertion);
        assertion->show_statistics();
    }

    return 0;
}
