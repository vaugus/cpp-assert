#ifndef UTILS_HPP
#define UTILS_HPP

#include <bits/stdc++.h>
#include <string>
#include <sstream>
#include <iostream>
#include <regex>
#include "types.hpp"

namespace Util
{
    static string create_include_path(std::string base_header) {
        std::stringstream include_path;
        include_path << "../include/" << base_header << ".hpp";
        return include_path.str();
    }

    static string create_include_statement(std::string base_header)
    {
        std::stringstream include;
        include << "#include \"" << create_include_path(base_header) << "\n";
        return include.str();
    }

    static string double_quote(const std::string header) 
    {
        std::stringstream result;
        result << "\"" << header << "\"";
        return result.str();
    }

    static string indent(string text, int tabs)
    {
        std::stringstream indented_text;

        for (int i = 0; i < tabs; i++)
        {
            indented_text << "\t";
        }

        indented_text << text;
        return indented_text.str();

    }

    static string concat(string text, string concatenation)
    {
        std::stringstream result;
        result << concatenation;
        return result.str();
    }

    static void write_includes(vector<string> const& base_headers, std::ostream & stream)
    {
        string include_statement = "";
        for (const string base : base_headers)
        {
            include_statement = create_include_statement(base);
            stream << include_statement;
        }
    }

    static void write_line(std::ostream & output_stream, string line)
    {
        output_stream << line << "\n";
    }

    static void copy_lines(std::ostream & output_stream, std::ifstream & input_stream, int number_of_lines)
    {
        string line;
        for (int i = 0; i < number_of_lines; i++)
        {
            std::getline(input_stream, line);
            write_line(output_stream, line);
        }
    }


    static void write_remaining_lines(std::ostream & output_stream, std::ifstream & input_stream)
    {
        for (string line; std::getline(input_stream, line);)
        {
            write_line(output_stream, line);
        }
    }

    static string replace_substring(string pattern, string target, string replacement)
    {
        return std::regex_replace(pattern, std::regex(target), replacement);
    }

    static string replace_substrings(string pattern, Replacements replacements) {
        string result = pattern;

        for (auto const& [key, val] : replacements) {
            result = replace_substring(result, key, val);
        }

        return result;
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