#include "../include/assert_equals.hpp"

/**
 * Static methods should be defined outside the class.
 */

AssertEquals* AssertEquals::instance{nullptr};
std::mutex AssertEquals::mutex;

/**
 * The first time we call GetInstance we will lock the storage location
 *      and then we make sure again that the variable is null and then we
 *      set the value. RU:
 */
AssertEquals *AssertEquals::get_instance() {
    std::lock_guard<std::mutex> lock(AssertEquals::mutex);
    if (AssertEquals::instance == nullptr) {
        instance = new AssertEquals();
    }

    return instance;
}