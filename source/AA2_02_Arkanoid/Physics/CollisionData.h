#pragma once
#include "../GameObjects/Tags.h"
#include "Vector2D.h"


struct CollisionData {

	CollisionData() : _otherTag(Tag::NONE), _otherCentrePosition() 
	{}
	CollisionData(Tag otherTag, Vector2D<float> otherCentrePosition)
		: _otherTag(otherTag), _otherCentrePosition(otherCentrePosition) 
	{}
	CollisionData(CollisionData* collisionData)
		: _otherTag(collisionData->_otherTag), _otherCentrePosition(collisionData->_otherCentrePosition) 
	{}

	~CollisionData() = default;


	Tag _otherTag;
	Vector2D<float> _otherCentrePosition;

};