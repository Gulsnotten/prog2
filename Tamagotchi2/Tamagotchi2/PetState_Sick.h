#pragma once
#include "PetState_Default.h"
#include "Factory_SickFood.h"

class PetState_Sick : public PetState_Default
{
	Factory_SickFood _foodFactory;
	void PrintWontEatMsg();
	void PrintWashMsg();
	void PrintPlayMsg();
protected:
	void Feed(Action action);
	void Wash();
	void Play();
public:
	PetState_Sick();
	~PetState_Sick();

	bool Update();

	SwitchType GetSwitchType() const;
};

