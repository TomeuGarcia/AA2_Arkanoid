#pragma once
#include <functional>
#include "Wall.h"
#include "../Player/Platform.h"


class ScoreWall : public Wall {

public:
	ScoreWall(const Vector2D<float>& position, const Vector2D<int>& size, Platform* ownerPlatform);

	virtual void Update(const double& elapsedTime) override;

	void SetStartKickOffCallback(std::function<void(Platform*)> startKickOffCallback);

private:
	virtual void OnCollisionEnter();
	virtual void OnCollisionStay();

	Platform* _ownerPlatform;
	std::function<void(Platform*)> _startKickOffCallback;
};