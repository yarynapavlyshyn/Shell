#include <iostream>

#include "shell.h"

using namespace std;


Shell::Shell()
{
	this->is_running_ = false;
	this->current_path_ = current_path();

	this->InitializeCommands();
}

Shell::Shell(path& startupPath) : Shell()
{
	this->current_path_ = startupPath;
}

Shell::~Shell()
{
	for (auto it = this->commands_.begin(); it != this->commands_.end(); ++it)
	{
		delete it->second;
	}
}

void Shell::Run()
{
	if (this->is_running_)
	{
		cout << "The shell is already running";
		throw - 1;
	}
	this->is_running_ = true;

	char user_command_input[1024];

	while (this->is_running_)
	{
		cout << this->current_path_.string() << " ^_^ ";
		cin.getline(user_command_input, 1024);

		std::vector<std::string> additional_options;
		additional_options.push_back("-h");

		if (this->commands_.find(user_command_input) != this->commands_.end())
		{
			this->commands_[user_command_input]->Execute(additional_options);
		}
	}
}

void Shell::Stop() 
{
	this->is_running_ = false;
}

bool Shell::IsRunning()
{
	return this->is_running_;
}

void Shell::SetPath(path& newPath)
{
	this->current_path_ = newPath;
}

void Shell::InitializeCommands()
{
	std::string exit_command_keyword = "exit";
	this->commands_.insert({ exit_command_keyword, new ExitCommand(exit_command_keyword, this) });

	std::string make_directory_command_keyword = "mkdir";
	this->commands_.insert({ make_directory_command_keyword, new MakeDirectoryCommand(make_directory_command_keyword) });
}
