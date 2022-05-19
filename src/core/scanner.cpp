
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

    return tests;
}