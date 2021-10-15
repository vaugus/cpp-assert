#include <dirent.h>
#include <string>
#include <vector>

#ifndef UTIL_HPP
#define UTIL_HPP

/**
 * Header file with a class for a simple assertion API.
 *
 * @author Victor Augusto
 * @version 1.0
 */

class Util {
    public:
        std::vector<std::string> get_unit_test_source_files(std::string const& directory);
};

#endif