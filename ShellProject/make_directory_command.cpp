#include "make_directory_command.h"

#include <iostream>

MakeDirectoryCommand::MakeDirectoryCommand(std::string commandKeyword) : ShellCommand(commandKeyword)
{
}


MakeDirectoryCommand::~MakeDirectoryCommand()
{
}

void MakeDirectoryCommand::DisplayShortCommandDescription()
{
	
}

bool MakeDirectoryCommand::Execute(std::vector<std::string> options)
{
	// create directory
	return true;
}
