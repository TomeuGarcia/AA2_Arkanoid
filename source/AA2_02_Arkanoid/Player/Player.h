#pragma once
#include "../Inputs/InputHandler.h"
#include "../Inputs/Keyboard.h"

#include "Platform.h"

class Player {
	
public:
	Player(Controller* controller);
	~Player();

	void InitPlatform(SDL_Renderer* renderer, const Vector2D<float>& position, const Vector2D<int>& size, const float& moveSpeed);

	Controller* GetController() const;
	Platform* GetPlatform() const;
	void MovePlatform(const Vector2D<float>& direction, const double& elapsedTime);

private:
	Controller* _controller;
	Platform* _platform;
};