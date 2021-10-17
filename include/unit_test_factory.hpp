#ifndef UNIT_TEST_FACTORY_HPP
#define UNIT_TEST_FACTORY_HPP

#include <string>
#include "unit_test.hpp"

/**
 * Header file with a class for a simple assertion API.
 *
 * @author Victor Augusto
 * @version 1.0
 */

class UnitTestFactory {
    public:
        template <typename T>
        T getUnitTest(std::string const& unit_test);
};

#endif