#pragma once
#include <vector>
#include "IState.h"
#include <errors.h>
class PushDownAutomata
{
private:
	std::vector<IState> history;
	void ChangeState(IState state);
	void Revert();
	void PushState(IState state);
protected:
	IState currentState;
	void StateSwitch();
public:
	PushDownAutomata();
	~PushDownAutomata();

	bool Update();
};

