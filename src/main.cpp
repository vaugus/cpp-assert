#include "../include/core/command_facade.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		CommandFacade *facade = new CommandFacade();
		auto commandFunction = facade->parse(argv[1]);
		commandFunction();
		delete facade;
	}

	return 0;
}
