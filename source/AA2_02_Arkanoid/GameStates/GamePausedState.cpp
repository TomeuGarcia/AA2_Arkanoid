#include "GamePausedState.h"


GamePausedState::GamePausedState(SDL_Renderer* renderer, GameObjects* gameObjects) 
	: GameState(renderer, gameObjects),_blackBackground(nullptr), _goToRunningState(false)
{
}

GamePausedState::~GamePausedState()
{
}

void GamePausedState::DoStart()
{
	std::cout << "GamePausedState::Start\n";
	InitBlackBackground();
}

void GamePausedState::HandleEvents()
{
	if (_gameObjects->_player1->GetController()->GetButtonDown(ActionName::RESUME)) {
		_goToRunningState = true;
	}
}

bool GamePausedState::Update(const double& elapsedTime)
{
	std::cout << "GamePausedState::Update\n";
	if (_goToRunningState) {
		_nextState = GameStates::RUNNING;
		return true;
	}

	return false;
}

void GamePausedState::Render() const
{
	std::cout << "GamePausedState::Render\n";
	
	SDL_RenderClear(_renderer);
	DrawGameObjects();
	_blackBackground->Draw();
	SDL_RenderPresent(_renderer);
}

void GamePausedState::End()
{
	std::cout << "GamePausedState::End\n";
	delete _blackBackground;
	_goToRunningState = false;
}

void GamePausedState::InitBlackBackground()
{
	_blackBackground = new Image(_renderer, Vector2D<int>(0, 0), Vector2D<int>(SCREEN_WIDTH, SCREEN_HEIGHT),
		Vector2D<int>(0, 0), Vector2D<int>(SCREEN_WIDTH, SCREEN_HEIGHT));
	_blackBackground->Init("../../resources/assets/images/blackBackground.png");
	_blackBackground->SetOpacity(150);
}
