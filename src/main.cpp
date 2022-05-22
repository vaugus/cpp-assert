#include "../include/core/command_facade.hpp"

static CommandFacade *facade = new CommandFacade();

void delete_facade()
{
	delete facade;
}

void usage()
{
	std::cerr <<
		"This program expects the name of a command as a single "
		"argument.\n\nAvailable commands:\n";

	for (auto command : facade->list_commands())
		std::cerr << "\t" << command << "\n";
}

int main(int argc, char **argv)
{
	std::atexit(delete_facade);

	if (argc < 2) {
		usage();
		return 0;
	}

	auto commandFunction = facade->parse(argv[1]);
	commandFunction();

	return 0;
}
