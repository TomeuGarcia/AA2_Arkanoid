#include "InputHandler.h"

InputHandler* InputHandler::_instance = nullptr;

InputHandler::InputHandler() 
	: _mouseScreenPosition(), _actionTypeMapping()

{
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

		if (event.motion.type == SDL_MOUSEMOTION)
		{
			_mouseScreenPosition.X = event.motion.x;
			_mouseScreenPosition.Y = event.motion.y;
		}
		else {
			eventToHandle = Event(event.key.keysym.sym, _actionTypeMapping[event.key.type]);
			for (Controller* controller : _controllers) {
				controller->HandleEvents(&eventToHandle);
			}
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

Vector2D<int> InputHandler::GetMouseScreenPosition() const
{
	return _mouseScreenPosition;
}
