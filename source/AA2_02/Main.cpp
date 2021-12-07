#include "Game/Game.h"
#include <exception>
#include <chrono>


int main(int argc, char* args[]) {

	try {

		Game game = Game();

		game.Init();


		auto lastTime = std::chrono::system_clock::now();
		while (game.IsRunning()) {
			auto currentTime = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsedTime = currentTime - lastTime;

			game.HandleEvents();

			game.Update(elapsedTime.count()); // Game logic goes here

			game.Render();

			lastTime = currentTime;
		}

		game.Release();

	}
	catch (std::exception& exception) {
		fprintf(stderr, exception.what());
		SDL_Quit();
		return -1;
	}

	return 0;
}