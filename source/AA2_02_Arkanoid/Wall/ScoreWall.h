#pragma once
#include <functional>
#include "Wall.h"
#include "../Player/Platform.h"


class ScoreWall : public Wall {

public:
	ScoreWall(const Vector2D<float>& position, const Vector2D<int>& size, Platform* ownerPlatform);

	virtual void Update(const double& elapsedTime) override;

	virtual void OnCollisionEnter();

	void SetStartKickOffCallback(std::function<void()> startKickOffCallback);

private:
	Platform* _ownerPlatform;
	std::function<void()> _startKickOffCallback;
};