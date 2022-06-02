#include "../include/core/command_facade.hpp"

void usage()
{
	std::cerr <<
		"This program expects the name of a command as a single "
		"argument.\n\nAvailable commands:\n";

	for (auto command : command_facade::list_commands())
		std::cerr << "\t" << command << "\n";
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		usage();
		return 0;
	}

	auto commandFunction = command_facade::parse(argv[1]);
	commandFunction();

	return 0;
}
