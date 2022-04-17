#include "../include/entity/assert.hpp"
#include "../include/entity/unit_test.hpp"
#include "../include/factory/unit_test_factory.hpp"

class UnitTestFactoryTest : public UnitTest {
    public:
        void run(Assert *assertion) {
            assertion->show_statistics();

            UnitTest *test = UnitTestFactory::create("assert_test");

            assertion->testing("Another very simple test");
            assertion->assert_equals("assert_test", test->get_test_name());
        }

        std::string get_test_name() {
            return "unit_test_factory_test";
        }
};