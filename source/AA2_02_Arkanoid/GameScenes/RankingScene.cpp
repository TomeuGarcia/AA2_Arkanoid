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
	InitTexts();
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
	_title->Update(elapsedTime);
	_mainMenuText->Update(elapsedTime);
	for (int i = 0; i < 10; ++i)
	{
		_ranking[i]->Update(elapsedTime);
	}
	return false;
}

void RankingScene::Render() const
{
	std::cout << "RankingScene::Render\n";
	SDL_RenderClear(_renderer);
	_background->Render();
	_title->Render();
	_mainMenuText->Render();
	for (int i = 0; i < 10; ++i) 
	{
		_ranking[i]->Render();
	}
	SDL_RenderPresent(_renderer);
}

void RankingScene::End()
{
	std::cout << "RankingScene::End\n";

	InputHandler::GetInstance()->RemoveAllControllers();
	_goToMainMenu = false;
	delete _background;
	_background = nullptr;
	delete _mainMenuText;
	delete _title;
	_mainMenuText = nullptr;
	_title = nullptr;
	for (int i = 0; i < 10; ++i)
	{
		delete _ranking[i];
		_ranking[i] = nullptr;
	}
}

void RankingScene::InitBackground()
{
	_background = new ImageGameObject(_renderer, "../../resources/assets/images/background.jpg",
		Vector2D<int>(0, 0), SCREEN_SIZE, Vector2D<int>(30, 30), Vector2D<int>(740, 435));
}

void RankingScene::InitTexts()
{
	SDL_Color white({ 255,255,255,255 });
	_title = new TextGameObject(_renderer, "Ranking:", white, Vector2D<int>(300, 100), 36);
	_mainMenuText = new TextGameObject(_renderer, "ESC to Menu", white, Vector2D<int>(580, 550), 24);
	for (int i = 0; i < 10; ++i) {
		
		_ranking.push_back(new TextGameObject(_renderer, (std::to_string(i+1) + std::string(". Player")).c_str(), white, Vector2D<int>(320, 160 + i*(40)), 20));
	}
	
}
