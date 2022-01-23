#include "ButtonGameObject.h"

ButtonGameObject::ButtonGameObject(SDL_Renderer* renderer, const char* text, SDL_Color& color, SDL_Color& colorOnHover,
	const Vector2D<int>& position, const char* fontPath, const int& textSize)
	: _color(color), _colorOnHover(colorOnHover), _text(nullptr), _rect()
{
	_text = new Text(renderer, text, color, position, fontPath, textSize);
	_rect = { position.X, position.Y, _text->GetDestinationSize().X, _text->GetDestinationSize().Y };
}

ButtonGameObject::~ButtonGameObject()
{
	delete _text;
	_text = nullptr;
}


void ButtonGameObject::Update(const double& elapsedTime)
{
	//if (CollisionsHelper::IsPointInsideRect(&_rect, &InputHandler::GetInstance()->GetMouseScreenPosition())) {
	//	OnHoverEnter();
	//	// if click
	//	// OnHoverClick();
	//}
	//else {
	//	OnHoverExit();
	//}
}

void ButtonGameObject::Render() const
{
	_text->Draw();
}

void ButtonGameObject::SetCallback(std::function<void()> callback)
{
	_callback = callback;
}



void ButtonGameObject::OnHoverEnter()
{
	_text->SetColor(_color);
}

void ButtonGameObject::OnHoverExit()
{
	_text->SetColor(_colorOnHover);
}

void ButtonGameObject::OnHoverClick()
{
	_callback();
}
