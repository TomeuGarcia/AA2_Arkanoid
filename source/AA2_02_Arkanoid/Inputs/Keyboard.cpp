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
		_actionUpStatus[it->second] = true;
		_actionDownStatus[it->second] = false;
	}
	else if (eventToHandle->_actionType == ActionType::BUTTON_DOWN) {
		_actionUpStatus[it->second] = false;
		_actionDownStatus[it->second] = true;
	}
}

bool Keyboard::GetButtonUp(const ActionName& actionID)
{
	std::unordered_map<ActionName, bool>::iterator it = _actionUpStatus.find(actionID);
	if (it == _actionUpStatus.end()) {
		throw std::exception("Action Up not registered for a Keyboard.");
	}

	if (it->second) {
		it->second = false;
		return true;	// true is only returned in the frame when the button went UP
	}
	return false;
}

bool Keyboard::GetButtonDown(const ActionName& actionID) const
{
	std::unordered_map<ActionName, bool>::const_iterator it = _actionDownStatus.find(actionID);
	if (it == _actionDownStatus.end()) {
		throw std::exception("Action Down not registered for a Keyboard."); 
	}

	return it->second;
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


