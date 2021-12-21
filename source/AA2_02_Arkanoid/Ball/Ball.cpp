#include "Ball.h"


Ball::Ball(SDL_Renderer* renderer, const Vector2D<float>& position, const Vector2D<int>& size, const Vector2D<float>& moveDirection, const float& moveSpeed)
	: GameObject(Tag::BALL), BoxCollider2D(), _sprite(nullptr), _position(position), _size(size),
	_moveDirection(moveDirection), _moveSpeed(moveSpeed)
	
{
	// Initialize _sprite
	_sprite = new Image(renderer, Vector2D<int>(0, 0), BALL_SOURCE_SIZE, Vector2D<int>(_position.X, _position.Y), _size);
	_sprite->Init("../../resources/assets/images/ball.png");

	// Initialize _collider
	_boundary._rectBoundary = { (int)_position.X, (int)_position.Y, _size.X, _size.Y };

	// Initialize _rigidbody
	_rigidbody = new Rigidbody2D(this, &_moveDirection);
}

Ball::~Ball()
{
	delete _sprite;
}


void Ball::Update(const double& elapsedTime)
{
	if (!_rigidbody->WillBeColliding()) {
		Move(elapsedTime);
		SetBoundaryPosition(_position);
	}
	else {
		_moveDirection *= -1;
	}
}

void Ball::Render() const
{
	_sprite->Draw();
}


void Ball::Move(const float& elapsedTime)
{
	_position += _moveDirection * _moveSpeed * elapsedTime;
	_sprite->SetDestinationStart(_position);
}

void Ball::SetMoveDirection(const Vector2D<float>& direction)
{
	_moveDirection = direction;
}

Rigidbody2D* Ball::GetRigidbody() const
{
	return _rigidbody;
}
