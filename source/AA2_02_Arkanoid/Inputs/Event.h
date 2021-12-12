#pragma once

enum class ActionType {BUTTON_UP, BUTTON_DOWN};

struct Event {
	int _key;
	ActionType _actionType;

	Event(int key, ActionType actionType);
};