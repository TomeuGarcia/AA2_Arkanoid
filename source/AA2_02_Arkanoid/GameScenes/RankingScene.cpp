#include "RankingScene.h"

RankingScene::RankingScene(SDL_Renderer* renderer) : Scene(renderer), _controller(nullptr), _goToMainMenu(false)
{
}


RankingScene::~RankingScene()
{
}

void RankingScene::DoStart()
{
	std::cout << "RankingScene::Start\n";

	_controller = new Keyboard("keyboard");
	_controller->AddActionKey(ActionName::RESUME, SDLK_SPACE);
	InputHandler::GetInstance()->AddController(_controller);
}

void RankingScene::HandleEvents()
{
	if (_controller->GetButtonDown(ActionName::RESUME)) {
		_goToMainMenu = true;
	}
	
}

bool RankingScene::Update(const double& elapsedTime)
{
	std::cout << "RankingScene::Update\n";
	if (_goToMainMenu) {
		_nextScene = Scenes::MAIN_MENU;
		return true;
	}

	return false;
}

void RankingScene::Render() const
{
	std::cout << "RankingScene::Render\n";
	SDL_RenderClear(_renderer);
	SDL_RenderPresent(_renderer);
}

void RankingScene::End()
{
	std::cout << "RankingScene::End\n";

	InputHandler::GetInstance()->RemoveAllControllers();
}
