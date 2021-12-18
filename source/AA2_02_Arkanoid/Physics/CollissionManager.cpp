#include "CollissionManager.h"

CollisionManager::CollisionManager()
	: _upperWallCollider(nullptr), _lowerWallCollider(nullptr),
	_rightWallCollider(nullptr), _leftWallCollider(nullptr),
	_platform1Collider(nullptr), _platform2Collider(nullptr)
{
}

CollisionManager::~CollisionManager()
{
	delete _upperWallCollider;
	delete _lowerWallCollider;
	delete _rightWallCollider;
	delete _leftWallCollider;
}

void CollisionManager::Init(BoxCollider2D* platform1Collider, BoxCollider2D* platform2Collider)
{
	_upperWallCollider = new BoxCollider2D({ 10, 10,  780, 40 });
	_lowerWallCollider = new BoxCollider2D({ 10, 485,  780, 50 });
	_rightWallCollider = new BoxCollider2D({ 10, 25,  20, 550 });
	_leftWallCollider = new BoxCollider2D({ 780, 25,  20, 550 });

	_platform1Collider = platform1Collider;
	_platform2Collider = platform2Collider;
}

bool CollisionManager::Platform1UpperWallCollision() const
{
	return _platform1Collider->IsCollidingWithCollider(_upperWallCollider);
}

bool CollisionManager::Platform1LowerWallCollision() const
{
	return _platform1Collider->IsCollidingWithCollider(_lowerWallCollider);
}

bool CollisionManager::Platform2UpperWallCollision() const
{
	return _platform2Collider->IsCollidingWithCollider(_upperWallCollider);
}

bool CollisionManager::Platform2LowerWallCollision() const
{
	return _platform2Collider->IsCollidingWithCollider(_lowerWallCollider);
}
