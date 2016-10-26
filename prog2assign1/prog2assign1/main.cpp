#include <iostream>
#include "RogueGame.h"

int main() {
	try {
		RogueGame game;
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