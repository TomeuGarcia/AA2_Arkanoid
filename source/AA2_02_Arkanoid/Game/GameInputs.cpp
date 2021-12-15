#include "GameInputs.h"

GameInputs::GameInputs() : _controllerPlayer1(nullptr), _controllerPlayer2(nullptr)
{
	_controllerPlayer1 = new Keyboard("keyboard1");
	InitPlayerController(_controllerPlayer1, SDLK_w, SDLK_s);
	_controllerPlayer2 = new Keyboard("keyboard2");
	InitPlayerController(_controllerPlayer2, SDLK_UP, SDLK_DOWN);
}

GameInputs::~GameInputs()
{
	delete _controllerPlayer1;
	delete _controllerPlayer2;
}

Controller* GameInputs::GetControllerPlayer1() const
{
	return _controllerPlayer1;
}

Controller* GameInputs::GetControllerPlayer2() const
{
	return _controllerPlayer2;
}

void GameInputs::InitPlayerController(Controller* controller, const int& moveUp, const int& moveDown)
{
	controller->AddActionKey(ActionName::UP, moveUp);
	controller->AddActionKey(ActionName::DOWN, moveDown);
	controller->AddAxisActionKeys(AxisName::VERTICAL, moveUp, moveDown);

	controller->AddActionKey(ActionName::QUIT, SDLK_ESCAPE);
	controller->AddActionKey(ActionName::PAUSE, SDLK_p);
	controller->AddActionKey(ActionName::RESUME, SDLK_l);
	controller->AddActionKey(ActionName::START, SDLK_SPACE);
	controller->AddActionKey(ActionName::RANKING, SDLK_r);

	InputHandler::GetInstance()->AddController(controller);
}
