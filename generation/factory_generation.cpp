#include <iostream>
#include "../include/generator/factory_generator.hpp"

int main(int argc, char **argv)
{
    int removal_status = std::remove("runners/unit_test_factory.cpp");

    if (removal_status == 0) {
        std::cout << "Previous runner removed." << std::endl;
    } else {
        std::cout << "Previous runner not removed." << std::endl;
    }

    FactoryGenerator *factory = new FactoryGenerator();

    const std::vector<std::string> headers = {
        "assert_test",
        "another_test"};

    factory->generate(headers);

    delete factory;

    // int status = std::remove("runners/run_tests.cpp");
    // std::cout << status << std::endl;

    return 0;
}