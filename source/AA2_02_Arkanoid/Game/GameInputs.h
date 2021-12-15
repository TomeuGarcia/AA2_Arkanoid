#pragma once
#include "../Inputs/InputHandler.h"
#include "../Inputs/Keyboard.h"

class GameInputs {

public:
	GameInputs();
	~GameInputs();
	Controller* GetControllerPlayer1() const;
	Controller* GetControllerPlayer2() const;

private:
	void InitPlayerController(Controller* controller, const int& moveUp, const int& moveDown);
	Controller* _controllerPlayer1;
	Controller* _controllerPlayer2;

};