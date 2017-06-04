#pragma once

#ifndef SHELLPROJECT_SHELL_H_
#define SHELLPROJECT_SHELL_H_

class Shell
{
public:
	Shell();
	virtual ~Shell();

	void Run();
	bool IsRunning();

private:
	bool is_running_;
};

#endif  // SHELLPROJECT_SHELL_H_