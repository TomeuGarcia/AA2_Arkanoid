#pragma once
#include "SDL.h"
#include "Tags.h"
#include "../Physics/Vector2D.h"

class GameObject {

public:
	GameObject() 
		: _active(true), _tag(Tag::NONE), _position(), _size()
	{}
	GameObject(const Tag& tag) 
		: _active(true), _tag(tag), _position(), _size()
	{}
	GameObject(const Tag& tag, const Vector2D<float>& position, const Vector2D<int>& size)
		: _active(true), _tag(tag), _position(position), _size(size)
	{}
	virtual ~GameObject() = default;

	virtual void Update(const double& elapsedTime) = 0;
	virtual void Render() const = 0;

	void SetActive(const bool& active) { _active = active; }
	bool IsActive() const { return _active; }
	Tag GetTag() const { return _tag; }
	Vector2D<float> GetCentrePosition() const { return Vector2D<float>(_position.X + _size.X/2, _position.Y + _size.Y/2); }

protected:
	bool _active;
	Tag _tag;
	Vector2D<float> _position;
	Vector2D<int> _size;
};