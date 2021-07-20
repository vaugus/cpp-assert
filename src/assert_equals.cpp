#include "../include/assert_equals.hpp"
#include <iostream>

template <typename T, typename U>
bool AssertEquals::assert_equals(T expected, U actual) {
    bool result = expected == actual;

    if (!result) {
        std::cout << "não" << std::endl;
    } 
    
    return result;
}