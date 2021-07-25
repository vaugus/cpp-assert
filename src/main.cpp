#include <iostream>
#include "../include/assert_equals.hpp"

using namespace std;

int main () {
    AssertEquals *equals = new AssertEquals();
    equals->testing("Attempt to make a funny math operation");
    equals->assert_equals(1, 1);
    equals->assert_equals(1, 3);
    equals->assert_equals(1, 2);

    delete equals;
    return 0;
}