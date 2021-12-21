#include "InputHandler.h"

InputHandler* InputHandler::_instance = nullptr;

InputHandler::InputHandler() {
	_actionTypeMapping[SDL_KEYDOWN] = ActionType::BUTTON_DOWN;
	_actionTypeMapping[SDL_KEYUP] = ActionType::BUTTON_UP;
}

InputHandler* InputHandler::GetInstance()
{
	if (_instance == nullptr) {
		_instance = new InputHandler();
	}
	return _instance;
}

void InputHandler::HandleEvents()
{
	for (Controller* controller : _controllers) {
		controller->ResetEvents();
	}

	SDL_Event event;
	Event eventToHandle;

	while (SDL_PollEvent(&event)) {

		eventToHandle = Event(event.key.keysym.sym, _actionTypeMapping[event.key.type]);
		for (Controller* controller : _controllers) {
			controller->HandleEvents(&eventToHandle);
		}

	}

}

void InputHandler::AddController(Controller* controllerToAdd)
{
	_controllers.push_back(controllerToAdd);
}

void InputHandler::RemoveAllControllers()
{
	_controllers.clear();
}
