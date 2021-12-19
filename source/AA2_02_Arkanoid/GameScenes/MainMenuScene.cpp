#include "MainMenuScene.h"


MainMenuScene::MainMenuScene(SDL_Renderer* renderer) 
	: Scene(renderer), _controller(nullptr), _goToGameScene(false), _goToRankingScene(false), _quitGame(false), _background(nullptr)
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
	InitText();
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
	_background->Update(elapsedTime);
	_title->Update(elapsedTime);
	return false;
}

void MainMenuScene::Render() const
{
	std::cout << "MainMenuScene::Render\n";
	SDL_RenderClear(_renderer);
	_background->Render();
	_title->Render();
	SDL_RenderPresent(_renderer);
}

void MainMenuScene::End()
{
	std::cout << "MainMenuScene::End\n";
	InputHandler::GetInstance()->RemoveAllControllers();
	_goToGameScene = false;
	_goToRankingScene = false;
	_quitGame = false;
	delete _background;
	_background = nullptr;
	delete _title;
	_title = nullptr;
}

void MainMenuScene::InitBackground()
{
	_background = new ImageGameObject(_renderer, "../../resources/assets/images/background.jpg",
		Vector2D<int>(0, 0), SCREEN_SIZE,Vector2D<int>(30, 30), Vector2D<int>(740, 435));
}

void MainMenuScene::InitText()
{
	
	SDL_Color color = { 255,255,255,100 };
	SDL_Color backgroundColor = { 0,0,0,100 };
	_title = new TextGameObject(_renderer, "MainMenu", color, backgroundColor, Vector2D<int>(100, 100), Vector2D<int>(200, 50));
}
