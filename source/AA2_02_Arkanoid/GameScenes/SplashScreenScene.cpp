#include "SplashScreenScene.h"

SplashScreenScene::SplashScreenScene(SDL_Renderer* renderer) : Scene(renderer), _background(nullptr), _waitTime(SPLASH_WAIT_TIME)
{
}

SplashScreenScene::~SplashScreenScene()
{
}

void SplashScreenScene::DoStart()
{
	std::cout << "SplashScreenScene::Start\n";

	InitBackground();
}

void SplashScreenScene::HandleEvents() {}

bool SplashScreenScene::Update(const double& elapsedTime)
{
	std::cout << "SplashScreenScene::Update\n";

	if (_waitTime <= 0.0f) {
		_nextScene = Scenes::MAIN_MENU;
		return true;
	}

	_waitTime -= elapsedTime;
	_background->Update(elapsedTime);

	return false;
}

void SplashScreenScene::Render() const
{
	std::cout << "SplashScreenScene::Render\n";

	SDL_RenderClear(_renderer);
	_background->Render();
	SDL_RenderPresent(_renderer);
}

void SplashScreenScene::End()
{
	std::cout << "SplashScreenScene::End\n";

	delete _background;
}

void SplashScreenScene::InitBackground()
{
	_background = new ImageGameObject(_renderer, "../../resources/assets/images/arkanoidSplashScreen.png", 
		Vector2D<int>(0,0), SCREEN_SIZE, Vector2D<int>(0, 0), SCREEN_SIZE);
}
