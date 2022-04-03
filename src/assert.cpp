#include "../include/assert.hpp"

Assert *Assert::instance{nullptr};
std::mutex Assert::mutex;

Assert::Assert()
{
    this->assertions = 0;
    this->test_count = 0;
    this->failures = 0;
    this->test_name = "";
}

Assert::~Assert() {}

Assert *Assert::get_instance()
{
    std::lock_guard<std::mutex> lock(Assert::mutex);
    if (Assert::instance == nullptr)
    {
        instance = new Assert();
    }

    return instance;
}

void Assert::show_statistics()
{
    std::cout << constants::BOLDWHITE;
    std::cout << "Ran "
              << this->test_count
              << " tests and "
              << this->assertions
              << " assertions."
              << std::endl;
    std::cout << this->failures << " failures." << std::endl;
    std::cout << constants::RESET;
}

void Assert::testing(const std::string test_name)
{
    std::cout << constants::BOLDGREEN << std::endl;
    std::cout << "TESTING ";
    std::cout << "\"" << test_name << "\"\n"
              << std::endl;

    this->test_name = test_name;
    this->test_count++;
}

std::string Assert::get_test_name()
{
    return this->test_name;
}

long Assert::get_assertions()
{
    return this->assertions;
}

long Assert::get_test_count()
{
    return this->test_count;
}

long Assert::get_failures()
{
    return this->failures;
}