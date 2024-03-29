#pragma once
#include "Controller.h"

class Keyboard : public Controller {

public:
	Keyboard(const std::string name);
	~Keyboard();

	virtual void ResetEvents() override;
	virtual bool GetButtonUp(const ActionName& actionID) override;
	virtual bool GetButtonDown(const ActionName& actionID) const override;
	virtual float GetAxis(const AxisName& axisID) const override;

private:
	virtual void HandleEvent(const Event* eventToHandle) override;
	virtual void HandleAxisEvent(const Event* eventToHandle) override;

};