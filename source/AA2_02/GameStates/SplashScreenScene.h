#pragma once
#include "GameScene.h"

class SplashScreenScene : public Scene {
public:
	SplashScreenScene(SDL_Renderer* renderer);
	~SplashScreenScene();
	virtual void DoStart();
	virtual bool Update(float elapsedTime);
	virtual void Render() const;
	virtual void End();

private:
	float _waitTime;
};