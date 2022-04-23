
#include "../../include/generator/suite_generator.hpp"
#include <iostream>

SuiteGenerator::SuiteGenerator()
{
    suite_runner = std::ofstream(GeneratorConstants::RUN_TESTS_FILE, std::ios_base::app);
    base_file = std::ifstream(GeneratorConstants::TEST_SUITE_BASE_FILE);
}

SuiteGenerator::~SuiteGenerator()
{
    if (suite_runner.is_open())
    {
        suite_runner.close();
    }

    if (base_file.is_open())
    {
        base_file.close();
    }
}

void SuiteGenerator::generate(Vector<String> const &base_headers)
{
    try
    {
        Util::write_includes(base_headers, suite_runner);
        Util::write_remaining_lines(suite_runner, base_file);

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
