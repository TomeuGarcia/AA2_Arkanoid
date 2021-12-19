#include "RankingScene.h"

RankingScene::RankingScene(SDL_Renderer* renderer) : Scene(renderer), _controller(nullptr), _goToMainMenu(false),
	_title(nullptr), _ranking(), _mainMenuText(nullptr)
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

void RankingScene::InitTexts()
{
	//SDL_Color white({ 255,255,255,255 });
	//_title = new TextGameObject(_renderer, "Main Menu", white, Vector2D<int>(300, 100), 36);

	//_playGameText = new TextGameObject(_renderer, "Space to Play Game", white, Vector2D<int>(50, 200), 24);
	//_rankingText = new TextGameObject(_renderer, "R to Ranking", white, Vector2D<int>(50, 300), 24);
	//_optionsText = new TextGameObject(_renderer, "Options", white, Vector2D<int>(50, 400), 24);
	//_quitText = new TextGameObject(_renderer, "Esc to Quit", white, Vector2D<int>(50, 500), 24);
}
