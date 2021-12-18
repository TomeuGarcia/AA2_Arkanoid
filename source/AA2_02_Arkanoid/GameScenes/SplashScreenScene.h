#pragma once
#include "GameScene.h"
#include "../Renders/Image.h"
#include "../GameObjects/ImageGameObject.h"


class SplashScreenScene : public Scene {
public:
	SplashScreenScene(SDL_Renderer* renderer);
	~SplashScreenScene();
	virtual void DoStart() override;
	virtual void HandleEvents() override;
	virtual bool Update(const double& elapsedTime) override;
	virtual void Render() const override;
	virtual void End() override;
	void InitBackground();

private:
	float _waitTime;
	ImageGameObject* _background;
};