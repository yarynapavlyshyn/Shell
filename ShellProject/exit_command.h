#pragma once
#include "shell_command.h"

#ifndef SHELLPROJECT_EXIT_COMMAND_H_
#define SHELLPROJECT_EXIT_COMMAND_H_

class ExitCommand : public ShellCommand
{
public:
	ExitCommand(std::string commandKeyword);
	virtual ~ExitCommand();
};

#endif // !SHELLPROJECT_EXIT_COMMAND_H_

