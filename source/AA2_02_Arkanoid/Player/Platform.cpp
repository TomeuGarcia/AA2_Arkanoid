#include "Platform.h"

Platform::Platform(SDL_Renderer* renderer, const Vector2D<float>& position, const Vector2D<int>& size,
	const float& moveSpeed, Vector2D<float>* grabPosition, const bool& isGrabbing, Player* player, Controller* controller)
	: GameObject(Tag::PLATFORM), BoxCollider2D(this), _sprite(nullptr), _rigidbody(nullptr),
	_moveDirection(Vector2D<float>(0, 0)), _startMoveSpeed(moveSpeed), _moveSpeed(moveSpeed), _grabPosition(grabPosition),
	_isGrabbing(isGrabbing), _player(player), _controller(controller)
{
	_position = Vector2D<float>(position.X + (size.X / 2) - (size.Y / 2), position.Y + (size.Y / 2) - (size.X / 2)); // Position inverted after rotating 90deg
	_size = Vector2D<int>(size.Y, size.X); // Size inverted after rotating 90deg

	// Initialize _sprite
	_sprite = new Image(renderer, Vector2D<int>(0, 0), PLATFORM_SOURCE_SIZE, Vector2D<int>(position.X, position.Y), size);
	_sprite->Init("../../resources/assets/images/platform.png");
	_sprite->Rotate(90);

	// Initialize _collider
	_boundary._rectBoundary = { (int)_position.X, (int)_position.Y, _size.X, _size.Y };

	// Initialize _rigidbody
	_rigidbody = new Rigidbody2D(this, &_moveDirection);
}

Platform::~Platform()
{
	delete _sprite;
	delete _rigidbody;
}


void Platform::Update(const double& elapsedTime)
{
	Collider::Update();

	SetMoveDirection(Vector2D<float>(0, _controller->GetAxis(AxisName::VERTICAL)));

	if (!_rigidbody->WillBeColliding()) {
		Move(elapsedTime);
		SetBoundaryPosition(_position);
	}
	
}

void Platform::Render() const
{
	_sprite->Draw();
}





void Platform::Move(const double& elapsedTime)
{
	_position += _moveDirection.Normalized() * _moveSpeed * elapsedTime;
	*_grabPosition += _moveDirection * _moveSpeed * elapsedTime;
	_sprite->SetDestinationStart(Vector2D<float>(_position.X - _size.X, _position.Y + _size.X));
}

void Platform::SetMoveDirection(const Vector2D<float>& direction)
{
	_moveDirection.X = direction.X;
	_moveDirection.Y = direction.Y;
}

Rigidbody2D* Platform::GetRigidbody() const
{
	return _rigidbody;
}

Vector2D<float>* Platform::GetGrabPosition() const
{
	return _grabPosition;
}

bool Platform::IsGrabbing() const
{
	return _isGrabbing;
}

void Platform::SetIsGrabbing(const bool& isGrabbing)
{
	_isGrabbing = isGrabbing;
}

Player* Platform::GetPlayer() const
{
	return _player;
}

void Platform::SetSize(const Vector2D<int>& size)
{
	_position.X += (size.X - _size.X) / 2;
	_position.Y += (size.Y - _size.Y) / 2;
	_size = size;

	_boundary._rectBoundary = { (int)_position.X, (int)_position.Y, _size.X, _size.Y };

	_sprite->SetDestinationRect(Vector2D<int>(_position.X, _position.Y), _size);

}

void Platform::ResetSize()
{
	SetSize(Vector2D<int>(PLATFORM_DESTINATION_HEIGHT, PLATFORM_DESTINATION_WIDTH)); 
}

float Platform::GetMoveSpeed() const{
	return _moveSpeed;
}

void Platform::SetMoveSpeed(const float& moveSpeed) {
	_moveSpeed = moveSpeed;
}

void Platform::ResetMoveSpeed() {
	_moveSpeed = _startMoveSpeed;
}
