#include "../../include/core/command_facade.hpp"
#include <map>

using CommandMap = std::map<std::string, std::function<void()>>;

void CommandFacade::self_test()
{
	UnitTest *test = UnitTestFactory::create("assert_test");
	test->run();
	Assert::get_instance()->show_statistics();
}

void CommandFacade::test()
{
    Scanner *scanner = new Scanner();
    Runner *runner = new Runner();

    for (const string test : scanner->scan_test_folder())
    {
        runner->compile(test);
        runner->run();
    }
}

void CommandFacade::parse(string const &command)
{
    CommandMap map = {
        { "self-test", [this]() -> void { self_test(); } },
        { "test",      [this]() -> void { test(); } }
    };

    auto it = map.find(command);

    if (it != map.end())
    {
        it->second();
    }
}
