#ifndef TEST_FACTORY_HPP
#define TEST_FACTORY_HPP

#include <string>
#include "../core/unit_test.hpp"

class UnitTestFactory
{
public:
    static UnitTest *create(std::string const &type);
};

#endif