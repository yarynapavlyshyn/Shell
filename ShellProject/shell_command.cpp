#include "shell_command.h"



ShellCommand::ShellCommand(std::string commandKeyword)
{
	this->command_keyword_ = commandKeyword;
}

ShellCommand::~ShellCommand()
{
}

std::string ShellCommand::GetCommandKeyword()
{
	return this->command_keyword_;
}
