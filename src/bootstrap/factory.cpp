#include "../../include/bootstrap/factory.hpp"
#include "../../include/core/unit_test.hpp"

FactoryBootstrap::FactoryBootstrap()
{
    base_file = std::ifstream(BootstrapConstants::TEST_FACTORY_BASE_FILE);
    output_file = std::ofstream(BootstrapConstants::FACTORY_FILE, std::ios_base::app);
}


FactoryBootstrap::~FactoryBootstrap()
{
    close_resources();
}

void FactoryBootstrap::close_resources()
{
    if (base_file.is_open()) { base_file.close(); }
    if (output_file.is_open()) { output_file.close(); }
}

void FactoryBootstrap::write_constructor_entries(vector<string> const &base_headers)
{
    const int size = base_headers.size();

    for (int i = 0; i < size; i++) 
    {
        string header = base_headers.at(i);
        string pattern = BootstrapConstants::CONSTRUCTOR_MAP_ENTRY;

        Replacements replacements = { 
            { "name",        Util::double_quote(header) },
            { "constructor", Util::constructor_from_file_name(header) }
        };

        const string function = Util::replace_substrings(pattern, replacements);
        const string line = (i + 1) == size ? function : Util::concat(function, ","); 

        Util::write_line(output_file, Util::indent(line, 2));
    }
}

void FactoryBootstrap::generate(vector<string> const &base_headers)
{
    try
    {
        Util::write_includes(base_headers, output_file);
        Util::copy_lines(output_file, base_file, base_headers.size() + 8);
        this->write_constructor_entries(base_headers);
        Util::write_remaining_lines(output_file, base_file);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    close_resources();
}