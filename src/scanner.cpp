
#include "../include/scanner.hpp"
#include "../include/types.hpp"

Vector<String> Scanner::scan_test_folder()
{
    Path path = fs::current_path();
    Directories directory_iterator = fs::recursive_directory_iterator(path);

    Vector<String> tests;

    for (const Entry &entry : directory_iterator)
    {
        String file = entry.path();
        if (file.find("test/") != String::npos)
        {
            tests.push_back(file);
        }
    }

    for (auto test : tests)
    {
        std::cout << test << std::endl;
    }

    std::cout << tests.size() << std::endl;

    return tests;
}

String Scanner::parse_header(String const &unit_test_header)
{
    const String base = unit_test_header.substr(8);
    const int extension_position = base.find(".");
    return base.substr(0, extension_position);
}