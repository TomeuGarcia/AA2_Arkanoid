#include "FixBrick.h"

FixBrick::FixBrick(SDL_Renderer* renderer, const Vector2D<float>& position, const Vector2D<int>& size, const int& spriteSourceWidthGap) 
	: Brick(position, size, spriteSourceWidthGap) 
{
	// Initialize _animatedSprite
	_animatedSprite = new AnimatedImage(renderer, FIX_BRICK_SOURCE_START, BRICK_SOURCE_SIZE, TOTAL_BRICK_FRAMES,
		Vector2D<int>(position.X, position.Y), size);
	_animatedSprite->Init("../../resources/assets/images/bricks.png");
	_animatedSprite->Rotate(90);
}

FixBrick::~FixBrick()
{
	delete _animatedSprite;
}


void FixBrick::Update(const double& elapsedTime)
{
	Collider::Update();

	if (_playingAnimation) {
		_animatedSprite->Update(elapsedTime);
	}

	if (_animatedSprite->HasAnimationFinished()) {
		_playingAnimation = false;
		_animatedSprite->ResetAnimation();
	}
}


void FixBrick::GetsHit()
{
	_playingAnimation = true;
}
