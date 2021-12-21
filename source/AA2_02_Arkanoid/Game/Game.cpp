#include "Game.h"

Game::Game() : _sceneManager(nullptr), _isRunning(true)
{
	InitSceneManager();
}

Game::~Game()
{
	_sceneManager->Release();
	delete _sceneManager;
}

void Game::InitSceneManager()
{
	_sceneManager = new SceneManager(&_isRunning);
	_sceneManager->Init();
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
	_sceneManager->HandleEvents();
}

void Game::Update(const double& elapsedTime)
{
	_sceneManager->Update(elapsedTime);
}

void Game::Render()
{
	_sceneManager->Render();
}
