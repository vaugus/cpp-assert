#include <iostream>
#include <cstdio>
#include <string>

#ifndef ASSERT_EQUALS_HPP
#define ASSERT_EQUALS_HPP

/**
 * Header file with a class for a simple assertion API.
 *
 * @author Victor Augusto
 * @version 1.0
 */

class AssertEquals {

    private:
        const char* TESTING = "Testing %s \n";
        // const std::string FAIL = "FAIL at {}: Expected {} but received {}.";
        
        // inline void print_error(const std::string test, const std::string expected, const std::string received) {
        //     cout << std::format(FAIL, "Hello", "world", "something") << std::end;
        // }


    public:
        inline void testing(const char* test) {
            printf(TESTING, test);
        }

        template <typename T, typename U>
        bool assert_equals(T expected, U actual) {
            bool result = expected == actual;

            if (!result) {
                // print_error(test, expected, actual)                
                std::cout << "DEU BOSTA" << std::endl;
            } 
            
            return result;
        }
};

#endif
