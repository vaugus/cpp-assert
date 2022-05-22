#include "../../include/core/command_facade.hpp"
#include <map>

using CommandMap = std::map<std::string, std::function<void()>>;

CommandFacade::CommandFacade()
{
    assert = Assert::get_instance();
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
    CommandMap map = {
        { "self-test", [this]() -> void { self_test(); } },
        { "test",      [this]() -> void { test(); } }
    };

    auto it = map.find(command);

    auto notfound = [command]() -> void {
        std::cerr << "Command '" << command << "' not found." << std::endl;
    };

    return (it != map.end()) ? it->second : notfound;
}
