#pragma once
#include <iostream>
#include <unordered_map>
#include <SDL.h>
#include "Event.h"

enum class ActionStatus { NONE, ACTIVE, INACTIVE };
enum class ActionName { RIGHT, LEFT, UP, DOWN, PAUSE, RESUME, QUIT, START, RANKING, MUSIC_SWITCH };
enum class AxisName { HORIZONTAL, VERTICAL };


class Controller {

public:
	Controller();
	Controller(const std::string& name);
	virtual ~Controller() = default;

	virtual void ResetEvents() = 0;
	virtual bool GetButtonUp(const ActionName& actionID) = 0;
	virtual bool GetButtonDown(const ActionName& actionID) const = 0;
	virtual float GetAxis(const AxisName& axisID) const = 0;

	std::string GetName() const;
	void HandleEvents(const Event* eventToHandle);
	void AddActionKey(const ActionName& actionID, const int& eventKeyToAdd);
	void AddAxisActionKeys(const AxisName& axisID, const int& positiveSignedEventKeyToAdd, const int& negativeSignedEventKeyToAdd);

protected:
	virtual void HandleEvent(const Event* eventToHandle) = 0;
	virtual void HandleAxisEvent(const Event* eventToHandle) = 0;


	std::string _name;

	std::unordered_map<int, ActionName> _eventKeyToAction;
	std::unordered_map<ActionName, ActionStatus> _actionUpStatus;
	std::unordered_map<ActionName, ActionStatus> _actionDownStatus;

	std::unordered_map<int, AxisName> _eventKeyToAxis;
	std::unordered_map<int, float> _eventKeyToSigned;
	std::unordered_map<AxisName, float> _axisStatus;
};