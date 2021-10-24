#include "../include/assert_equals.hpp"
#include "../include/unit_test.hpp"
#include "../include/unit_test_factory.hpp"

class UnitTestFactoryTest : public UnitTest {
    public:
        void run(AssertEquals *equals) {
            equals->stats();

            UnitTest *test = UnitTestFactory::create("assert_equals_test");

            equals->testing("Another very simple test");
            equals->assert_equals("assert_equals_test", test->get_test_name());
        }

        std::string get_test_name() {
            return "unit_test_factory_test";
        }
};