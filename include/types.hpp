#ifndef TYPES_HPP
#define TYPES_HPP

#include <map>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

template <typename T>
using Vector = std::vector<T>;

template <typename T>
using vector = std::vector<T>;

using String = std::string;

using string = std::string;

using Entry = fs::directory_entry;

using Directories = fs::recursive_directory_iterator;

using Path = fs::path;

using Replacements = std::map<string, string>;

#endif