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

void InputHandler::HandleEvents(const SDL_Event* eventToHandle)
{
	Event* newEventToHandle = new Event(eventToHandle->key.keysym.sym, _actionTypeMapping[eventToHandle->key.type]);

	for (Controller* controller : _controllers) {
		controller->HandleEvent(newEventToHandle);
		controller->HandleAxisEvent(newEventToHandle);
	}

	delete newEventToHandle;
}

void InputHandler::AddController(Controller* controllerToAdd)
{
	_controllers.push_back(controllerToAdd);
}

void InputHandler::RemoveAllControllers()
{
	_controllers.clear();
}
