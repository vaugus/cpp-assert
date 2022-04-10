
#include "../../include/suite/test_suite.hpp"
#include <iostream>

TestSuite::TestSuite()
{
    this->suite_runner = std::ofstream("build/run_tests.cpp", std::ios_base::app);
    this->base_file = std::ifstream("resources/test_suite_base.cpp");
}

TestSuite::~TestSuite()
{
    if (this->suite_runner.is_open())
    {
        this->suite_runner.close();
    }

    if (this->base_file.is_open())
    {
        this->base_file.close();
    }
}

void TestSuite::append_header(String header)
{
    std::stringstream header_path;
    header_path << "../include/" << header << ".hpp";

    this->suite_runner << "#include \"" << header_path.str() << "\n";
}

void TestSuite::generate(Vector<String> const &headers)
{
    try
    {
        for (const String header : headers)
        {
            append_header(header);
        }

        for (String line; std::getline(base_file, line);)
        {
            this->suite_runner << line << "\n";
        }

        if (suite_runner.is_open())
        {
            suite_runner.close();
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
}
