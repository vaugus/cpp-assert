#include "../../include/core/runner.hpp"
#include "../../include/util.hpp"

Runner *Runner::instance{nullptr};
std::mutex Runner::mutex;

Runner::Runner() {}
Runner::~Runner() {}

Runner *Runner::get_instance()
{
    std::lock_guard<std::mutex> lock(Runner::mutex);
    if (Runner::instance == nullptr)
        instance = new Runner();

    return instance;
}

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