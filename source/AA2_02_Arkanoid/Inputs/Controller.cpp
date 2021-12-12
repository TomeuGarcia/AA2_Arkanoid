#include "Controller.h"

Controller::Controller() : _name("Controller") {}
Controller::Controller(const std::string& name) : _name(name) {}


std::string Controller::GetName() const
{
	return _name;
}

void Controller::AddActionKey(const ActionName& actionID, const int& eventKeyToAdd)
{
	_eventKeyToAction[eventKeyToAdd] = actionID;
	_actionUpStatus[actionID] = false;
	_actionDownStatus[actionID] = false;
}

void Controller::AddAxisActionKeys(const AxisName& axisID, const int& positiveSignedEventKeyToAdd, const int& negativeSignedEventKeyToAdd)
{
	_eventKeyToAxis[positiveSignedEventKeyToAdd] = axisID;
	_eventKeyToAxis[negativeSignedEventKeyToAdd] = axisID;

	_eventKeyToSigned[positiveSignedEventKeyToAdd] = 1.0f;
	_eventKeyToSigned[negativeSignedEventKeyToAdd] = -1.0f;

	_axisStatus[axisID] = 0.0f;
}

