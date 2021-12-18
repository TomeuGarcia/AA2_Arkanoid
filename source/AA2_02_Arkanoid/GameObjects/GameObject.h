#pragma once
#include "SDL.h"


class GameObject {

public:
	GameObject() : _renderer(nullptr) {}
	GameObject(SDL_Renderer* renderer) : _renderer(renderer) {}
	~GameObject() = default;

	virtual void Update(const double& elapsedTime) = 0;
	virtual void Render() = 0;

protected:
	SDL_Renderer* _renderer;

};