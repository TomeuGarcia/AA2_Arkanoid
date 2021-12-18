#pragma once
#include "../Constants/Constants.h"
#include "BoxCollider2D.h"
#include "../GameObjects/GameObject.h"
#include <list>


class CollisionManager {

public:
	CollisionManager();
	~CollisionManager();

	void Init(BoxCollider2D* platform1Collider, BoxCollider2D* platform2Collider);
	bool Platform1UpperWallCollision() const;
	bool Platform1LowerWallCollision() const;
	bool Platform2UpperWallCollision() const;
	bool Platform2LowerWallCollision() const;



private:
	std::list<GameObject*> staticGameObjects;
	std::list<std::list<GameObject*>> movingGameObjects;




	Collider* _upperWallCollider;
	Collider* _lowerWallCollider;
	Collider* _rightWallCollider;
	Collider* _leftWallCollider;

	Collider* _platform1Collider;
	Collider* _platform2Collider;
};