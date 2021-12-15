#include "GamePausedState.h"


GamePausedState::GamePausedState(SDL_Renderer* renderer, Player* player1) : GameState(renderer), _player1(player1), _blackBackground(nullptr)
{
}

GamePausedState::~GamePausedState()
{
}

void GamePausedState::DoStart()
{
	std::cout << "GamePausedState::Start\n";
	InitBlackbackground();
}

bool GamePausedState::Update(float elapsedTime)
{
	std::cout << "GamePausedState::Update\n";
	if (_player1->GetController()->GetButtonDown(ActionName::RESUME)) {
		_nextState = GameStates::RUNNING;
		return true;
	}

	return false;
}

void GamePausedState::Render() const
{
	std::cout << "GamePausedState::Render\n";
	
	//SDL_RenderClear(_renderer);
	_blackBackground->Draw();
	//SDL_RenderPresent(_renderer);
}

void GamePausedState::End()
{
	std::cout << "GamePausedState::End\n";
}

void GamePausedState::InitBlackbackground()
{
	_blackBackground = new Image(_renderer, Vector2D<int>(0, 0), Vector2D<int>(SCREEN_WIDTH, SCREEN_HEIGHT),
		Vector2D<int>(0, 0), Vector2D<int>(SCREEN_WIDTH, SCREEN_HEIGHT));
	_blackBackground->Init("../../resources/assets/images/blackBackground.png");
	_blackBackground->SetOpacity(150);
}
