#include "CollissionManager.h"

CollisionManager::CollisionManager()
	: _upperWallCollider(nullptr), _lowerWallCollider(nullptr),
	_rightWallCollider(nullptr), _leftWallCollider(nullptr),
	_platform1Collider(nullptr), _platform2Collider(nullptr),
	_rigidbodies(), _rigidbodylessColliders()
{
}

CollisionManager::~CollisionManager()
{
	delete _upperWallCollider;
	delete _lowerWallCollider;
	delete _rightWallCollider;
	delete _leftWallCollider;

	_rigidbodies.clear();
	_rigidbodylessColliders.clear();
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



void CollisionManager::AddGameObjectRigidbody(Rigidbody2D* rigidbody2D)
{
	_rigidbodies.push_back(rigidbody2D);
}

void CollisionManager::AddRigidbodylessGameObjectCollider(Collider* collider)
{
	_rigidbodylessColliders.push_back(collider);
}


void CollisionManager::Update()
{
	// 1. Iterate all _rigidbodies
	// 2. for each element in _rigidbodies, check if they collide with 
	// all other _rigidbodies and all _rigidbodylessColliders

	int currentRigidbody{ 0 };
	for (int i{ 0 }; i < _rigidbodies.size(); ++i) {
		_rigidbodies[currentRigidbody]->SetWillBeColliding(false);

		// 1.(1/2) Iterate other rigidbody-GameObjects' Rigidbodies
		for (int j{ 0 }; j < currentRigidbody; ++j) {
			CheckCollision(_rigidbodies[i], _rigidbodies[j]->GetCollider());
		}
		// 1.(2/2) Iterate other rigidbody-GameObjects' Rigidbodies
		for (int j{ ++currentRigidbody }; j < _rigidbodies.size(); ++j) {
			CheckCollision(_rigidbodies[i], _rigidbodies[j]->GetCollider());
		}

		// 2. Iterate rigidbodyless-GameObjects' Colliders
		for (int j{ 0 }; j < _rigidbodylessColliders.size(); ++j) {
			CheckCollision(_rigidbodies[i], _rigidbodylessColliders[j]);
		}
	}
}

void CollisionManager::CheckCollision(Rigidbody2D* rigidbody, Collider* otherCollider)
{
	bool willCollide = rigidbody->GetCollider()->WillBeCollidingWithColliderOnDirection(rigidbody->GetMoveDirection(), otherCollider);
	if (willCollide) { 
		rigidbody->SetWillBeColliding(willCollide);
	}
}
