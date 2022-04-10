
#include "../../include/suite/constants.hpp"
#include "../../include/suite/scanner.hpp"
#include "../../include/types.hpp"

Vector<String> Scanner::scan_test_folder()
{
    Path path = fs::current_path();
    Directories directory_iterator = fs::recursive_directory_iterator(path);

    Vector<String> tests;

    for (const Entry &entry : directory_iterator)
    {
        String file = entry.path();
        if (file.find(SuiteConstants::TEST_FOLDER) != String::npos)
        {
            tests.push_back(file);
        }
    }

    for (auto test : tests)
    {
        std::cout << parse_header(test) << std::endl;
    }

    std::cout << tests.size() << std::endl;

    return tests;
}

String Scanner::parse_header(String const &unit_test_header)
{
    const int path_prefix = unit_test_header.find(SuiteConstants::TEST_FOLDER);
    const String base = unit_test_header.substr(path_prefix + SuiteConstants::TEST_FOLDER.length());
    const int extension_position = base.find(".");
    return base.substr(0, extension_position);
}