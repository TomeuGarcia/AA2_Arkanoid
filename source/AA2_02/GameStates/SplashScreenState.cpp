#include "SplashScreenState.h"

SplashScreenState::SplashScreenState() : GameState()
{
}

SplashScreenState::~SplashScreenState()
{
}

void SplashScreenState::DoStart()
{
	std::cout << "SplashScreenState::Start\n";
	
	_waitTime = 3.0f;
}

bool SplashScreenState::Update(float elapsedTime)
{
	std::cout << "SplashScreenState::Update\n";
	if (_waitTime <= 0.0f) {
		_nextState = GameStates::MAIN_MENU;
		return true;
	}

	_waitTime -= elapsedTime;
	return false;
}

void SplashScreenState::Render() const
{
	std::cout << "SplashScreenState::Render\n";
}

void SplashScreenState::End()
{
	std::cout << "SplashScreenState::End\n";
}
