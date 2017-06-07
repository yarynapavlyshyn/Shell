#pragma once

#ifndef SHELLPROJECT_SHELL_H_
#define SHELLPROJECT_SHELL_H_

#include "exit_command.h"
#include "make_directory_command.h"
#include "list_command.h"
#include "print_working_directory_command.h"

class Shell
{
public:
	Shell();
	Shell(path& startupPath);
	~Shell();

	void Run();
	void Stop();
	bool IsRunning();

	void SetPath(path& newPath);

private:
	bool is_running_;
	std::unordered_map<std::string, ICommand*> commands_;
	path current_path_;

	void InitializeCommands();
};

#endif  // SHELLPROJECT_SHELL_H_