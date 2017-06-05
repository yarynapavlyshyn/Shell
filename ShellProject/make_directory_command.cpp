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
	std::cout << "What the fuck?";
}

bool MakeDirectoryCommand::Execute(std::vector<std::string> options)
{
	this->optional_action_commands_[options[0]]->Invoke();
	return true;
}
