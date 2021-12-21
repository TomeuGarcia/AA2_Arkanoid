#include "Event.h"

Event::Event() : _key(), _actionType() {}

Event::Event(int key, ActionType actionType) : _key(key), _actionType(actionType) {}
