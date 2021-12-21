#pragma once
#include "../GameObjects/GameObject.h"
#include "../Physics/BoxCollider2D.h"
#include "../Constants/Constants.h"


class Wall : public GameObject, public BoxCollider2D {

public:
	Wall(const Vector2D<float>& position, const Vector2D<int>& size);
	~Wall();

	virtual void Update(const double& elapsedTime) override;
	virtual void Render() const override;

private:

};