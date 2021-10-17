#ifndef UNIT_TEST_HPP
#define UNIT_TEST_HPP

#include <string>

class UnitTest {
    public:
        static UnitTest* create(std::string const& type);
        virtual void run() = 0;
        virtual std::string get_test_name() = 0;
};

#endif