#include "SplashScreenScene.h"

SplashScreenScene::SplashScreenScene(SDL_Renderer* renderer) : Scene(renderer)
{
}

SplashScreenScene::~SplashScreenScene()
{
}

void SplashScreenScene::DoStart()
{
	std::cout << "SplashScreenScene::Start\n";
	
	_waitTime = 3.0f;
}

bool SplashScreenScene::Update(float elapsedTime)
{
	std::cout << "SplashScreenScene::Update\n";
	if (_waitTime <= 0.0f) {
		_nextScene = Scenes::MAIN_MENU;
		return true;
	}

	_waitTime -= elapsedTime;
	return false;
}

void SplashScreenScene::Render() const
{
	std::cout << "SplashScreenScene::Render\n";
}

void SplashScreenScene::End()
{
	std::cout << "SplashScreenScene::End\n";
}
