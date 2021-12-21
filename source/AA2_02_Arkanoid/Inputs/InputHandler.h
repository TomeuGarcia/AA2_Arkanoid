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

	void HandleEvents();
	void AddController(Controller* controllerToAdd);
	void RemoveAllControllers();

private:
	static InputHandler* _instance;
	std::vector<Controller*> _controllers;

	std::unordered_map<int, ActionType> _actionTypeMapping;
};