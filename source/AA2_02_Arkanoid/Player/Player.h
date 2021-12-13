#pragma once
#include "../Inputs/InputHandler.h"
#include "../Inputs/Keyboard.h"

#include "Platform.h"

class Player {
	
public:
	Player();
	~Player();

	void InitController(const int& moveUp, const int& moveDown);
	Controller* GetController() const;
	Platform* GetPlatform() const;
	void MovePlatform(const Vector2D<int>& direction, const float& speed);

private:
	Controller* _controller;
	Platform* _platform;
};