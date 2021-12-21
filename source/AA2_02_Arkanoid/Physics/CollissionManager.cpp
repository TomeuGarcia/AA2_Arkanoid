#include "CollissionManager.h"

CollisionManager::CollisionManager()
	: _rigidbodies(), _rigidbodylessColliders()
{
}

CollisionManager::~CollisionManager()
{
	_rigidbodies.clear();
	_rigidbodylessColliders.clear();
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
	ResetCollisions();
	CheckForCollisions();
}


void CollisionManager::ResetCollisions()
{
	for (int i{ 0 }; i < _rigidbodies.size(); ++i) {
		_rigidbodies[i]->SetWillBeColliding(false);
	}
	for (int i{ 0 }; i < _rigidbodylessColliders.size(); ++i) {
		_rigidbodylessColliders[i]->_willBeColliding = false;
	}
}

void CollisionManager::CheckForCollisions()
{
	// 1. Iterate all _rigidbodies
	// 2. for each element in _rigidbodies, check if they collide with 
	// all other _rigidbodies and all _rigidbodylessColliders

	int currentRigidbody{ 0 };
	for (int i{ 0 }; i < _rigidbodies.size(); ++i) {	

		// 1.(1/2) Iterate other rigidbody-GameObjects' Rigidbodies
		for (int j{ 0 }; j < currentRigidbody; ++j) {
			if (_rigidbodies[j]->GetCollider()->GetThisGameObject()->IsActive()) {
				CheckCollision(_rigidbodies[i], _rigidbodies[j]->GetCollider());
			}
		}
		// 1.(2/2) Iterate other rigidbody-GameObjects' Rigidbodies
		for (int j{ ++currentRigidbody }; j < _rigidbodies.size(); ++j) {
			if (_rigidbodies[j]->GetCollider()->GetThisGameObject()->IsActive()) {
				CheckCollision(_rigidbodies[i], _rigidbodies[j]->GetCollider());
			}
		}

		// 2. Iterate rigidbodyless-GameObjects' Colliders
		for (int j{ 0 }; j < _rigidbodylessColliders.size(); ++j) {
			if (_rigidbodylessColliders[j]->GetThisGameObject()->IsActive()) {
				CheckCollision(_rigidbodies[i], _rigidbodylessColliders[j]);
			}
		}
	}
}

void CollisionManager::CheckCollision(Rigidbody2D* rigidbody, Collider* otherCollider)
{
	bool willCollide = rigidbody->GetCollider()->WillBeCollidingWithColliderOnDirection(rigidbody->GetMoveDirection(), otherCollider);
	if (willCollide) { 
		rigidbody->SetWillBeColliding(true);

		rigidbody->GetCollider()->SetCollisionData(CollisionData(otherCollider->GetThisGameObject()->GetTag(),
				otherCollider->GetThisGameObject()->GetCentrePosition())
		);

		otherCollider->SetCollisionData(CollisionData(rigidbody->GetCollider()->GetThisGameObject()->GetTag(),
			rigidbody->GetCollider()->GetThisGameObject()->GetCentrePosition())
		);
	}
}
