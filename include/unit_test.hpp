#ifndef UNIT_TEST_HPP
#define UNIT_TEST_HPP

#include <string>

/**
 * Header file with a class for a simple assertion API.
 *
 * @author Victor Augusto
 * @version 1.0
 */

class UnitTest {
    public:
        virtual void run() = 0;
        static UnitTest* create(std::string const& type);
};

#endif