#pragma once
#include "PetState_Default.h"

class PetState_Sick : public PetState_Default
{
protected:
	void Feed();
	void Wash();
	void Play();
public:
	PetState_Sick();
	~PetState_Sick();

	bool Update();

	SwitchType GetSwitchType() const;
};

