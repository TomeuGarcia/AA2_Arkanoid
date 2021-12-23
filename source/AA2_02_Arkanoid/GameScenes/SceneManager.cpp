#include "SceneManager.h"

SceneManager::SceneManager(bool* isRunning, SDL_Renderer* renderer) 
	: _isRunning(isRunning), _renderer(renderer)
{
	InitScenes();
}

SceneManager::~SceneManager()
{
}


void SceneManager::InitScenes()
{
	_isSceneFinished = false;

	_scenes[Scenes::SPLASH_SCREEN] = new SplashScreenScene(_renderer);
	_scenes[Scenes::MAIN_MENU] = new MainMenuScene(_renderer, _isRunning);
	_scenes[Scenes::RANKING] = new RankingScene(_renderer);
	_scenes[Scenes::GAME] = new GameScene(_renderer);

	_currentScene = _scenes[Scenes::SPLASH_SCREEN];
	_currentScene->Start();
}



void SceneManager::Update(const double& elapsedTime)
{
	_isSceneFinished = _currentScene->Update(elapsedTime);
	if (_isSceneFinished) {
		// Acabar estat actual
		_currentScene->End();
		// Canviar d'estat
		_currentScene = _scenes[_currentScene->GetNextState()];
		// Començar nou estat
		_currentScene->Start();
	}
}

void SceneManager::Render()
{
	_currentScene->Render();
}


bool SceneManager::IsRunning()
{
	return _isRunning;
}
