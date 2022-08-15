#include <algorithm>
#include <iostream>
#include <mutex>
#include <string>
#include <vector>
#include "../constants.hpp"

#ifndef ASSERT_HPP
#define ASSERT_HPP

/**
 * Header file with a class for a simple assertion API.
 *
 * @author Victor Augusto
 * @version 2.0
 */

class Assert
{

private:
    static Assert *instance;
    static std::mutex mutex;

    std::string test_name;
    long assertions;
    long test_count;
    long failures;

    Assert();
    ~Assert();

public:
    Assert(Assert &other) = delete;

    void operator=(const Assert &) = delete;

    static Assert *get_instance();

    void testing(const std::string test_name);
    void show_statistics();
    std::string get_test_name();

    long get_assertions();
    long get_test_count();
    long get_failures();

    template <typename T, typename U>
    inline void assertion_fail(const std::string test, T expected, U received)
    {
        std::cout << Constants::BOLDRED;

        std::cout << "FAIL at " << test << ":" << std::endl;
        std::cout << "expected " << expected;
        std::cout << " but received " << received << std::endl;

        std::cout << Constants::RESET << std::endl;
    }

    template <typename T>
    inline void membership_fail(const std::string test, T expected)
    {
        std::cout << Constants::BOLDRED;

        std::cout << "FAIL at " << test << ":" << std::endl;

        std::cout << "the collection does not contain " << expected;

        std::cout << Constants::RESET << std::endl;
    }

    template <typename T, typename U>
    inline void assert_equals(T expected, U actual)
    {
        bool result = expected == actual;

        if (!result)
        {
            assertion_fail(this->test_name, expected, actual);
            this->failures++;
        }

        this->assertions++;
    }

    template <typename T>
    inline void assert_contains(std::vector<T> collection, T element)
    {

        auto begin = collection.begin();
        auto end = collection.end();
        bool result = std::find(begin, end, element) != end;
        if (!result)
        {
            membership_fail(this->test_name, element);
            this->failures++;
        }

        this->assertions++;
    }
};

#endif