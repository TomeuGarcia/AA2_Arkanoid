#include "SplashScreenScene.h"

SplashScreenScene::SplashScreenScene(SDL_Renderer* renderer) 
	: Scene(renderer), _waitTime(SPLASH_WAIT_TIME)
{
}

SplashScreenScene::~SplashScreenScene()
{
}

void SplashScreenScene::DoStart()
{
	InitBackground();
}

bool SplashScreenScene::Update(const double& elapsedTime)
{
	if (_waitTime <= 0.0f) {
		_nextScene = Scenes::MAIN_MENU;
		return true;
	}

	_waitTime -= elapsedTime;
	UpdateSceneGameObjects(elapsedTime);

	return false;
}

void SplashScreenScene::Render() const
{
	SDL_RenderClear(_renderer);
	RenderSceneGameObjects();
	SDL_RenderPresent(_renderer);
}

void SplashScreenScene::End()
{
	DeleteSceneGameObjects();
}

void SplashScreenScene::InitBackground()
{
	ImageGameObject* background = new ImageGameObject(_renderer, "../../resources/assets/images/arkanoidSplashScreen.png",
		Vector2D<int>(0,0), SCREEN_SIZE, Vector2D<int>(0, 0), SCREEN_SIZE);

	AddSceneGameObject(background);
}
