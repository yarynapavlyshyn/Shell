#pragma once

#ifndef SHELLPROJECT_SHELL_COMMAND_H_
#define	SHELLPROJECT_SHELL_COMMAND_H_

#include <string>

class ShellCommand
{
public:
	ShellCommand(std::string commandKeyword);
	virtual ~ShellCommand();

	virtual bool Execute() = 0;

	std::string GetCommandKeyword();

protected:
	std::string command_keyword_;
};

#endif // !SHELLPROJECT_SHELL_COMMAND_H_