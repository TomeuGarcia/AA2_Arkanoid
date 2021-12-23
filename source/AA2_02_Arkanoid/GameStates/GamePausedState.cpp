#include "GamePausedState.h"


GamePausedState::GamePausedState(SDL_Renderer* renderer, Controller* controller, GameObjects* gameObjects)
	: GameState(renderer, gameObjects), _controller(controller),
	_blackBackground(nullptr), _pauseText(nullptr), _lToResumeText(nullptr)
	
{
}

GamePausedState::~GamePausedState()
{
}

void GamePausedState::DoStart()
{
	InitBlackBackground();
	InitTexts();
}


bool GamePausedState::Update(const double& elapsedTime)
{
	if (_controller->GetButtonDown(ActionName::RESUME)) {
		_nextState = GameStates::RUNNING;
		return true;
	}
	else if (_controller->GetButtonDown(ActionName::QUIT)) {
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
	SDL_RenderClear(_renderer);

	RenderGameObjects();
	_blackBackground->Render();
	_pauseText->Render();
	_lToResumeText->Render();

	SDL_RenderPresent(_renderer);
}

void GamePausedState::End()
{
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