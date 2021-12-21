#pragma once
#include "../GameObjects/Tags.h"
#include "Vector2D.h"


struct CollisionData {

	CollisionData() = default;
	CollisionData(Tag otherTag, Vector2D<int> otherCentrePosition)
		: _otherTag(otherTag), _otherCentrePosition(otherCentrePosition) 
	{}
	CollisionData(CollisionData* collisionData)
		: _otherTag(collisionData->_otherTag), _otherCentrePosition(collisionData->_otherCentrePosition) 
	{}

	~CollisionData() = default;


	Tag _otherTag;
	Vector2D<int> _otherCentrePosition;

};