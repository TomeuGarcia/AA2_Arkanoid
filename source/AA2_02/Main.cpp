#include "Game/SceneManager.h"
#include <exception>
#include <chrono>


int main(int argc, char* args[]) {

	try {

		SceneManager sceneManager = SceneManager();

		sceneManager.Init();


		auto lastTime = std::chrono::system_clock::now();
		while (sceneManager.IsRunning()) {
			auto currentTime = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsedTime = currentTime - lastTime;

			sceneManager.HandleEvents();

			sceneManager.Update(elapsedTime.count()); // Game logic goes here

			sceneManager.Render();

			lastTime = currentTime;
		}

		sceneManager.Release();

	}
	catch (std::exception& exception) {
		fprintf(stderr, exception.what());
		SDL_Quit();
		return -1;
	}

	return 0;
}