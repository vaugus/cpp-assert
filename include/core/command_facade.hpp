#ifndef COMMAND_PARSER_HPP
#define COMMAND_PARSER_HPP

#include <map>

#include <bits/stdc++.h>
#include "assert.hpp"
#include "scanner.hpp"
#include "runner.hpp"
#include "../types.hpp"

using CommandMap = std::map<std::string, std::function<void()>>;

class CommandFacade
{
private:
    Assert *assert;
    CommandMap commands;

    void self_test();
    void test();

public:
    CommandFacade();
    std::function<void()> parse(string const &command);
    std::vector<std::string> list_commands();
};

#endif
