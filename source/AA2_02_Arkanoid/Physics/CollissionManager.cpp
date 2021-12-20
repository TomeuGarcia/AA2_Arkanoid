#include "CollissionManager.h"

CollisionManager::CollisionManager()
	: _upperWallCollider(nullptr), _lowerWallCollider(nullptr),
	_rightWallCollider(nullptr), _leftWallCollider(nullptr),
	_platform1Collider(nullptr), _platform2Collider(nullptr),
	_rigidbodyGameObjectsRigidbodies(), _rigidbodylessGameObjectsColliders()
{
}

CollisionManager::~CollisionManager()
{
	delete _upperWallCollider;
	delete _lowerWallCollider;
	delete _rightWallCollider;
	delete _leftWallCollider;

	_rigidbodyGameObjectsRigidbodies.clear();
	_rigidbodylessGameObjectsColliders.clear();
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



void CollisionManager::AddRigidbodyGameObject(Rigidbody2D* gameObjectRigidbody2D)
{
	_rigidbodyGameObjectsRigidbodies.push_back(gameObjectRigidbody2D);
}

void CollisionManager::AddRigidbodylessGameObject(Collider* gameObjectCollider)
{
	_rigidbodylessGameObjectsColliders.push_back(gameObjectCollider);
}


void CollisionManager::Update()
{
	// 1. Iterate all _rigidbodyGameObjects
	// 2. for each element in _rigidbodyGameObjects, check if they collide with 
	// all other _rigidbodyGameObjects and all _rigidbodylessGameObjects

	int currentRigidbodyGameObject{ 0 };
	for (int i{ 0 }; i < _rigidbodyGameObjectsRigidbodies.size(); ++i) {

		// (1/2) Iterate other rigidbody-GameObjects' Rigidbodies
		for (int j{ 0 }; j < currentRigidbodyGameObject; ++j) {
			CheckCollision(_rigidbodyGameObjectsRigidbodies[i], _rigidbodyGameObjectsRigidbodies[j]->GetCollider());
		}
		// (2/2) Iterate other rigidbody-GameObjects' Rigidbodies
		for (int j{ currentRigidbodyGameObject+1 }; j < _rigidbodyGameObjectsRigidbodies.size(); ++j) {
			CheckCollision(_rigidbodyGameObjectsRigidbodies[i], _rigidbodyGameObjectsRigidbodies[j]->GetCollider());
		}

		// Iterate rigidbodyless-GameObjects' Colliders
		for (int j{ 0 }; j < _rigidbodylessGameObjectsColliders.size(); ++j) {
			CheckCollision(_rigidbodyGameObjectsRigidbodies[i], _rigidbodylessGameObjectsColliders[j]);
		}
	}

}

void CollisionManager::CheckCollision(Rigidbody2D* rigidbody, Collider* otherCollider)
{
	rigidbody->SetWillBeColliding(rigidbody->GetCollider()->IsCollidingWithCollider(otherCollider));
}
