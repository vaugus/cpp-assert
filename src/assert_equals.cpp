#include "../include/assert_equals.hpp"

AssertEquals* AssertEquals::instance{nullptr};
std::mutex AssertEquals::mutex;

AssertEquals *AssertEquals::get_instance() {
    std::lock_guard<std::mutex> lock(AssertEquals::mutex);
    if (AssertEquals::instance == nullptr) {
        instance = new AssertEquals();
    }

    return instance;
}

std::string AssertEquals::get_test_name() {
    return this->test_name;
}

long AssertEquals::get_assertions() {
    return this->assertions;
}

long AssertEquals::get_test_count() {
    return this->test_count;
}

long AssertEquals::get_failures() {
    return this->failures;
}