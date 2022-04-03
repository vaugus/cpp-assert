#include <iostream>
#include "../include/assert.hpp"
#include "../include/test_suite_writer.hpp"
#include "../include/unit_test.hpp"

class TestSuiteWriterTest : public UnitTest {
    public:
        void run(Assert *assertion) {
            TestSuiteWriter *writer = new TestSuiteWriter();

            assertion->testing("Suite writer reads all unit test source files from /test folder.");
            const std::vector<std::string> headers = writer->get_unit_test_source_files("test");
        }

        std::string get_test_name() {
            return "test_suite_writer_test";
        }
};