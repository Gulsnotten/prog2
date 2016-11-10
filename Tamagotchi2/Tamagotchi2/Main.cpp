#include <iostream>
#include "PetGame.h"

#include <string>

int main() {
	int min = 0;
	int max = 5;
	


	try {
		PetGame game;
		game.Run();
	}
	catch (const std::runtime_error& error) {
		std::cerr << error.what() << std::endl;
	}
	catch (...) {
		std::cerr << "God damn goofy, you goofed up!\n";
	}

	return 0;
}