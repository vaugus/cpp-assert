#ifndef BOOTSTRAP_EXECUTOR_HPP
#define BOOTSTRAP_EXECUTOR_HPP

#include <bits/stdc++.h>
#include <sstream>
#include "constants.hpp"
#include "../types.hpp"

class BoostrapExecutor
{
public:
    void compile(string file);
    void run(string command);
};

#endif