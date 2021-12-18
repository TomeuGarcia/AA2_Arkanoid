#pragma once
#include "SDL.h"


class GameObject {

public:
	GameObject() = default;
	virtual ~GameObject() = default;

	virtual void Update(const double& elapsedTime) = 0;
	virtual void Render() const = 0;

};