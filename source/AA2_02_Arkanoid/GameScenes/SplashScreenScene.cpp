#include "SplashScreenScene.h"

SplashScreenScene::SplashScreenScene(SDL_Renderer* renderer) : Scene(renderer), _background(nullptr), _waitTime(SPLASH_WAIT_TIME)
{
}

SplashScreenScene::~SplashScreenScene()
{
}

void SplashScreenScene::DoStart()
{
	InitBackground();
	std::cout << "SplashScreenScene::Start\n";
}

bool SplashScreenScene::Update(const double& elapsedTime)
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
	SDL_RenderClear(_renderer);
	_background->Draw();
	SDL_RenderPresent(_renderer);
	std::cout << "SplashScreenScene::Render\n";
}

void SplashScreenScene::End()
{
	delete _background;
	std::cout << "SplashScreenScene::End\n";
}

void SplashScreenScene::InitBackground()
{
	_background = new Image(_renderer,Vector2D<int>(0,0),Vector2D<int>(SCREEN_WIDTH, SCREEN_HEIGHT), 
							Vector2D<int>(0, 0), Vector2D<int>(SCREEN_WIDTH, SCREEN_HEIGHT));
	_background->Init("../../resources/assets/images/arkanoidSplashScreen.png");
}
