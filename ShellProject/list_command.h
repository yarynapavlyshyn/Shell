#pragma once

#include "shell_command.h"

class ListCommand : public ShellCommand, public ICommand
{
public:
	ListCommand(std::string commandKeyword);
	virtual ~ListCommand();

	void DisplayShortCommandDescription();

	bool Execute(std::vector<std::string> options);
};

