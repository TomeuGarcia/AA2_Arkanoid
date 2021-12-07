#pragma once
#include <vector>
#include <SDL.h>
#include "Event.h"
#include "Controller.h"


class InputHandler {

private:
	InputHandler();
public:
	static InputHandler* GetInstance();

	void HandleEvents(const SDL_Event* eventToHandle);
	void AddController(Controller* controllerToAdd);

private:
	static InputHandler* _instance;
	std::vector<Controller*> _controllers;

	std::map<int, ActionType> _actionTypeMapping;
};