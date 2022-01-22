#include "Brick.h"

Brick::Brick(const Vector2D<float>& position, const Vector2D<int>& size, const int& spriteSourceWidthGap)
	: GameObject(Tag::BRICK), BoxCollider2D(this), _animatedSprite(nullptr),
	_spriteSourceWidthGap(spriteSourceWidthGap) , _playingAnimation(false)
{
	_position = Vector2D<float>(position.X + size.X / 2 - size.Y / 2, position.Y + size.Y / 2 - size.X / 2); // Position inverted after rotating 90deg
	_size = Vector2D<int>(size.Y, size.X); // Size inverted after rotating 90deg

	// Initialize _collider
	_boundary._rectBoundary = { (int)_position.X, (int)_position.Y, _size.X, _size.Y };
}


void Brick::Render() const
{
	_animatedSprite->Draw();
}

void Brick::OnCollisionEnter()
{
	if (_otherCollisionCollider->GetThisGameObject()->GetTag() == Tag::BALL) {
		GetsHit();
	}
}

void Brick::OnCollisionStay()
{
	if (_otherCollisionCollider->GetThisGameObject()->GetTag() == Tag::BALL) {
		GetsHit();
	}
}

Vector2D<float> Brick::GetPosition() const 
{ 
	return _position; 
}

void Brick::SetBrickBreaksCallback(std::function<void(const Vector2D<float>, const int&)> brickBreaksCallback)
{
	_brickBreaksCallback = brickBreaksCallback;
}

