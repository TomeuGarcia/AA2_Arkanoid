#include "Ball.h"


Ball::Ball(SDL_Renderer* renderer, const Vector2D<int>& size, const float& moveSpeed, Platform* lastPlatform)
	: GameObject(Tag::BALL, *lastPlatform->GetGrabPosition(), size), BoxCollider2D(this), _sprite(nullptr),
	_moveDirection(), _moveSpeed(moveSpeed), _ballStatus(BallStatus::FOLLOWING), 
	_followingPosition(lastPlatform->GetGrabPosition()), _lastPlatform(lastPlatform)
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
	Collider::Update();

	if (_ballStatus == BallStatus::FOLLOWING) {
		Follow();
	}
	else if (_ballStatus == BallStatus::MOVING) {
		Move(elapsedTime);
	}

}

void Ball::Render() const
{
	_sprite->Draw();
}


void Ball::OnCollisionEnter()
{
	if (_otherCollisionCollider->GetThisGameObject()->GetTag() == Tag::PLATFORM) {

		Vector2D<float> platformPosition = _otherCollisionCollider->GetThisGameObject()->GetCentrePosition();
		Vector2D<int> platformSize = _otherCollisionCollider->GetThisGameObject()->GetSize();

		if ((GetCentrePosition().Y < (platformPosition.Y - platformSize.Y / 4)) &&
			(GetCentrePosition().Y) > (platformPosition.Y - platformSize.Y /1.5)) {
			_moveDirection.Y = -1 - GetRandomBounce(8);
			_moveDirection.X *= -1;
		}
		else if (GetCentrePosition().Y > (platformPosition.Y + platformSize.Y / 4) &&
			(GetCentrePosition().Y) < (platformPosition.Y + platformSize.Y / 1.5)) {
			_moveDirection.Y = 1 + GetRandomBounce(8);
			_moveDirection.X *= -1;
		}
		else if (GetCentrePosition().Y > (platformPosition.Y - platformSize.Y / 4) &&
			GetCentrePosition().Y < (platformPosition.Y + platformSize.Y / 4)) {
			_moveDirection.Y = 0;
			_moveDirection.X *= -1;
		}
	}
	else if (_otherCollisionCollider->GetThisGameObject()->GetTag() == Tag::WALL) {
		_moveDirection.Y *= -1;
	}
	else if (_otherCollisionCollider->GetThisGameObject()->GetTag() == Tag::BRICK) {

		Vector2D<float> brickPosition = _otherCollisionCollider->GetThisGameObject()->GetCentrePosition();
		Vector2D<int> brickSize = _otherCollisionCollider->GetThisGameObject()->GetSize();

		if ((GetCentrePosition().Y >= brickPosition.Y - brickSize.Y / 2 - brickSize.Y / 4) &&
			(GetCentrePosition().Y <= brickPosition.Y + brickSize.Y / 2 + brickSize.Y / 4)) {
			_moveDirection.X *= -1 - GetRandomBounce(5);
		}
		else if ((GetCentrePosition().X >= brickPosition.X - brickSize.X / 2 - brickSize.X / 4) &&
			(GetCentrePosition().X <= brickPosition.X + brickSize.X / 2 + brickSize.X / 4)) {
			_moveDirection.Y *= -1 - GetRandomBounce(5);
		}
		else {
			_moveDirection *= -1;
		}
	}
	else {
		_moveDirection *= -1;
	}
}


void Ball::Move(const float& elapsedTime)
{
	
	_position += _moveDirection.Normalized() * _moveSpeed * elapsedTime;
	_sprite->SetDestinationStart(_position);
	SetBoundaryPosition(_position);
}

void Ball::Follow()
{
	_position = *_followingPosition;
	_sprite->SetDestinationStart(_position);
	SetBoundaryPosition(_position);
}

void Ball::SetMoveDirection(const Vector2D<float>& direction)
{
	_moveDirection = direction;
}

Rigidbody2D* Ball::GetRigidbody() const
{
	return _rigidbody;
}

void Ball::StartMoving()
{
	_ballStatus = BallStatus::MOVING;
	_moveDirection.X = _position.X > _lastPlatform->GetCentrePosition().X ? 1 : -1;
}

void Ball::StartFollowing(Platform* platformToFollow)
{
	_ballStatus = BallStatus::FOLLOWING;
	_lastPlatform = platformToFollow;
	_followingPosition = _lastPlatform->GetGrabPosition();
	_moveDirection = { 0,0 };
	Follow();
}

void Ball::SetLastPlatform(Platform* lastPlatform)
{
	_lastPlatform = lastPlatform;
}

Platform* Ball::GetLastPlatform() const
{
	return _lastPlatform;
}

float Ball::GetRandomBounce(const float& randomUnits) const
{
	return (rand() % static_cast<int>(randomUnits)) / randomUnits;
}
