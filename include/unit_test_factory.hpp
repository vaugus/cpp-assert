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
        static UnitTest* create(std::string const& type);
};

#endif