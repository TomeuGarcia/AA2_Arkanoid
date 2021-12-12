#pragma once
#include <iostream>
#include <map>
#include <SDL.h>
#include "Event.h"

enum class ActionName { RIGHT, LEFT, UP, DOWN, PAUSE, RESUME, QUIT, START, RANKING };
enum class AxisName { HORIZONTAL, VERTICAL };


class Controller {

public:
	Controller();
	Controller(const std::string& name);
	virtual ~Controller() = default;

	virtual void HandleEvent(const Event* eventToHandle) = 0;
	virtual bool GetButtonUp(const ActionName& actionID) = 0;
	virtual bool GetButtonDown(const ActionName& actionID) const = 0;
	virtual void HandleAxisEvent(const Event* eventToHandle) = 0;
	virtual float GetAxis(const AxisName& axisID) const = 0;

	std::string GetName() const;
	void AddActionKey(const ActionName& actionID, const int& eventKeyToAdd);
	void AddAxisActionKeys(const AxisName& axisID, const int& positiveSignedEventKeyToAdd, const int& negativeSignedEventKeyToAdd);

protected:
	std::string _name;

	std::map<int, ActionName> _eventKeyToAction;
	std::map<ActionName, bool> _actionUpStatus;
	std::map<ActionName, bool> _actionDownStatus;

	std::map<int, AxisName> _eventKeyToAxis;
	std::map<int, float> _eventKeyToSigned;
	std::map<AxisName, float> _axisStatus;
};