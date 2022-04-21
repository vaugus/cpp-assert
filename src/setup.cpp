#include "../include/core/assert.hpp"
#include "../include/core/unit_test.hpp"
#include "../include/factory/unit_test_factory.hpp"
#include "../include/bootstrap/factory.hpp"
#include "../include/bootstrap/executor.hpp"
#include "../include/core/scanner.hpp"
#include "../include/types.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    Scanner *scanner = new Scanner();
    vector<string> tests = scanner->scan_test_folder();

    if (std::remove("src/factory/unit_test_factory.cpp") == 0) {
        std::cout << "Previous factory removed." << std::endl;
    } else {
        std::cout << "Previous factory not removed." << std::endl;
    }

    FactoryBootstrap *factory = new FactoryBootstrap();

    factory->generate(tests);

    BoostrapExecutor *executor = new BoostrapExecutor();
    executor->compile("unit_test_factory.o");

    return 0;
}