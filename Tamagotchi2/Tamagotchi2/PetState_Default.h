#pragma once
#include "PetState.h"
class PetState_Default : public PetState
{
	static const std::vector<std::string> CHOICES;
protected:
	virtual void Feed() = 0;
	virtual void Wash();
	virtual void Play() = 0;

	void Interact();
public:
	PetState_Default();
	~PetState_Default();
};

