#include "MainMenuScene.h"


MainMenuScene::MainMenuScene(SDL_Renderer* renderer, bool* isRunning)
	: _isRunning(isRunning), Scene(renderer), _controller(nullptr), _goToGameScene(false), _goToRankingScene(false), 
	_background(nullptr), _title(nullptr), _playGameText(nullptr), _rankingText(nullptr), _optionsText(nullptr), _quitText(nullptr)
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
	InitBackground();
	InitTexts();
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
		*_isRunning = false;
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


	_background->Update(elapsedTime);

	_title->Update(elapsedTime);
	_playGameText->Update(elapsedTime);
	_rankingText->Update(elapsedTime);
	_optionsText->Update(elapsedTime);
	_quitText->Update(elapsedTime);


	return false;
}

void MainMenuScene::Render() const
{
	std::cout << "MainMenuScene::Render\n";
	SDL_RenderClear(_renderer);

	_background->Render();
	_title->Render();
	_playGameText->Render();
	_rankingText->Render();
	_optionsText->Render();
	_quitText->Render();
	SDL_RenderPresent(_renderer);
}

void MainMenuScene::End()
{
	std::cout << "MainMenuScene::End\n";
	InputHandler::GetInstance()->RemoveAllControllers();
	_goToGameScene = false;
	_goToRankingScene = false;

	delete _background;
	_background = nullptr;

	delete _title;
	delete _playGameText;
	delete _rankingText;
	delete _optionsText;
	delete _quitText;
	_title = _playGameText = _rankingText = _optionsText = _quitText = nullptr;

}

void MainMenuScene::InitBackground()
{
	_background = new ImageGameObject(_renderer, "../../resources/assets/images/background.jpg",
		Vector2D<int>(0, 0), SCREEN_SIZE,Vector2D<int>(30, 30), Vector2D<int>(740, 435));
}

void MainMenuScene::InitTexts()
{
	SDL_Color white({ 255,255,255,255 });
	_title = new TextGameObject(_renderer, "Main Menu", white, Vector2D<int>(300, 100), 36);

	_playGameText = new TextGameObject(_renderer, "Space to Play Game", white, Vector2D<int>(50, 200), 24);
	_rankingText = new TextGameObject(_renderer, "R to Ranking", white, Vector2D<int>(50, 300), 24);
	_optionsText = new TextGameObject(_renderer, "Options", white, Vector2D<int>(50, 400), 24);
	_quitText = new TextGameObject(_renderer, "Esc to Quit", white, Vector2D<int>(50, 500), 24);
}
