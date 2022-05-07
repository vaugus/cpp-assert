#ifndef UNIT_TEST_HPP
#define UNIT_TEST_HPP

#include "assert.hpp"

class UnitTest
{
public:
    virtual void run() = 0;
    virtual std::string get_test_name() = 0;
};


#endif