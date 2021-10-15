#include "../include/util.hpp"

std::vector<std::string> Util::get_unit_test_source_files(std::string const& directory) {
    // opendir requires a const char*
    const char* folder_name = directory.c_str();

    std::vector<std::string> headers_to_include;

    if (auto dir = opendir(folder_name)) {
        while (auto file = readdir(dir)) {
            // Skip everything that starts with a dot.
            if (!file->d_name || file->d_name[0] == '.') {
                continue;
            }
            
            headers_to_include.push_back(file->d_name);
            printf("File: %s\n", file->d_name);
        }
        closedir(dir);
    }

    return headers_to_include;
}
