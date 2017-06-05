#include "shell.h"

using namespace std;

int main(int argc, char* argv[]) {
	
	Shell* shell = new Shell(path{ "C:" });
	
	shell->Run();
	
	// Clear memory
	delete shell;

	return 0;
}