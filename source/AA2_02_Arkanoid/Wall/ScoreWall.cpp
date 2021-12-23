#include "ScoreWall.h"

ScoreWall::ScoreWall(const Vector2D<float>& position, const Vector2D<int>& size, Platform* ownerPlatform)
	: Wall(position, size), _ownerPlatform(ownerPlatform), _startKickOffCallback()
{
}

void ScoreWall::Update(const double& elapsedTime)
{
	Collider::Update();
}

void ScoreWall::OnCollisionEnter()
{
	if (_otherCollisionCollider->GetThisGameObject()->GetTag() == Tag::BALL) {
		_startKickOffCallback(_ownerPlatform);
	}
}

void ScoreWall::SetStartKickOffCallback(std::function<void(Platform*)> startKickOffCallback)
{
	_startKickOffCallback = startKickOffCallback;
}
