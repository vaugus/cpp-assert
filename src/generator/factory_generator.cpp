#include "../../include/generator/factory_generator.hpp"
#include "../../include/core/unit_test.hpp"

FactoryGenerator::FactoryGenerator()
{
    base_file = std::ifstream(GeneratorConstants::TEST_FACTORY_BASE_FILE);
    runner = std::ofstream(GeneratorConstants::FACTORY_FILE, std::ios_base::app);
}


FactoryGenerator::~FactoryGenerator()
{
    if (runner.is_open())
        runner.close();

    if (base_file.is_open())
        base_file.close();
}

ConstructorMap FactoryGenerator::create_constructor_map(Vector<String> const &base_headers)
{
    
}

void FactoryGenerator::generate(Vector<String> const &base_headers)
{
    try
    {
        Util::write_includes(base_headers, runner);
        Util::copy_lines(runner, base_file, 6);

        for (const string header : base_headers) {
            string pattern = GeneratorConstants::CONSTRUCTOR_MAP_ENTRY;

            Replacements replacements = { 
                { "name",        Util::double_quote(header) },
                { "constructor", Util::constructor_from_file_name(header) }
            };

            const string inline_function = Util::replace_substrings(pattern, replacements);
            Util::write_line(runner, Util::indent(inline_function, 2));
        }

        Util::write_remaining_lines(runner, base_file);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
}