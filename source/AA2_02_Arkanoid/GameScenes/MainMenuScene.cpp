#include "MainMenuScene.h"


MainMenuScene::MainMenuScene(SDL_Renderer* renderer, Player* player1) : Scene(renderer), _player1(player1)
{
}

MainMenuScene::~MainMenuScene() 
{
}

void MainMenuScene::DoStart()
{

	std::cout << "MainMenuScene::Start\n";
}

bool MainMenuScene::Update(const double& elapsedTime)
{
	std::cout << "MainMenuScene::Update\n";
	if (_player1->GetController()->GetButtonDown(ActionName::START)) {
		_nextScene = Scenes::GAME;
		return true;
	}
	else if (_player1->GetController()->GetButtonDown(ActionName::RANKING)) { 
		_nextScene = Scenes::RANKING;
		return true;
	}
	else if (_player1->GetController()->GetButtonDown(ActionName::QUIT)) {
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
}
