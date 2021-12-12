#include "Player.h"

Player::Player() : _controller(nullptr)
{
}

Player::~Player()
{
	delete _controller;
}

void Player::InitController(const int& moveUp, const int& moveDown)
{
	_controller = new Keyboard("keyboard1");
	_controller->AddActionKey(ActionName::UP, moveUp);
	_controller->AddActionKey(ActionName::DOWN, moveDown);
	_controller->AddAxisActionKeys(AxisName::VERTICAL, moveUp, moveDown);

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