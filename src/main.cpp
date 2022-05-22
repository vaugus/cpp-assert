#include "../include/core/command_facade.hpp"

void usage()
{
	std::cerr <<
		"This program expects the name of a command as a single "
		"argument.\n";
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		usage();
		return 0;
	}

	CommandFacade *facade = new CommandFacade();
	auto commandFunction = facade->parse(argv[1]);
	commandFunction();
	delete facade;

	return 0;
}
