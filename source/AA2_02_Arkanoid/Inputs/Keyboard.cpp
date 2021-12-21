#include "Keyboard.h"

Keyboard::Keyboard(const std::string name) : Controller(name) {}

Keyboard::~Keyboard() {}

void Keyboard::HandleEvent(const Event* eventToHandle)
{
	std::unordered_map<int, ActionName>::const_iterator it = _eventKeyToAction.find(eventToHandle->_key);
	if (it == _eventKeyToAction.end()) {
		return;
	}

	if (eventToHandle->_actionType == ActionType::BUTTON_UP) {
		_actionUpStatus[it->second] = ActionStatus::ACTIVE;
		_actionDownStatus[it->second] = ActionStatus::INACTIVE;
	}
	else if (eventToHandle->_actionType == ActionType::BUTTON_DOWN) {
		_actionUpStatus[it->second] = ActionStatus::INACTIVE;
		_actionDownStatus[it->second] = ActionStatus::ACTIVE;
	}
}

void Keyboard::ResetEvents()
{
	for (std::unordered_map<ActionName, ActionStatus>::iterator it = _actionUpStatus.begin(); it != _actionUpStatus.end(); ++it) {
		it->second = ActionStatus::NONE;
	}
	for (std::unordered_map<ActionName, ActionStatus>::iterator it = _actionDownStatus.begin(); it != _actionDownStatus.end(); ++it) {
		it->second = ActionStatus::NONE;
	}
}

bool Keyboard::GetButtonUp(const ActionName& actionID)
{
	std::unordered_map<ActionName, ActionStatus>::iterator it = _actionUpStatus.find(actionID);
	if (it == _actionUpStatus.end()) {
		throw std::exception("Action Up not registered for a Keyboard.");
	}

	return it->second == ActionStatus::ACTIVE;
}

bool Keyboard::GetButtonDown(const ActionName& actionID) const
{
	std::unordered_map<ActionName, ActionStatus>::const_iterator it = _actionDownStatus.find(actionID);
	if (it == _actionDownStatus.end()) {
		throw std::exception("Action Down not registered for a Keyboard."); 
	}

	return it->second == ActionStatus::ACTIVE;
}


void Keyboard::HandleAxisEvent(const Event* eventToHandle)
{
	std::unordered_map<int, AxisName>::const_iterator it = _eventKeyToAxis.find(eventToHandle->_key);
	if (it == _eventKeyToAxis.end()) {
		return;
	}

	if (eventToHandle->_actionType == ActionType::BUTTON_UP) {
		_axisStatus[it->second] = 0.0f;
	}
	else if (eventToHandle->_actionType == ActionType::BUTTON_DOWN) {
		_axisStatus[it->second] = _eventKeyToSigned[eventToHandle->_key];
	}
}

float Keyboard::GetAxis(const AxisName& axisID) const
{
	std::unordered_map<AxisName, float>::const_iterator it = _axisStatus.find(axisID);
	if (it == _axisStatus.end()) {
		return 0.0f;
	}

	return it->second;
}


