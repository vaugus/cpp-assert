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

void Runner::add_descriptor(RunnerDescriptor descriptor)
{
    const string key = descriptor.file_name;
    descriptors.insert(std::pair<string, RunnerDescriptor>(key, descriptor));
}

RunnerDescriptor Runner::get_descriptor(string const &file_name)
{
    RunnerDescriptor descriptor;

    auto it = descriptors.find(file_name);
    if (it != descriptors.end())
        descriptor = it->second;

    return descriptor;
}

void Runner::initialize_descriptor(string const &file_name)
{
    RunnerDescriptor descriptor;

    const string test_name = Util::parse_header(file_name);
    descriptor.file_name = file_name;
    descriptor.test_name = test_name;
    descriptor.runnable_file = Util::concat({Constants::TEST_FOLDER,
                                             Constants::RUNNABLE,
                                             test_name,
                                             Constants::CPP});

    add_descriptor(descriptor);
}

void Runner::write_runnable_test(string const &file_name)
{
    RunnerDescriptor descriptor = get_descriptor(file_name);

    std::ofstream runnable = std::ofstream(descriptor.runnable_file, std::ios_base::app);
    std::ifstream base_test = std::ifstream(file_name);
    std::ifstream base_runner = std::ifstream(Constants::TEST_SUITE_BOILERPLATE);

    Util::write_remaining_lines(runnable, base_test);
    Util::write_remaining_lines(runnable, base_runner);

    runnable.close();
    base_test.close();
    base_test.close();
}

void Runner::compile(string const &file_name)
{
    RunnerDescriptor descriptor = get_descriptor(file_name);

    const string command = Util::concat({Constants::CXX,
                                         Constants::OBJECT_FLAG,
                                         descriptor.test_name,
                                         Constants::FIND_OBJECTS,
                                         descriptor.runnable_file});

    std::cout << "Compiling file using " << command << std::endl;

    system(command.c_str());
}

void Runner::run(vector<string> tests)
{
    for (const string test : tests)
    {
        RunnerDescriptor descriptor = get_descriptor(test);

        std::cout << "\nRunning file " << descriptor.runnable_file << std::endl;
        const string run = Util::concat({"./", descriptor.test_name});
        const string rm = Util::concat({"rm ",
                                        descriptor.test_name,
                                        " && rm ",
                                        descriptor.runnable_file});

        system(run.c_str());
        system(rm.c_str());
    }
}

void Runner::process(vector<string> tests)
{
    for (const string test : tests)
    {
        initialize_descriptor(test);
        write_runnable_test(test);
        compile(test);
    }
}
