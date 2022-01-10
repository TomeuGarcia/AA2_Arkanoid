#include "AnimatedImage.h"

AnimatedImage::AnimatedImage(SDL_Renderer* renderer, const Vector2D<int>& sourceStartCorner, const Vector2D<int>& sourceFrameSize,
	const int& numberOfFrames, const Vector2D<int>& destinationStartCorner, const Vector2D<int>& destinationSize)
	: Render(renderer, sourceStartCorner, sourceFrameSize, destinationStartCorner, destinationSize), 
	_frameWidth(sourceFrameSize.X), _currentFrame(0), _numberOfFrames(numberOfFrames), _accumulatedElapsedTime(0), _frameSpeed(20.0f)
{}

AnimatedImage::~AnimatedImage() {
	SDL_DestroyTexture(_texture);
}

void AnimatedImage::Draw() {
	SDL_RenderCopyEx(_renderer, _texture, &_sourceRect, &_destinationRect, _rotationAngleInDegrees, &_rotationPivot, _textureFlip);
}

void AnimatedImage::Update(const double& elapsedTime)
{
	_accumulatedElapsedTime += elapsedTime;
	_currentFrame = (int)(_accumulatedElapsedTime * _frameSpeed) % _numberOfFrames;
	_sourceRect.x = _frameWidth * _currentFrame;
}

bool AnimatedImage::HasAnimationFinished() const
{
	return _currentFrame == _numberOfFrames-1;
}

void AnimatedImage::ForceNextFrame()
{
	++_currentFrame;
	++_accumulatedElapsedTime;
	_sourceRect.x = _frameWidth * _currentFrame;
}

void AnimatedImage::ResetAnimation()
{
	_currentFrame = 0;
	_accumulatedElapsedTime = 0;
	_sourceRect.x = _frameWidth * _currentFrame;
}
