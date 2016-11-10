#pragma once
#include "PDA_State.h"
#include "PetData.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>

class PetState : public PDA_State
{
protected:
	std::unique_ptr<PetState> nextState;
	std::shared_ptr<PetData> _petDataPtr = nullptr;

	int GetChoice(const std::vector<std::string> choices) const;
	int getInputInt(int min, int max) const;

	virtual void Feed();
	virtual void Wash();
	virtual void Play();
public:
	PetState();
	~PetState();

	void Enter(std::shared_ptr<PetData> _ptr);
	SwitchType GetSwitchType() const;

	PetState* NextState() const;
};