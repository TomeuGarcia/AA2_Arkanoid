#pragma once
#include "../Inputs/InputHandler.h"
#include "../Inputs/Keyboard.h"

class Player {
	
public:
	Player();
	~Player();

	void InitController(const int& moveUp, const int& moveDown);
	Controller* GetController() const;

private:
	Controller* _controller;

};