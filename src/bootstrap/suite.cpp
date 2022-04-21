
#include "../../include/bootstrap/suite.hpp"
#include <iostream>

SuiteBootstrap::SuiteBootstrap()
{
    output_file = std::ofstream(BootstrapConstants::RUN_TESTS_FILE, std::ios_base::app);
    base_file = std::ifstream(BootstrapConstants::TEST_SUITE_BASE_FILE);
}

SuiteBootstrap::~SuiteBootstrap()
{
    if (output_file.is_open())
    {
        output_file.close();
    }

    if (base_file.is_open())
    {
        base_file.close();
    }
}

void SuiteBootstrap::generate(Vector<String> const &base_headers)
{
    try
    {
        Util::write_includes(base_headers, output_file);
        Util::write_remaining_lines(output_file, base_file);

        if (output_file.is_open())
        {
            output_file.close();
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
}
