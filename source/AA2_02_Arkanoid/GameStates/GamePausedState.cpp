#include "GamePausedState.h"


GamePausedState::GamePausedState(SDL_Renderer* renderer, Controller* controller, GameObjects* gameObjects, Mix_Music* gameMusic)
	: GameState(renderer, gameObjects), _controller(controller),
	_blackBackground(nullptr), _pauseText(nullptr), _lToResumeText(nullptr),
	_gameMusic(gameMusic)
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
	if (_controller->GetButtonDown(ActionName::START)) {
		_nextState = GameStates::RUNNING;
		return true;
	}
	else if (_controller->GetButtonDown(ActionName::QUIT)) {
		_nextState = GameStates::QUIT_TO_MAIN_MENU;
		return true;
	}
	if (_controller->GetButtonDown(ActionName::MUSIC_SWITCH)) {
		AudioHandler::GetInstance()->AudioSwitch();
	}

	_blackBackground->Update(elapsedTime);
	_pauseText->Update(elapsedTime);
	_lToResumeText->Update(elapsedTime);

	return false;
}

void GamePausedState::Render() const
{	
	RenderGameObjects();
	_blackBackground->Render();
	_pauseText->Render();
	_lToResumeText->Render();
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
	_lToResumeText = new TextGameObject(_renderer, "Space to resume", white, Vector2D<int>(185, 280), 36);
	_lToResumeText = new TextGameObject(_renderer, "M to play / stop audio", white, Vector2D<int>(185, 315), 28);
}