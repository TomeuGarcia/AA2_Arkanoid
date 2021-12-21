#include "Collider.h"

Collider::Collider(GameObject* thisGameObject, ColliderType type) 
    : _thisGameObject(thisGameObject), _type(type), _boundary(), _willBeColliding(false), _collisionData()
{}

void Collider::OnCollisionEnter()
{
    return;
}

void Collider::OnCollisionStay()
{
    return;
}

void Collider::OnCollisionExit()
{
    return;
}

GameObject* Collider::GetThisGameObject()
{
    return _thisGameObject;
}

void Collider::SetCollisionData(CollisionData incomingCollisionData)
{
    _collisionData = incomingCollisionData;
}


