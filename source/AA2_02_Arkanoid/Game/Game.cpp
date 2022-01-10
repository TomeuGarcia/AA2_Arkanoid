#include "Game.h"

Game::Game() : _sceneManager(nullptr), _isRunning(true)
{
	InitSDL();
	InitSceneManager();
}

Game::~Game()
{
	Release();
	delete _sceneManager;
}


void Game::InitSDL()
{
	int result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	bool isInitialized = result >= 0;

	if (!isInitialized) {
		SDL_GetError();
	}

	InitWindowAndRenderer();
	InitAudioSDL();
	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
	InitFont();
}

void Game::InitWindowAndRenderer()
{
	int result = SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN, &_window, &_renderer);
	bool isInitialized = result >= 0;

	if (!isInitialized) {
		SDL_GetError();
	}
}

void Game::InitAudioSDL()
{
}

void Game::InitFont()
{
	TTF_Init();
}


void Game::InitSceneManager()
{
	_sceneManager = new SceneManager(&_isRunning, _renderer);
}




void Game::GameLoop()
{
	auto lastTime = std::chrono::system_clock::now();
	while (_isRunning) {
		auto currentTime = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsedTime = currentTime - lastTime;

		HandleEvents();
		Update(elapsedTime.count());
		Render();

		lastTime = currentTime;
	}
}

void Game::HandleEvents()
{
	InputHandler::GetInstance()->HandleEvents();
}

void Game::Update(const double& elapsedTime)
{
	_sceneManager->Update(elapsedTime);
}

void Game::Render()
{
	SDL_RenderClear(_renderer);
	_sceneManager->Render();
	SDL_RenderPresent(_renderer);
}


void Game::Release()
{
	Mix_CloseAudio();

	TTF_Quit();

	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}
