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

	_currentScene = new SplashScreenScene(_renderer);
	_currentScene->Start();
}



void SceneManager::Update(const double& elapsedTime)
{
	_isSceneFinished = _currentScene->Update(elapsedTime);
	if (_isSceneFinished) {
		// Acabar estat actual
		_currentScene->End();
		// Canviar d'estat
		SetNewCurrentScene(_currentScene->GetNextState());
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


void SceneManager::SetNewCurrentScene(const Scenes& newCurrentScene)
{
	delete _currentScene;

	switch (newCurrentScene) 
	{
	case Scenes::SPLASH_SCREEN:
		_currentScene = new SplashScreenScene(_renderer);
		break;
	case Scenes::MAIN_MENU:
		_currentScene = new MainMenuScene(_renderer, _isRunning);
		break;
	case Scenes::RANKING:
		_currentScene = new RankingScene(_renderer);
		break;
	case Scenes::GAME:
		_currentScene = new GameScene(_renderer);
		break;
	default:
		break;
	}
}