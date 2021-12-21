#include "Collider.h"

Collider::Collider(ColliderType type) 
    : _type(type), _boundary(), _willBeColliding(false), _collisionData()
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


