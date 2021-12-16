#include "MainMenuScene.h"


MainMenuScene::MainMenuScene(SDL_Renderer* renderer) 
	: Scene(renderer), _controller(nullptr), _goToGameScene(false), _goToRankingScene(false), _quitGame(false)
{
}

MainMenuScene::~MainMenuScene() 
{
}

void MainMenuScene::DoStart()
{
	std::cout << "MainMenuScene::Start\n";

	_controller = new Keyboard("keyboard");
	_controller->AddActionKey(ActionName::START, SDLK_SPACE);
	_controller->AddActionKey(ActionName::RANKING, SDLK_r);
	_controller->AddActionKey(ActionName::QUIT, SDLK_ESCAPE);
	InputHandler::GetInstance()->AddController(_controller);
}

void MainMenuScene::HandleEvents()
{
	if (_controller->GetButtonDown(ActionName::START)) {
		_goToGameScene = true;
	}
	else if (_controller->GetButtonDown(ActionName::RANKING)) {
		_goToRankingScene = true;
	}
	else if (_controller->GetButtonDown(ActionName::QUIT)) {
		_quitGame = true;
	}
}

bool MainMenuScene::Update(const double& elapsedTime)
{
	std::cout << "MainMenuScene::Update\n";
	if (_goToGameScene) {
		_nextScene = Scenes::GAME;
		return true;
	}
	else if (_goToRankingScene) {
		_nextScene = Scenes::RANKING;
		return true;
	}
	else if (_quitGame) {
		_nextScene = Scenes::QUIT;
		return true;
	}

	return false;
}

void MainMenuScene::Render() const
{
	std::cout << "MainMenuScene::Render\n";
	SDL_RenderClear(_renderer);
	SDL_RenderPresent(_renderer);
}

void MainMenuScene::End()
{
	std::cout << "MainMenuScene::End\n";
	InputHandler::GetInstance()->RemoveAllControllers();
	_goToGameScene = false;
	_goToRankingScene = false;
	_quitGame = false;
}
