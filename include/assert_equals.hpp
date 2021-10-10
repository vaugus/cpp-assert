#include <iostream>
#include <mutex>
#include <string>
#include <thread>

#ifndef ASSERT_EQUALS_HPP
#define ASSERT_EQUALS_HPP

/**
 * Header file with a class for a simple assertion API.
 *
 * @author Victor Augusto
 * @version 1.0
 */

#define RESET       "\033[0m"
#define BLACK       "\033[30m"          /* Black */
#define RED         "\033[31m"          /* Red */
#define GREEN       "\033[32m"          /* Green */
#define YELLOW      "\033[33m"          /* Yellow */
#define BLUE        "\033[34m"          /* Blue */
#define MAGENTA     "\033[35m"          /* Magenta */
#define CYAN        "\033[36m"          /* Cyan */
#define WHITE       "\033[37m"          /* White */
#define BOLDBLACK   "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"   /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"   /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"   /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"   /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"   /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"   /* Bold White */

class AssertEquals {

    private:
        const std::string FAIL[5] = {"FAIL at \"", "\":", "  expected ", " but received ", "."};

        static AssertEquals *instance;
        static std::mutex mutex;

        std::string test_name;
        long assertions;
        long test_count;
        long failures;

        AssertEquals() {
            this->assertions = 0;
            this->test_count = 0;
            this->failures = 0;
            this->test_name = "";
        }

        ~AssertEquals() {}

    public:

        /**
        * Singletons should not be assignable.
        */
        AssertEquals(AssertEquals &other) = delete;
        
        void operator=(const AssertEquals &) = delete;

        /**
         * This is the static method that controls the access to the singleton
         * instance. On the first run, it creates a singleton object and places it
         * into the static field. On subsequent runs, it returns the client existing
         * object stored in the static field.
         */

        static AssertEquals *get_instance();

        template <typename T, typename U>
        inline void print_error(const std::string test, T expected, U received) {
            std::cout << BOLDRED;

            std::cout << FAIL[0]  << test  << FAIL[1] << std::endl;

            std::cout << FAIL[2];
            std::cout << expected;
            std::cout << FAIL[3];
            std::cout << received;
            std::cout << FAIL[4] << std::endl;

            std::cout << RESET << std::endl;
        }

        inline void testing(const std::string test) {
            std::cout << BOLDGREEN << std::endl;
            std::cout << "TESTING \"" << test << "\"\n" << std::endl;
            
            this->test_name = test;
            this->test_count++;
        }

        template <typename T, typename U>
        inline void assert_equals(T expected, U actual) {
            bool result = expected == actual;

            if (!result) {
                print_error(this->test_name, expected, actual);
                this->failures++;
            }

            this->assertions++;
        }

        inline void stats() {
            std::cout << BOLDWHITE;
            std::cout << "Ran " 
                      << this->test_count 
                      << " tests and " 
                      << this->assertions
                      << " assertions." 
                      << std::endl;
            std::cout << this->failures << " failures." << std::endl;
            std::cout << RESET;
        }
};

#endif
