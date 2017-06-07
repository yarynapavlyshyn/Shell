#include "shell.h"

using namespace std;

int main(int argc, char* argv[]) {
	
	Shell* shell = new Shell();
	
	shell->Run();
	
	// Clear memory
	delete shell;

	return 0;
}