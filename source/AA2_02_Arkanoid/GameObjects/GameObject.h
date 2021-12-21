#pragma once
#include "SDL.h"
#include "Tags.h"

class GameObject {

public:
	GameObject() = default;
	GameObject(const Tag& tag) : _tag(tag) {}
	virtual ~GameObject() = default;

	virtual void Update(const double& elapsedTime) = 0;
	virtual void Render() const = 0;

	Tag GetTag() const { return _tag; }

protected:
	Tag _tag;
};