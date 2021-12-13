#include "SplashScreenScene.h"

SplashScreenScene::SplashScreenScene(SDL_Renderer* renderer) : Scene(renderer)
{
}

SplashScreenScene::~SplashScreenScene()
{
}

void SplashScreenScene::DoStart()
{
	InitBackground();
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
	_background = new Image(_renderer,Vector2D<int>(0,0),Vector2D<int>(800,600), Vector2D<int>(0, 0), Vector2D<int>(800, 600));
	_background->Init("../../resources/Assets/Images/arkanoidSplashScreen.png");
}