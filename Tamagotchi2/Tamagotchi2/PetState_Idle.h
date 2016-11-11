#pragma once
#include "PetState_Default.h"
#include "PetState_Sick.h"
#include "PetState_Dead.h"
class PetState_Idle : public PetState_Default
{
protected:
	void Feed();
	void Wash();
	void Play();
public:
	PetState_Idle();
	~PetState_Idle();

	bool Update();
	PetState* NextState() const;
	SwitchType GetSwitchType() const;
};

