#pragma once
#include "GameScene.h"
#include "../Renders/Image.h"
class SplashScreenScene : public Scene {
public:
	SplashScreenScene(SDL_Renderer* renderer);
	~SplashScreenScene();
	virtual void DoStart();
	virtual void HandleEvents();
	virtual bool Update(const double& elapsedTime);
	virtual void Render() const;
	virtual void End();
	void InitBackground();

private:
	float _waitTime;
	Image* _background;
};