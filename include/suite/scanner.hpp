#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <iostream>
#include "../types.hpp"

class Scanner
{
private:
    vector<string> unit_test_headers;

public:
    vector<string> scan_test_folder();
    string parse_header(string const &unit_test_header);
};

#endif