#pragma once
#include "IState.h"

enum SwitchType { switch_, push, pop, kill, error };

class PDA_State : public IState
{
public:
	PDA_State();
	~PDA_State();

	virtual void Enter();

	virtual SwitchType GetSwitchType() const;
};