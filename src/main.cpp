#include <iostream>
#include "../include/assert_equals.hpp"

using namespace std;

int main () {
    AssertEquals *equals = AssertEquals::get_instance();
    equals->testing("A very simple test");
    equals->assert_equals(1, 1);
    equals->assert_equals(1, 3);
    equals->testing("Another very simple test");
    equals->assert_equals(1, 2);

    equals->stats();
    return 0;
}