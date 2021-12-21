#pragma once
#include "../Constants/Constants.h"
#include "../GameObjects/GameObject.h"
#include "Rigidbody2D.h"
#include <vector>


class CollisionManager {

public:
	CollisionManager();
	~CollisionManager();

	void AddGameObjectRigidbody(Rigidbody2D* gameObject);
	void AddRigidbodylessGameObjectCollider(Collider* gameObject);
	void Update();
	void CheckCollision(Rigidbody2D* rigidbody, Collider* otherCollider);

private:
	std::vector<Rigidbody2D*> _rigidbodies;
	std::vector<Collider*> _rigidbodylessColliders;
};