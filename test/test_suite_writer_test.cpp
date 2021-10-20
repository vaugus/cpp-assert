#include <iostream>
#include "../include/assert_equals.hpp"
#include "../include/test_suite_writer.hpp"
#include "../include/unit_test.hpp"

class TestSuiteWriterTest : public UnitTest {
    public:
        void run() {
            AssertEquals *equals = AssertEquals::get_instance();


            TestSuiteWriter *writer = new TestSuiteWriter();

            equals->testing("Suite writer reads all unit test source files from /test folder.");
            const std::vector<std::string> headers = writer->get_unit_test_source_files("test");

            // unit_test_factory_test.cpp
            // test_suite_writer_test.cpp
            // assert_equals_test.cpp


            equals->stats();
        }

        std::string get_test_name() {
            return "test_suite_writer_test";
        }
};