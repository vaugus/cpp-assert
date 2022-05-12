
#include "../../include/constants.hpp"
#include "../../include/core/scanner.hpp"
#include "../../include/types.hpp"

Scanner *Scanner::instance{nullptr};
std::mutex Scanner::mutex;

Scanner::Scanner() {}

Scanner::~Scanner() {}

Scanner *Scanner::get_instance()
{
    std::lock_guard<std::mutex> lock(Scanner::mutex);
    if (Scanner::instance == nullptr)
        instance = new Scanner();

    return instance;
}

vector<string> Scanner::scan_test_folder()
{
    Path path = fs::current_path();
    Directories directory_iterator = fs::recursive_directory_iterator(path);

    vector<string> tests;

    for (const Entry &entry : directory_iterator)
    {
        string file = entry.path();
        if (file.find(Constants::TEST_FOLDER) != string::npos)
        {
            tests.push_back(file);
        }
    }

    for (auto test : tests)
    {
        std::cout << parse_header(test) << std::endl;
    }

    return tests;
}

string Scanner::parse_header(string const &unit_test_header)
{
    const int path_prefix = unit_test_header.find(Constants::TEST_FOLDER);
    const string base = unit_test_header.substr(path_prefix + Constants::TEST_FOLDER.length());
    const int extension_position = base.find(".");
    return base.substr(0, extension_position);
}