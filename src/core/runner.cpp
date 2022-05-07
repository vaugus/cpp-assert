#include "../../include/core/runner.hpp"

void Runner::compile(string const &file_name)
{
    std::stringstream compilation_command;
    compilation_command << CoreConstants::COMPILE_TEST;
    compilation_command << file_name;

    std::cout << "Compiling file using " << compilation_command.str() << std::endl;
    system(compilation_command.str().c_str());
}

void Runner::run()
{
    std::cout << "Running file" << std::endl;
    system("./test_to_run");
    system("rm test_to_run");
}