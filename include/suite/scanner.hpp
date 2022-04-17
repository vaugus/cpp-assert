#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <iostream>
#include "../types.hpp"

class Scanner
{
private:
    Vector<String> unit_test_headers;

public:
    Vector<String> scan_test_folder();
    String parse_header(String const &unit_test_header);
};

#endif