#ifndef TYPES_HPP
#define TYPES_HPP

#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

template <typename T>
using Vector = std::vector<T>;

using String = std::string;

using Entry = fs::directory_entry;

using Directories = fs::recursive_directory_iterator;

using Path = fs::path;

#endif