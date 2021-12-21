#include "GamePausedState.h"


GamePausedState::GamePausedState(SDL_Renderer* renderer, Controller* controller, GameObjects* gameObjects)
	: GameState(renderer, gameObjects), _controller(controller), _goToRunningState(false), _goToMainMenu(false),
	_blackBackground(nullptr), _pauseText(nullptr), _lToResumeText(nullptr)
	
{
}

GamePausedState::~GamePausedState()
{
}

void GamePausedState::DoStart()
{
	std::cout << "GamePausedState::Start\n";
	InitBlackBackground();
	InitTexts();
}

void GamePausedState::HandleEvents()
{
	if (_controller->GetButtonDown(ActionName::RESUME)) {
		_goToRunningState = true;
	}
	if (_controller->GetButtonDown(ActionName::QUIT)) {
		_goToMainMenu = true;
	}
}

bool GamePausedState::Update(const double& elapsedTime)
{
	std::cout << "GamePausedState::Update\n";
	if (_goToRunningState) {
		_nextState = GameStates::RUNNING;
		return true;
	}
	else if (_goToMainMenu) {
		_nextState = GameStates::QUIT_TO_MAIN_MENU;
		return true;
	}

	_blackBackground->Update(elapsedTime);
	_pauseText->Update(elapsedTime);
	_lToResumeText->Update(elapsedTime);

	return false;
}

void GamePausedState::Render() const
{
	std::cout << "GamePausedState::Render\n";
	
	SDL_RenderClear(_renderer);

	DrawGameObjects();
	_blackBackground->Render();
	_pauseText->Render();
	_lToResumeText->Render();

	SDL_RenderPresent(_renderer);
}

void GamePausedState::End()
{
	std::cout << "GamePausedState::End\n";

	_goToRunningState = _goToMainMenu = false;
	delete _blackBackground;
	_blackBackground = nullptr;
	delete _pauseText;
	delete _lToResumeText;
	_pauseText = _lToResumeText = nullptr;
}

void GamePausedState::InitBlackBackground()
{
	_blackBackground = new ImageGameObject(_renderer, "../../resources/assets/images/blackBackground.png", 
		Vector2D<int>(0, 0), Vector2D<int>(SCREEN_WIDTH, SCREEN_HEIGHT), Vector2D<int>(0, 0), Vector2D<int>(SCREEN_WIDTH, SCREEN_HEIGHT), 150);
}

void GamePausedState::InitTexts()
{
	SDL_Color white({ 255,255,255,255 });
	_pauseText = new TextGameObject(_renderer, "...PAUSE...", white, Vector2D<int>(200, 200), 72);
	_lToResumeText = new TextGameObject(_renderer, "L TO RESUME", white, Vector2D<int>(240, 280), 36);
}