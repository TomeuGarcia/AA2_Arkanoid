#pragma once
#include "GameObject.h"
#include "../Renders/Text.h"
#include "../Inputs/InputHandler.h"
#include "../Physics/CollisionsHelper.h"
#include <functional>

class ButtonGameObject : public GameObject
{
public:
	ButtonGameObject(SDL_Renderer* renderer, const char* text, SDL_Color& color, SDL_Color& colorOnHover, 
		const Vector2D<int>& position, const char* fontPath, const int& textSize);
	~ButtonGameObject();

	virtual void Update(const double& elapsedTime);
	virtual void Render() const;

	void SetCallback(std::function<void()> callback);

private:
	void OnHoverEnter();
	void OnHoverExit();
	void OnHoverClick();

	Text* _text;
	SDL_Rect _rect;
	SDL_Color _color;
	SDL_Color _colorOnHover;

	std::function<void()> _callback;
};
