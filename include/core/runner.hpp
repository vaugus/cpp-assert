#ifndef RUNNER_HPP
#define RUNNER_HPP

#include <bits/stdc++.h>
#include <sstream>
#include <mutex>
#include "constants.hpp"
#include "../types.hpp"

class Runner
{
private:
    static Runner *instance;
    static std::mutex mutex;

    Runner();
    ~Runner();
public:
    Runner(Runner &other) = delete;
    void operator=(const Runner &) = delete;
    static Runner *get_instance();

    void compile(string const &file_name);
    void run();
};

#endif