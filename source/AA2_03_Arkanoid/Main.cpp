#include "Game/Game.h"
#include <exception>
#include <chrono>

int main(int argc, char* args[]) {

	try {

		srand(time(NULL));
		Game myGame;
		myGame.GameLoop();

	}
	catch (std::exception& exception) {
		fprintf(stderr, exception.what());
		SDL_Quit();
		return -1;
	}

	return 0;
}