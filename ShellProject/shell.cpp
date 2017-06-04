#include <iostream>

#include "shell.h"
#include "exit_command.h"


using namespace std;


Shell::Shell()
{
	this->is_running_ = false;
}


Shell::~Shell()
{
}

void Shell::Run()
{
	this->is_running_ = true;

	char* user_command_input = new char[1024];

	ExitCommand* exitCommand = new ExitCommand("exit");

	while (user_command_input != exitCommand->GetCommandKeyword())
	{
		cout << "^_^ ";
		cin.getline(user_command_input, 1024);
	}

	this->is_running_ = false;
}

bool Shell::IsRunning()
{
	return this->is_running_;
}
