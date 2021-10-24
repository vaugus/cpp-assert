
#include "../include/test_suite_writer.hpp"

std::vector<std::string> TestSuiteWriter::get_unit_test_source_files(std::string const& directory) {
    // opendir requires a const char*
    const char* folder_name = directory.c_str();

    std::vector<std::string> headers_to_include;

    if (auto dir = opendir(folder_name)) {
        while (auto file = readdir(dir)) {
            std::string file_name(file->d_name);

            if (file_name.find("_test.cpp") != std::string::npos) {
                const std::string path = "../" + directory + "/" + file_name;
                headers_to_include.push_back(path);
            }
        }
        closedir(dir);
    }
   
    return headers_to_include;
}

std::string TestSuiteWriter::parse_header(std::string const& unit_test_header) {
    const std::string base = unit_test_header.substr(8);
    const int extension_position = base.find(".");
    return base.substr(0, extension_position);
}

void TestSuiteWriter::write_test_suite(std::string const& directory) {
	// resulting test runner to be written.
	std::ofstream runner_file;

	// append instead of overwrite.
	runner_file.open("src/run_tests.cpp", std::ios_base::app); 

	std::ifstream base_file("src/run_tests_base.cpp");

	for (const std::string header : get_unit_test_source_files(directory)) {
		runner_file << "#include \"" << header << "\"" << "\n";
	}

	for(std::string line; std::getline(base_file, line);) {
		runner_file << line << "\n";
	}
}