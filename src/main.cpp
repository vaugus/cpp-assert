#include "../include/core/assert.hpp"
#include "../include/core/unit_test.hpp"
#include "../include/factory/unit_test_factory.hpp"
#include "../include/core/scanner.hpp"

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	Assert *assertion = Assert::get_instance();
	UnitTest *test = UnitTestFactory::create("assert_test");
	test->run(assertion);
	assertion->show_statistics();

	return 0;
}
