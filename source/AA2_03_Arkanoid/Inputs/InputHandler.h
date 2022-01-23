#pragma once
#include <vector>
#include <SDL.h>
#include "Event.h"
#include "Controller.h"
#include "../Physics/Vector2D.h"


class InputHandler {

private:
	InputHandler();
public:
	static InputHandler* GetInstance();

	void HandleEvents();
	void AddController(Controller* controllerToAdd);
	void RemoveAllControllers();
	Vector2D<int> GetMouseScreenPosition() const;

private:
	static InputHandler* _instance;
	std::vector<Controller*> _controllers;

	std::unordered_map<int, ActionType> _actionTypeMapping;

	Vector2D<int> _mouseScreenPosition;
};