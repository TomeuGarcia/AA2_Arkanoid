#include "Collider.h"

Collider::Collider(GameObject* thisGameObject, ColliderType type) 
    : _thisGameObject(thisGameObject), _type(type), _boundary(), _willBeColliding(false),
    _collisionStatus(CollisionStatus::NONE), _otherCollisionCollider(nullptr)
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

void Collider::Update()
{
    if (_otherCollisionCollider == nullptr)
        return;

    switch (_collisionStatus)
    {
    case CollisionStatus::ENTER:
        OnCollisionEnter();
        break;
    case CollisionStatus::STAY:
        OnCollisionStay();
        break;
    case CollisionStatus::EXIT:
        OnCollisionExit();
        break;
    default:
        break;
    }
}

GameObject* Collider::GetThisGameObject()
{
    return _thisGameObject;
}

void Collider::SetOtherCollisionCollider(Collider* otherCollisionCollider)
{
    _otherCollisionCollider = otherCollisionCollider;
}

void Collider::UpdateCollisionStatus()
{    
    if (_willBeColliding) {
        switch (_collisionStatus)
        {
        case CollisionStatus::NONE:
            _collisionStatus = CollisionStatus::ENTER;
            break;
        case CollisionStatus::ENTER:
            _collisionStatus = CollisionStatus::STAY;
            break;
        case CollisionStatus::STAY:
            break;
        case CollisionStatus::EXIT:
            break;
        default:
            break;
        }
    }
    else {
        switch (_collisionStatus)
        {
        case CollisionStatus::NONE:
            break;
        case CollisionStatus::ENTER:
            _collisionStatus = CollisionStatus::EXIT;
            break;
        case CollisionStatus::STAY:
            _collisionStatus = CollisionStatus::EXIT;
            break;
        case CollisionStatus::EXIT:
            _collisionStatus = CollisionStatus::NONE;
            _otherCollisionCollider = nullptr;
            break;
        default:
            break;
        }
    }
}


