#include "Tute01_AgentsApp.h"

int main() {
	
	// allocation
	auto app = new Tute01_AgentsApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}