#pragma once
#include "IState.h"

enum SwitchType { switch_, push, pop, error };

class PDA_State : public IState
{
public:
	PDA_State();
	~PDA_State();

	virtual SwitchType GetSwitchType() const;
};

