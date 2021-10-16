#include <iostream>
#include "../include/test_suite_writer.hpp"

// Include all source files
// Dynamically write runner.cpp
// Compile run_tests.cpp
// Run run_tests.cpp

using namespace std;

int main(int argc, char** argv) {
	TestSuiteWriter *test_suite_writer = new TestSuiteWriter();
	test_suite_writer->write_test_suite(argv[1]);
	delete test_suite_writer;

	return 0;
}