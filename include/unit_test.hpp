#ifndef UNIT_TEST_HPP
#define UNIT_TEST_HPP

/**
 * Header file with a class for a simple assertion API.
 *
 * @author Victor Augusto
 * @version 1.0
 */

class UnitTest {
    public:
        virtual void run() const = 0;
};

#endif