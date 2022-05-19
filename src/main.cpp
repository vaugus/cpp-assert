#include "../include/core/command_facade.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		CommandFacade *facade = new CommandFacade();
		facade->parse(argv[1]);
		delete facade;
	}

	return 0;
}
