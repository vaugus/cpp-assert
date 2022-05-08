#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <iostream>
#include <mutex>
#include "../types.hpp"

class Scanner
{
private:
    static Scanner *instance;
    static std::mutex mutex;
    vector<string> unit_test_headers;

    Scanner();
    ~Scanner();
public:
    Scanner(Scanner &other) = delete;
    void operator=(const Scanner &) = delete;
    static Scanner *get_instance();

    vector<string> scan_test_folder();
    string parse_header(string const &unit_test_header);
};

#endif