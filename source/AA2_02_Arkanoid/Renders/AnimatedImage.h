#pragma once
#include "Render.h"

class AnimatedImage : public Render
{

public:
	AnimatedImage(SDL_Renderer* renderer, const Vector2D<int>& sourceStartCorner, const Vector2D<int>& sourceFrameSize,
		const int& numberOfFrames, const Vector2D<int>& destinationStartCorner, const Vector2D<int>& destinationSize);
	~AnimatedImage();
	virtual void Draw() override;
	virtual void Update(const double& elapsedTime) override;

private:
	int _frameWidth;
	int _currentFrame;
	int _numberOfFrames;
	double _accumulatedElapsedTime;
	float _frameSpeed;
};

