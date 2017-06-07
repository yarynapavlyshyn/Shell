#include "make_directory_command.h"

MakeDirectoryCommand::MakeDirectoryCommand(std::string commandKeyword) : ShellCommand(commandKeyword)
{
}


MakeDirectoryCommand::~MakeDirectoryCommand()
{
}

void MakeDirectoryCommand::DisplayShortCommandDescription()
{
	
}

void MakeDirectoryCommand::InitializeAdditionalCommandTriggers()
{
}

bool MakeDirectoryCommand::Execute(std::vector<std::string> options)
{
	for (std::string s : options)
	{
		std::cout << s << std::endl;
	}

	if (bfs::create_directory(bfs::path { options[0] }))
	{
		return true;
	}
	perror("Could not create a directory at current path");
	return false;
}
