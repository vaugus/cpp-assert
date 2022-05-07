#ifndef RUNNER_HPP
#define RUNNER_HPP

#include <bits/stdc++.h>
#include <sstream>
#include "constants.hpp"
#include "../types.hpp"

class Runner
{
public:
    void compile(string const &file_name);
    void run();
};

#endif