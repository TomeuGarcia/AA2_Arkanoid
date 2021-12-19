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
	_controller->AddActionKey(ActionName::RESUME, SDLK_ESCAPE);
	InputHandler::GetInstance()->AddController(_controller);
	InitBackground();
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
	_background->Update(elapsedTime);
	return false;
}

void RankingScene::Render() const
{
	std::cout << "RankingScene::Render\n";
	SDL_RenderClear(_renderer);
	_background->Render();
	SDL_RenderPresent(_renderer);
}

void RankingScene::End()
{
	std::cout << "RankingScene::End\n";

	InputHandler::GetInstance()->RemoveAllControllers();
	_goToMainMenu = false;
	delete _background;
	_background = nullptr;
}

void RankingScene::InitBackground()
{
	_background = new ImageGameObject(_renderer, "../../resources/assets/images/background.jpg",
		Vector2D<int>(0, 0), SCREEN_SIZE, Vector2D<int>(30, 30), Vector2D<int>(740, 435));
}
