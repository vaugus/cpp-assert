#ifndef RUNNER_HPP
#define RUNNER_HPP

#include <bits/stdc++.h>
#include <sstream>
#include <mutex>
#include <map>
#include "../constants.hpp"
#include "../types.hpp"

using DescriptorMap = std::map<std::string, RunnerDescriptor>;

class Runner
{
private:
    static Runner *instance;
    static std::mutex mutex;

    DescriptorMap descriptors;

    void add_descriptor(RunnerDescriptor descriptor);
    RunnerDescriptor get_descriptor(string const &file_name);

    Runner();
public:
    ~Runner();
    Runner(Runner &other) = delete;
    void operator=(const Runner &) = delete;
    static Runner *get_instance();

    void initialize_descriptor(string const &file_name);
    void write_runnable_test(string const &file_name);
    void compile(string const &file_name);
    void run(string const &file_name);
};

#endif
