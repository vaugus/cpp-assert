#ifndef COMMAND_PARSER_HPP
#define COMMAND_PARSER_HPP

#include <bits/stdc++.h>
#include "assert.hpp"
#include "scanner.hpp"
#include "runner.hpp"
#include "../types.hpp"

class CommandFacade
{
private:
    void self_test();
    void test();

public:
    void parse(string const& command);
};

#endif