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