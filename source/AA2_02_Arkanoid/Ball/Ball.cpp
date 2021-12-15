#include "Ball.h"

Ball::Ball(const Vector2D<int>& position, const float& moveSpeed)
	: _sprite(nullptr), _position(position), _size(BALL_DESTINATION_SIZE), _moveDistance(0.0f), _moveSpeed(moveSpeed)
{
}

Ball::~Ball()
{
	delete _sprite;
}

void Ball::InitSprite(SDL_Renderer* renderer)
{
	_sprite = new Image(renderer, Vector2D<int>(0, 0), BALL_SOURCE_SIZE, _position, BALL_DESTINATION_SIZE);
	_sprite->Init("../../resources/assets/images/ball.png");
}

void Ball::Move(const Vector2D<int>& direction, const float& elapsedTime)
{
	_moveDistance += _moveSpeed * elapsedTime;

	_position += Vector2D<int>(-direction.X, direction.Y) * _moveDistance;
	_sprite->SetDestinationStart(_position);

	if (_moveDistance >= 1.0f) _moveDistance = 0.0f;
}

void Ball::Draw() const
{
	_sprite->Draw();
}
