#include <iostream>
#include "PetGame.h"

int main() {
	try {
		PetGame game;
		game.run();
	}
	catch (const std::runtime_error& error) {
		std::cerr << error.what() << std::endl;
	}
	catch (...) {
		std::cerr << "God damn goofy, you goofed up!\n";
	}

	return 0;
}