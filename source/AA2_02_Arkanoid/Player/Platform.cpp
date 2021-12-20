#include "Platform.h"

Platform::Platform(SDL_Renderer* renderer, const Vector2D<float>& position, const Vector2D<int>& size, const float& moveSpeed)
	: BoxCollider2D(), _sprite(nullptr), _rigidbody(nullptr), _position(), _size(), 
	_moveDirection(Vector2D<float>(0,0)), _moveSpeed(moveSpeed)
{
	_position = Vector2D<float>(position.X + size.X / 2 - size.Y / 2, position.Y + size.Y / 2 - size.X / 2); // Position inverted after rotating 90deg
	_size = Vector2D<int>(size.Y, size.X); // Size inverted after rotating 90deg

	// Initialize _sprite
	_sprite = new Image(renderer, Vector2D<int>(0, 0), PLATFORM_SOURCE_SIZE, Vector2D<int>(_position.X, _position.Y), size);
	_sprite->Init("../../resources/assets/images/platform.png");
	_sprite->Rotate(90);

	// Initialize _collider
	_boundary._rectBoundary = { (int)_position.X, (int)_position.Y, _size.X, _size.Y };
	//_collider = new BoxCollider2D({ (int)_position.X, (int)_position.Y, _size.X, _size.Y }); 

	// Initialize _rigidbody
	//_rigidbody = new Rigidbody2D(_collider, &_moveDirection);
	_rigidbody = new Rigidbody2D(this, &_moveDirection);
}

Platform::~Platform()
{
	delete _sprite;
	//delete _collider;
	delete _rigidbody;
}


void Platform::Update(const double& elapsedTime)
{
	if (!_rigidbody->WillBeColliding()) {
		Move(elapsedTime);
	}
	//_collider->SetBoundaryPosition(_position);
}

void Platform::Render() const
{
	_sprite->Draw();
}


void Platform::Move(const float& elapsedTime)
{
	_position += _moveDirection * _moveSpeed * elapsedTime;
	//_sprite->SetDestinationStart(_position);
	_sprite->SetDestinationStart(Vector2D<float>(_position.X - _size.X/2, _position.Y + _size.Y/2));
}

void Platform::SetMoveDirection(const Vector2D<float>& direction)
{
	//_moveDirection = direction;
	_moveDirection.X = direction.X;
	_moveDirection.Y = direction.Y;
}

BoxCollider2D* Platform::GetCollider() const
{
	//return _collider;
	BoxCollider2D bc;
	return &bc; // ---------------------- NEEDS REVISING
}

Rigidbody2D* Platform::GetRigidbody() const
{
	return _rigidbody;
}
