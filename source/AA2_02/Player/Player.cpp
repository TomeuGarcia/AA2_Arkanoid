#include "Player.h"

Player::Player() : _controller(nullptr)
{
	InitController();
}

Player::~Player()
{
	delete _controller;
}

void Player::InitController()
{
	_controller = new Keyboard("keyboard1");
	_controller->AddActionKey(ActionName::RIGHT, SDLK_RIGHT);
	_controller->AddActionKey(ActionName::LEFT, SDLK_LEFT);
	_controller->AddAxisActionKeys(AxisName::HORIZONTAL, SDLK_RIGHT, SDLK_LEFT);
	_controller->AddActionKey(ActionName::UP, SDLK_UP);
	_controller->AddActionKey(ActionName::DOWN, SDLK_DOWN);
	_controller->AddAxisActionKeys(AxisName::VERTICAL, SDLK_UP, SDLK_DOWN);

	_controller->AddActionKey(ActionName::QUIT, SDLK_ESCAPE);
	_controller->AddActionKey(ActionName::PAUSE, SDLK_p);
	_controller->AddActionKey(ActionName::RESUME, SDLK_l);
	_controller->AddActionKey(ActionName::START, SDLK_SPACE);
	_controller->AddActionKey(ActionName::RANKING, SDLK_r);

	InputHandler::GetInstance()->AddController(_controller);
}

Controller* Player::GetController() const
{
	return _controller;
}
