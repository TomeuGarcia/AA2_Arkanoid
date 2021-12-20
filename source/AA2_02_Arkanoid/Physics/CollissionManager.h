#pragma once
#include "../Constants/Constants.h"
#include "../GameObjects/GameObject.h"
#include "Rigidbody2D.h"
#include <vector>


class CollisionManager {

public:
	CollisionManager();
	~CollisionManager();

	void Init(BoxCollider2D* platform1Collider, BoxCollider2D* platform2Collider);
	bool Platform1UpperWallCollision() const;
	bool Platform1LowerWallCollision() const;
	bool Platform2UpperWallCollision() const;
	bool Platform2LowerWallCollision() const;


	void AddRigidbodyGameObject(Rigidbody2D* gameObject);
	void AddRigidbodylessGameObject(Collider* gameObject);
	void Update();
	void CheckCollision(Rigidbody2D* rigidbody, Collider* otherCollider);

private:
	std::vector<Rigidbody2D*> _rigidbodyGameObjectsRigidbodies;
	std::vector<Collider*> _rigidbodylessGameObjectsColliders;




	Collider* _upperWallCollider;
	Collider* _lowerWallCollider;
	Collider* _rightWallCollider;
	Collider* _leftWallCollider;

	Collider* _platform1Collider;
	Collider* _platform2Collider;
};