#include <iostream>
#include "../include/assert_equals.hpp"
#include "../include/unit_test.hpp"

class AssertEqualsTest : public UnitTest {
    public:
        void run() {
            AssertEquals *equals = AssertEquals::get_instance();

            equals->assert_equals(1, equals->get_assertions());
            equals->assert_equals(0, equals->get_test_count());
            equals->assert_equals(0, equals->get_failures());
            equals->assert_equals("", equals->get_test_name());

            equals->testing("A very simple test");
            equals->assert_equals(1, 1);
            equals->assert_equals(1, 3);
            
            equals->testing("Another very simple test");
            equals->assert_equals(1, 2);
            equals->assert_equals(2, 2);
            equals->assert_equals(4, 2);

            equals->testing("Testing the equality of strings");
            equals->assert_equals("foo", "foao");
            equals->assert_equals("foo", "bar");
            equals->assert_equals("bar", "bar");

            equals->testing("Testing the equality of booleans");
            equals->assert_equals(false, false);
            equals->assert_equals(true, true);
            equals->assert_equals(false , true);

            equals->testing("Testing the equality of double");
            equals->assert_equals(2.0, 2.0);
            equals->assert_equals(1.0, 2.0);
            equals->assert_equals(3.0, 3.00);

            equals->stats();
        }

        std::string get_test_name() {
            return "assert_equals_test";
        }
};