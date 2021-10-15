#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "../include/util.hpp"

using namespace std;

void write(std::string const& directory) {

	Util *util = new Util();

	// resulting test runner to be written.
	std::ofstream outfile;

	// append instead of overwrite.
	outfile.open("run_tests.cpp", std::ios_base::app); 

	std::ifstream base_file("src/run_tests_base.cpp");

	for (const std::string header : util->get_unit_test_source_files(directory)) {
		outfile << "#include \"" << header << "\"" << "\n";
	}

	for(std::string line; std::getline(base_file, line);) {
		outfile << line << "\n";
	}

	delete util;
}

	// Include all source files
	// Dynamically write runner.cpp
	// Compile run_tests.cpp
	// Run run_tests.cpp

int main() {
	cout << "ronaldo" << endl;
}