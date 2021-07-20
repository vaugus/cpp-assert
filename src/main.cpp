#include <iostream>
#include "../include/assert_equals.hpp"

using namespace std;

int main () {
    AssertEquals *equals = new AssertEquals();
    equals->testing("Attempt to make a funny math operation");
    equals->assert_equals(10, 11);
    return 0;
}