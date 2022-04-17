#include <iostream>
#include "../include/entity/assert.hpp"
#include "../include/factory/unit_test_factory.hpp"
#include "../include/entity/unit_test.hpp"

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