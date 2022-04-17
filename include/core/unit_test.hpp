#ifndef UNIT_TEST_HPP
#define UNIT_TEST_HPP

#include "assert.hpp"

class UnitTest
{
public:
    static UnitTest *create(std::string const &type);
    virtual void run(Assert *assertion) = 0;
    virtual std::string get_test_name() = 0;
};

#endif