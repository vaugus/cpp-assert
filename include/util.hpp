#ifndef UTILS_HPP
#define UTILS_HPP

#include <bits/stdc++.h>
#include <string>
#include <sstream>
#include <iostream>
#include <regex>
#include <initializer_list>
#include "types.hpp"

namespace Util
{
    static void write_line(std::ostream & output_stream, string line)
    {
        output_stream << line << "\n";
    }

    static string concat(std::initializer_list<string> strings)
    {
        std::stringstream result;
        for (string element: strings)
            result << element;

        return result.str();
    }

    static string parse_header(string const &unit_test_header)
    {
        const string folder = "test/";
        const int path_prefix = unit_test_header.find(folder);
        const string base = unit_test_header.substr(path_prefix + folder.length());
        const int extension_position = base.find(".");
        return base.substr(0, extension_position); 
    }

    static void write_remaining_lines(std::ostream & output_stream, std::ifstream & input_stream)
    {
        for (string line; std::getline(input_stream, line);)
        {
            write_line(output_stream, line);
        }
    }

    static string capitalize_first_letter(string word)
    {
        word[0] = toupper(word[0]);
        return word;
    }

    static vector<string> split(string text, string delimilter = "_")
    {
        vector<string> tokens;
        string token;
        
        int start = 0;
        int end = text.find(delimilter);
        while (end != -1) 
        {
            token = text.substr(start, end - start);
            tokens.push_back(token);
            start = end + delimilter.size();
            end = text.find(delimilter, start);
        }

        token = text.substr(start, end - start);
        tokens.push_back(token);

        return tokens;
    }

    static string constructor_from_file_name(string file_name) {
        std::stringstream constructor;

        for (string word : split(file_name))
        {
            constructor << capitalize_first_letter(word);
        }

        constructor << "();";
        return constructor.str();
    }
}

#endif