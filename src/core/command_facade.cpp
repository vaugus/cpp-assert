#include "../../include/core/command_facade.hpp"
#include <map>

using CommandMap = std::map<std::string, std::function<void()>>;

void CommandFacade::self_test()
{
    Runner *runner = Runner::get_instance();
    runner->compile(Constants::ASSERT_TEST);
    runner->run(Constants::ASSERT_TEST);
	Assert::get_instance()->show_statistics();
}

void CommandFacade::test()
{
    Scanner *scanner = Scanner::get_instance();
    Runner *runner = Runner::get_instance();

    for (const string test : scanner->scan_test_folder())
    {
        runner->initialize_descriptor(test);
        runner->write_runnable_test(test);
        runner->compile(test);
        runner->run(test);
    }
}

void CommandFacade::parse(string const& command)
{
    CommandMap map = {
        { "self-test", [this]() -> void { self_test(); } },
        { "test",      [this]() -> void { test(); } }
    };

    auto it = map.find(command);

    if (it != map.end())
        it->second();
}
