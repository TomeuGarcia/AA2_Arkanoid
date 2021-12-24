#include "HeavyBrick.h"

HeavyBrick::HeavyBrick(SDL_Renderer* renderer, const Vector2D<float>& position, const Vector2D<int>& size, const int& spriteSourceWidthGap,
	const int& points, const int& lives)
	: Brick(position, size, spriteSourceWidthGap), 	_points(points), _lifeSystem(lives) 
{
	// Initialize _animatedSprite
	_animatedSprite = new AnimatedImage(renderer, HEAVY_BRICK_SOURCE_START, BRICK_SOURCE_SIZE, TOTAL_BRICK_FRAMES+1,
		Vector2D<int>(position.X, position.Y), size);
	_animatedSprite->Init("../../resources/assets/images/bricks.png");
	_animatedSprite->Rotate(90);
}

HeavyBrick::~HeavyBrick()
{
	delete _animatedSprite;
}

void HeavyBrick::Update(const double& elapsedTime)
{
	Collider::Update();

	if (_playingAnimation) {
		_animatedSprite->Update(elapsedTime);
	}

	if (_animatedSprite->AnimationFinished()) {
		_playingAnimation = false;
		GetsDestroyed();
	}
}


void HeavyBrick::GetsHit()
{
	_lifeSystem.LoseLives(1);
	if (_lifeSystem.HasNoLivesLeft()) {
		_playingAnimation = true;
	}
	else {
		_animatedSprite->ForceNextFrame();
	}	
}

void HeavyBrick::GetsDestroyed()
{
	_brickBreaksCallback(_points);
	SetActive(false);
}
