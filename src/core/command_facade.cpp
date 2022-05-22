#include "../../include/core/command_facade.hpp"

CommandFacade::CommandFacade()
{
    assert = Assert::get_instance();
    commands = {
        { "self-test", [this]() -> void { self_test(); } },
        { "test",      [this]() -> void { test(); } }
    };
}

std::vector<std::string> CommandFacade::list_commands()
{
    std::vector<std::string> keys;

    keys.reserve(commands.size());

    for (auto it = commands.begin(); it != commands.end(); ++it)
        keys.push_back(it->first);

    return keys;
}

void CommandFacade::self_test()
{
    Runner *runner = Runner::get_instance();
    vector<string> tests = {Constants::ASSERT_TEST};

    runner->process(tests);
    runner->run(tests);

    assert->show_statistics();
}

void CommandFacade::test()
{
    Scanner *scanner = Scanner::get_instance();
    Runner *runner = Runner::get_instance();

    vector<string> tests = scanner->scan_test_folder();

    runner->process(tests);
    runner->run(tests);

    assert->show_statistics();
}

std::function<void()> CommandFacade::parse(string const &command)
{
    auto it = commands.find(command);

    auto notfound = [command]() -> void {
        std::cerr << "Command '" << command << "' not found." << std::endl;
    };

    return (it != commands.end()) ? it->second : notfound;
}
