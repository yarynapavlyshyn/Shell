#include <iostream>

#include "shell.h"
#include "string_utility.h"

using namespace std;


Shell::Shell()
{
	this->is_running_ = false;
	this->current_path_ = bfs::current_path();

	this->InitializeCommands();
}

Shell::Shell(bfs::path& startupPath) : Shell()
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
		throw -1;
	}
	this->is_running_ = true;

	char user_command_input[1024];

	while (this->is_running_)
	{
		cout << this->current_path_.string() << ":~ ^_^ ";
		cin.getline(user_command_input, 1024);

		std::string delimiter = " ";
		std::vector<std::string> additional_options = StringUtility::Split(std::string(user_command_input), delimiter);

		if (this->commands_.find(user_command_input) != this->commands_.end())
		{
			this->commands_[user_command_input]->Execute(additional_options);
		}
		else
		{
			cout << "Unrecognised command. Notice me Senpai!" << endl;
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

void Shell::SetPath(bfs::path& newPath)
{
	this->current_path_ = newPath;
}

void Shell::InitializeCommands()
{
	std::string exit_command_keyword = "exit";
	this->commands_.insert({ exit_command_keyword, new ExitCommand(exit_command_keyword, this) });

	std::string make_directory_command_keyword = "mkdir";
	this->commands_.insert({ make_directory_command_keyword, new MakeDirectoryCommand(make_directory_command_keyword) });

	std::string list_command_keyword = "ls";
	this->commands_.insert({ list_command_keyword, new ListCommand(list_command_keyword) });

	// std::string print_working_directory_command_keyword = "pwd";
	// this->commands_.insert({ print_working_directory_command_keyword, new PrintWorkingDirectoryCommand(print_working_directory_command_keyword) });

	// std::string remove_command_keyword = "rm";
	// this->commands_.insert({ remove_command_keyword, new RemoveCommand(remove_command_keyword) });

	// Im going to add string split() to shell in this cpp file after you initialize those new commands in here because of merge on git
	// So you can leave additional options to be additional_options.push_back("-h"); for now, without adding additional options fucntional to commands
}
