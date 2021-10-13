#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

int main() {  
  std::ofstream outfile;
  std::ifstream input("runner.cpp");

  outfile.open("runner_base.cpp", std::ios_base::app); // append instead of overwrite
  outfile << "#include \"cstdio\"" << "\n";

    for( std::string line; std::getline( input, line ); ) {
        outfile << line << "\n";
    }

  return 0;
}