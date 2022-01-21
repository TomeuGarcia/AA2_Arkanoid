#include "PowerUp.h"

PowerUp::PowerUp(const Vector2D<float>& position, const Vector2D<int>& size, 
	const Vector2D<float>& moveDirection, const float& moveSpeed)
	: GameObject(Tag::POWER_UP, position, size), BoxCollider2D(this),
	_sprite(nullptr), _moveDirection(moveDirection), _moveSpeed(moveSpeed)
{
	// Initialize _collider
	_boundary._rectBoundary = { (int)_position.X, (int)_position.Y, _size.X, _size.Y };

	// Initialize _rigidbody
	_rigidbody = new Rigidbody2D(this, &_moveDirection);
}

void PowerUp::Update(const double& elapsedTime)
{
	Collider::Update();
	Move(elapsedTime);
}

void PowerUp::Render() const
{
	_sprite->Draw();
}

Rigidbody2D* PowerUp::GetRigidbody() const
{
	return _rigidbody;
}

void PowerUp::DoFinishEffect(Platform* platform)
{
	platform->ResetSize();
	platform->ResetMoveSpeed();
}

void PowerUp::OnCollisionEnter()
{
	if (_otherCollisionCollider->GetThisGameObject()->GetTag() == Tag::PLATFORM) {
		//DoEffect(dynamic_cast<Platform*>(_otherCollisionCollider->GetThisGameObject()));
		_position.X = 0;
		_position.Y = 0;
		SetActive(false);
	}
	else if (_otherCollisionCollider->GetThisGameObject()->GetTag() == Tag::WALL) {
		_position.X = 0;
		_position.Y = 0;
		SetActive(false);
	}
}

void PowerUp::Move(const double& elapsedTime)
{
	_position += _moveDirection.Normalized() * _moveSpeed * elapsedTime;
	_sprite->SetDestinationStart(_position);
	SetBoundaryPosition(_position);
}
