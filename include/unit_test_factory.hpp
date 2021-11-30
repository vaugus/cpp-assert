#ifndef UNIT_TEST_FACTORY_HPP
#define UNIT_TEST_FACTORY_HPP

#include <string>
#include "unit_test.hpp"

class UnitTestFactory {
    public:
        static UnitTest* create(std::string const& type);
};

#endif